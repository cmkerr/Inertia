#include "MacInputHandler.h"

#import <Carbon/Carbon.h>



namespace Inertia {
    
void MacInputHandler::deregisterEvents()
{
    [NSEvent removeMonitor:m_eventMonitor];
}

void MacInputHandler::registerEvents()
{
    NSEventMask mask =  NSKeyDownMask|NSKeyUpMask|NSFlagsChangedMask|
                        NSLeftMouseDownMask|NSRightMouseDownMask|
                        NSLeftMouseUpMask|NSRightMouseUpMask;
    
    m_eventMonitor = [NSEvent addLocalMonitorForEventsMatchingMask:mask handler:^(NSEvent *theEvent)
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
    
InputEvent MacInputHandler::translateNativeEvent(unsigned short id)
{
    InputEvent event;
    
    switch (id)
    {
        // ANSI Codes
        case kVK_ANSI_A:
            event = InputEvent_Key_A;
            break;
        case kVK_ANSI_S:
            event = InputEvent_Key_S;
            break;
        case kVK_ANSI_D:
            event = InputEvent_Key_D;
            break;
        case kVK_ANSI_F:
            event = InputEvent_Key_F;
            break;
        case kVK_ANSI_H:
            event = InputEvent_Key_H;
            break;
        case kVK_ANSI_G:
            event = InputEvent_Key_G;
            break;
        case kVK_ANSI_Z:
            event = InputEvent_Key_Z;
            break;
        case kVK_ANSI_X:
            event = InputEvent_Key_X;
            break;
        case kVK_ANSI_C:
            event = InputEvent_Key_C;
            break;
        case kVK_ANSI_V:
            event = InputEvent_Key_V;
            break;
        case kVK_ANSI_B:
            event = InputEvent_Key_B;
            break;
        case kVK_ANSI_Q:
            event = InputEvent_Key_Q;
            break;
        case kVK_ANSI_W:
            event = InputEvent_Key_W;
            break;
        case kVK_ANSI_E:
            event = InputEvent_Key_E;
            break;
        case kVK_ANSI_R:
            event = InputEvent_Key_R;
            break;
        case kVK_ANSI_Y:
            event = InputEvent_Key_Y;
            break;
        case kVK_ANSI_T:
            event = InputEvent_Key_T;
            break;
        case kVK_ANSI_1:
            event = InputEvent_Key_1;
            break;
        case kVK_ANSI_2:
            event = InputEvent_Key_2;
            break;
        case kVK_ANSI_3:
            event = InputEvent_Key_3;
            break;
        case kVK_ANSI_4:
            event = InputEvent_Key_4;
            break;
        case kVK_ANSI_6:
            event = InputEvent_Key_6;
            break;
        case kVK_ANSI_5:
            event = InputEvent_Key_5;
            break;
        case kVK_ANSI_Equal:
            event = InputEvent_Key_Equal;
            break;
        case kVK_ANSI_9:
            event = InputEvent_Key_9;
            break;
        case kVK_ANSI_7:
            event = InputEvent_Key_7;
            break;
        case kVK_ANSI_Minus:
            event = InputEvent_Key_Minus;
            break;
        case kVK_ANSI_8:
            event = InputEvent_Key_8;
            break;
        case kVK_ANSI_0:
            event = InputEvent_Key_0;
            break;
        case kVK_ANSI_RightBracket:
            event = InputEvent_Key_RightBracket;
            break;
        case kVK_ANSI_O:
            event = InputEvent_Key_0;
            break;
        case kVK_ANSI_U:
            event = InputEvent_Key_U;
            break;
        case kVK_ANSI_LeftBracket:
            event = InputEvent_Key_LeftBracket;
            break;
        case kVK_ANSI_I:
            event = InputEvent_Key_I;
            break;
        case kVK_ANSI_P:
            event = InputEvent_Key_P;
            break;
        case kVK_ANSI_L:
            event = InputEvent_Key_L;
            break;
        case kVK_ANSI_J:
            event = InputEvent_Key_J;
            break;
        case kVK_ANSI_Quote:
            event = InputEvent_Key_Quote;
            break;
        case kVK_ANSI_K:
            event = InputEvent_Key_K;
            break;
        case kVK_ANSI_Semicolon:
            event = InputEvent_Key_Semicolon;
            break;
        case kVK_ANSI_Backslash:
            event = InputEvent_Key_Backslash;
            break;
        case kVK_ANSI_Comma:
            event = InputEvent_Key_Comma;
            break;
        case kVK_ANSI_Slash:
            event = InputEvent_Key_Slash;
            break;
        case kVK_ANSI_N:
            event = InputEvent_Key_N;
            break;
        case kVK_ANSI_M:
            event = InputEvent_Key_M;
            break;
        case kVK_ANSI_Period:
            event = InputEvent_Key_Period;
            break;
        case kVK_ANSI_Grave:
            event = InputEvent_Key_Grave;
            break;
        case kVK_ANSI_KeypadDecimal:
            event = InputEvent_Key_KeypadDecimal;
            break;
        case kVK_ANSI_KeypadMultiply:
            event = InputEvent_Key_KeypadMultiply;
            break;
        case kVK_ANSI_KeypadPlus:
            event = InputEvent_Key_KeypadPlus;
            break;
        case kVK_ANSI_KeypadClear:
            event = InputEvent_Key_KeypadClear;
            break;
        case kVK_ANSI_KeypadDivide:
            event = InputEvent_Key_KeypadDivide;
            break;
        case kVK_ANSI_KeypadEnter:
            event = InputEvent_Key_KeypadEnter;
            break;
        case kVK_ANSI_KeypadMinus:
            event = InputEvent_Key_KeypadMinus;
            break;
        case kVK_ANSI_KeypadEquals:
            event = InputEvent_Key_KeypadEquals;
            break;
        case kVK_ANSI_Keypad0:
            event = InputEvent_Key_Keypad0;
            break;
        case kVK_ANSI_Keypad1:
            event = InputEvent_Key_Keypad1;
            break;
        case kVK_ANSI_Keypad2:
            event = InputEvent_Key_Keypad2;
            break;
        case kVK_ANSI_Keypad3:
            event = InputEvent_Key_Keypad3;
            break;
        case kVK_ANSI_Keypad4:
            event = InputEvent_Key_Keypad4;
            break;
        case kVK_ANSI_Keypad5:
            event = InputEvent_Key_Keypad5;
            break;
        case kVK_ANSI_Keypad6:
            event = InputEvent_Key_Keypad6;
            break;
        case kVK_ANSI_Keypad7:
            event = InputEvent_Key_Keypad7;
            break;
        case kVK_ANSI_Keypad8:
            event = InputEvent_Key_Keypad8;
            break;
        case kVK_ANSI_Keypad9:
            event = InputEvent_Key_Keypad9;
            break;
            
        // Layout-independent Codes
        case kVK_Return:
            event = InputEvent_Key_Return;
            break;
        case kVK_Tab:
            event = InputEvent_Key_Tab;
            break;
        case kVK_Space:
            event = InputEvent_Key_Space;
            break;
        case kVK_Delete:
            event = InputEvent_Key_Delete;
            break;
        case kVK_Escape:
            event = InputEvent_Key_Escape;
            break;
        case kVK_Command:
            event = InputEvent_Key_Command;
            break;
        case kVK_Shift:
            event = InputEvent_Key_Shift;
            break;
        case kVK_CapsLock:
            event = InputEvent_Key_CapsLock;
            break;
        case kVK_Option:
            event = InputEvent_Key_Alt;
            break;
        case kVK_Control:
            event = InputEvent_Key_Control;
            break;
        case kVK_RightShift:
            event = InputEvent_Key_RightShift;
            break;
        case kVK_RightOption:
            event = InputEvent_Key_RightAlt;
            break;
        case kVK_RightControl:
            event = InputEvent_Key_RightControl;
            break;
        case kVK_Function:
            event = InputEvent_Key_Function;
            break;
        case kVK_F17:
            event = InputEvent_Key_F17;
            break;
        case kVK_VolumeUp:
            event = InputEvent_Key_VolumeUp;
            break;
        case kVK_VolumeDown:
            event = InputEvent_Key_VolumeDown;
            break;
        case kVK_Mute:
            event = InputEvent_Key_Mute;
            break;
        case kVK_F18:
            event = InputEvent_Key_F18;
            break;
        case kVK_F19:
            event = InputEvent_Key_F19;
            break;
        case kVK_F20:
            event = InputEvent_Key_F20;
            break;
        case kVK_F5:
            event = InputEvent_Key_F5;
            break;
        case kVK_F6:
            event = InputEvent_Key_F6;
            break;
        case kVK_F7:
            event = InputEvent_Key_F7;
            break;
        case kVK_F3:
            event = InputEvent_Key_F3;
            break;
        case kVK_F8:
            event = InputEvent_Key_F8;
            break;
        case kVK_F9:
            event = InputEvent_Key_F9;
            break;
        case kVK_F11:
            event = InputEvent_Key_F11;
            break;
        case kVK_F13:
            event = InputEvent_Key_F13;
            break;
        case kVK_F16:
            event = InputEvent_Key_F16;
            break;
        case kVK_F14:
            event = InputEvent_Key_F14;
            break;
        case kVK_F10:
            event = InputEvent_Key_F10;
            break;
        case kVK_F12:
            event = InputEvent_Key_F12;
            break;
        case kVK_F15:
            event = InputEvent_Key_F15;
            break;
        case kVK_Help:
            event = InputEvent_Key_Help;
            break;
        case kVK_Home:
            event = InputEvent_Key_Home;
            break;
        case kVK_PageUp:
            event = InputEvent_Key_PageUp;
            break;
        case kVK_ForwardDelete:
            event = InputEvent_Key_ForwardDelete;
            break;
        case kVK_F4:
            event = InputEvent_Key_F4;
            break;
        case kVK_End:
            event = InputEvent_Key_End;
            break;
        case kVK_F2:
            event = InputEvent_Key_F2;
            break;
        case kVK_PageDown:
            event = InputEvent_Key_PageDown;
            break;
        case kVK_F1:
            event = InputEvent_Key_F1;
            break;
        case kVK_LeftArrow:
            event = InputEvent_Key_LeftArrow;
            break;
        case kVK_RightArrow:
            event = InputEvent_Key_RightArrow;
            break;
        case kVK_DownArrow:
            event = InputEvent_Key_DownArrow;
            break;
        case kVK_UpArrow:
            event = InputEvent_Key_UpArrow;
            break;
        default:
            event = InputEvent_Invalid;
    }
    
    return event;
}
    

void MacInputHandler::handleEvent(NSEvent *nativeEvent)
{
    Input input;
    
    switch ([nativeEvent type])
    {
        case NSKeyDown:
            input.event = translateNativeEvent([nativeEvent keyCode]);
            if ([nativeEvent isARepeat])
                input.action = InputAction_KeyRepeat;
            else
                input.action = InputAction_KeyDown;
            break;
            
        case NSKeyUp:
            input.event = translateNativeEvent([nativeEvent keyCode]);
            input.action = InputAction_KeyUp;
            break;
            
        case NSFlagsChanged:
            input.event = translateNativeEvent([nativeEvent keyCode]);
            if (CGEventSourceKeyState(kCGEventSourceStateCombinedSessionState, [nativeEvent keyCode]))
                input.action = InputAction_KeyDown;
            else
                input.action = InputAction_KeyUp;
            break;
            
        case NSLeftMouseDown:
            input.event = InputEvent_Mouse_LeftButton;
            input.action = InputAction_MouseDown;
            break;
            
        case NSRightMouseDown:
            input.event = InputEvent_Mouse_RightButton;
            input.action = InputAction_MouseDown;
            break;
            
        case NSLeftMouseUp:
            input.event = InputEvent_Mouse_LeftButton;
            input.action = InputAction_MouseUp;
            break;
            
        case NSRightMouseUp:
            input.event = InputEvent_Mouse_RightButton;
            input.action = InputAction_MouseUp;
            break;
    }
    
    if (input.event != InputEvent_Invalid && input.action != InputAction_Invalid)
        queueInput(input);
}

Input MacInputHandler::getInput()
{
    return dequeueInput();
}

}