#pragma once

namespace Inertia {

enum InputEvent {
    InvalidEvent = -1,
    MouseDown,
    MouseUp,
    KeyDown,
    KeyUp,
};

enum InputAction {
    InvalidAction = -1,
    
    MouseButtonLeft,
    MouseButtonRight,
    
    ArrowKeyLeft,
    ArrowKeyRight,
    ArrowKeyDown,
    ArrowKeyUp,
    
    SpecialKeyShift,
    SpecialKeyRightShift,
    SpecialKeyCtrl,
    SpecialKeyRightCtrl,
    SpecialKeyAlt,
    SpecialKeyRightAlt,
    SpecialKeyTab,
    SpecialKeyEnter,
    SpecialKeyBackspace,
    SpecialKeyEscape,
    
    FunctionKey,
    
    StandardKey,
};

struct Input {
    InputEvent event;
    InputAction action;
    int value1; // Key value    or X-coord
    int value2; // Repeat value or Y-coord
    
    Input() : event(InvalidEvent), action(InvalidAction), value1(0), value2(0) {}
};

}
