#include "MacInputHandler.h"

#import <Carbon/Carbon.h>


namespace Inertia {

void MacInputHandler::deregisterEvents()
{

}

void MacInputHandler::registerEvents()
{
    NSEventMask mask =  NSKeyDownMask|NSKeyUpMask|NSFlagsChangedMask|
                        NSLeftMouseDownMask|NSRightMouseDownMask|
                        NSLeftMouseUpMask|NSRightMouseUpMask;
    
    [NSEvent addLocalMonitorForEventsMatchingMask:mask handler:^(NSEvent *theEvent)
     {
        handleEvent(theEvent);
        return theEvent;
     }];
}

void MacInputHandler::queueInput(Input i)
{
    m_mutex.lock();
    m_inputQueue.push(i);
    m_mutex.unlock();
}

Input MacInputHandler::dequeueInput()
{
    Input i;
    m_mutex.lock();
    if (! m_inputQueue.empty())
    {
        i = m_inputQueue.front();
        m_inputQueue.pop();
    }
    m_mutex.unlock();
    return i;
}

InputAction MacInputHandler::getKeyType(unsigned short id)
{
    InputAction i = InvalidAction;
    
    if (id == kVK_Shift)        i = SpecialKeyShift;
    else if (id == kVK_RightShift)        i = SpecialKeyRightShift;
    else if (id == kVK_Control) i = SpecialKeyCtrl;
    else if (id == kVK_RightControl) i = SpecialKeyRightCtrl;
    else if (id == kVK_Option)  i = SpecialKeyAlt;
    else if (id == kVK_RightOption)  i = SpecialKeyRightAlt;
    else if (id == kVK_Tab)     i = SpecialKeyTab;
    else if (id == kVK_Return)  i = SpecialKeyEnter;
    else if (id == kVK_Delete)  i = SpecialKeyBackspace;
    else if (id == kVK_Escape)  i = SpecialKeyEscape;
    
    else if (id == kVK_DownArrow)   i = ArrowKeyDown;
    else if (id == kVK_UpArrow)     i = ArrowKeyUp;
    else if (id == kVK_LeftArrow)   i = ArrowKeyLeft;
    else if (id == kVK_RightArrow)  i = ArrowKeyRight;
    
    // Handle Function Keys
    
    // Verify Standard Key
    else i = StandardKey;
    
    return i;
}

InputEvent getModifierEvent(InputAction action, NSUInteger flags)
{
    //NOTE: This does not properly detect the release of modifier keys if both the Left and Right
    // were pressed before the release.
    InputEvent event = InvalidEvent;
    
    bool shift = flags & NSShiftKeyMask;
    bool alt = flags & NSAlternateKeyMask;
    bool ctrl = flags & NSControlKeyMask;
    
    if (action == SpecialKeyShift || action == SpecialKeyRightShift)
    {
        if (shift)
            event = KeyDown;
        else
            event = KeyUp;
    }
    else if (action == SpecialKeyAlt || action == SpecialKeyRightAlt)
    {
        if (alt)
            event = KeyDown;
        else
            event = KeyUp;
    }
    else if (action == SpecialKeyCtrl || action == SpecialKeyRightCtrl)
    {
        if (ctrl)
            event = KeyDown;
        else
            event = KeyUp;
    }
    
    return event;
}

void MacInputHandler::handleEvent(NSEvent *nativeEvent)
{
    Input i;
    
    // Translate native events into platform independent events
    switch ([nativeEvent type])
    {
        case NSKeyDown:
            i.event = KeyDown;
            i.action = getKeyType([nativeEvent keyCode]);
            i.value1 = [[[nativeEvent charactersIgnoringModifiers] lowercaseString] characterAtIndex:0];
            i.value2 = [nativeEvent isARepeat];
            break;
            
        case NSKeyUp:
            i.event = KeyUp;
            i.action = getKeyType([nativeEvent keyCode]);
            i.value1 = [[[nativeEvent charactersIgnoringModifiers] lowercaseString] characterAtIndex:0];
            i.value2 = [nativeEvent isARepeat];
            break;
            
        case NSFlagsChanged:
            i.action = getKeyType([nativeEvent keyCode]);
            i.event = getModifierEvent(i.action, [nativeEvent modifierFlags]);
            break;
            
        case NSLeftMouseDown:
            i.action = MouseButtonLeft;
            i.event = MouseDown;
            i.value1 =[nativeEvent locationInWindow].x;
            i.value2 =[nativeEvent locationInWindow].y;
            break;
            
        case NSRightMouseDown:
            i.action = MouseButtonRight;
            i.event = MouseDown;
            i.value1 =[nativeEvent locationInWindow].x;
            i.value2 =[nativeEvent locationInWindow].y;
            break;
            
        case NSLeftMouseUp:
            i.action = MouseButtonLeft;
            i.event = MouseUp;
            i.value1 =[nativeEvent locationInWindow].x;
            i.value2 =[nativeEvent locationInWindow].y;
            break;
            
        case NSRightMouseUp:
            i.action = MouseButtonRight;
            i.event = MouseUp;
            i.value1 =[nativeEvent locationInWindow].x;
            i.value2 =[nativeEvent locationInWindow].y;
            break;
    }
    
    if (i.event != InvalidEvent && i.action != InvalidAction)
        queueInput(i);
}

Input MacInputHandler::getInput()
{
    return dequeueInput();
}

}