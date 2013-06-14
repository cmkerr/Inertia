#pragma once

namespace Inertia {

    enum InputEvent {
        InputEvent_Invalid= -1,
        
        InputEvent_Mouse_LeftButton,
        InputEvent_Mouse_RightButton,
        
        InputEvent_Key_A,
        InputEvent_Key_B,
        InputEvent_Key_C,
        InputEvent_Key_D,
        InputEvent_Key_E,
        InputEvent_Key_F,
        InputEvent_Key_G,
        InputEvent_Key_H,
        InputEvent_Key_I,
        InputEvent_Key_J,
        InputEvent_Key_K,
        InputEvent_Key_L,
        InputEvent_Key_M,
        InputEvent_Key_N,
        InputEvent_Key_O,
        InputEvent_Key_P,
        InputEvent_Key_Q,
        InputEvent_Key_R,
        InputEvent_Key_S,
        InputEvent_Key_T,
        InputEvent_Key_U,
        InputEvent_Key_V,
        InputEvent_Key_W,
        InputEvent_Key_X,
        InputEvent_Key_Y,
        InputEvent_Key_Z,
        
        InputEvent_Key_1,
        InputEvent_Key_2,
        InputEvent_Key_3,
        InputEvent_Key_4,
        InputEvent_Key_5,
        InputEvent_Key_6,
        InputEvent_Key_7,
        InputEvent_Key_8,
        InputEvent_Key_9,
        InputEvent_Key_0,
        
        InputEvent_Key_Minus,
        InputEvent_Key_Equal,
        
        InputEvent_Key_LeftBracket,
        InputEvent_Key_RightBracket,
        
        InputEvent_Key_Quote,
        InputEvent_Key_Semicolon,
        InputEvent_Key_Backslash,
        InputEvent_Key_Comma,
        InputEvent_Key_Slash,
        InputEvent_Key_Period,
        InputEvent_Key_Grave,
        
        InputEvent_Key_KeypadDecimal,
        InputEvent_Key_KeypadMultiply,
        InputEvent_Key_KeypadPlus,
        InputEvent_Key_KeypadClear,
        InputEvent_Key_KeypadDivide,
        InputEvent_Key_KeypadEnter,
        InputEvent_Key_KeypadMinus,
        InputEvent_Key_KeypadEquals,
        InputEvent_Key_Keypad0,
        InputEvent_Key_Keypad1,
        InputEvent_Key_Keypad2,
        InputEvent_Key_Keypad3,
        InputEvent_Key_Keypad4,
        InputEvent_Key_Keypad5,
        InputEvent_Key_Keypad6,
        InputEvent_Key_Keypad7,
        InputEvent_Key_Keypad8,
        InputEvent_Key_Keypad9,
        
        InputEvent_Key_Return,
        InputEvent_Key_Tab,
        InputEvent_Key_Space,
        InputEvent_Key_Delete,
        InputEvent_Key_Escape,
        InputEvent_Key_Command,
        InputEvent_Key_Shift,
        InputEvent_Key_CapsLock,
        InputEvent_Key_Alt, // Option key on Mac
        InputEvent_Key_Control,
        InputEvent_Key_RightShift,
        InputEvent_Key_RightAlt, // Option key on Mac
        InputEvent_Key_RightControl,
        
        InputEvent_Key_Home,
        InputEvent_Key_End,
        InputEvent_Key_Help,
        InputEvent_Key_ForwardDelete,
        
        InputEvent_Key_PageUp,
        InputEvent_Key_PageDown,
        InputEvent_Key_LeftArrow,
        InputEvent_Key_RightArrow,
        InputEvent_Key_DownArrow,
        InputEvent_Key_UpArrow,
        
        InputEvent_Key_Function,
        InputEvent_Key_VolumeUp,
        InputEvent_Key_VolumeDown,
        InputEvent_Key_Mute,
        
        InputEvent_Key_F1,
        InputEvent_Key_F2,
        InputEvent_Key_F3,
        InputEvent_Key_F4,
        InputEvent_Key_F5,
        InputEvent_Key_F6,
        InputEvent_Key_F7,
        InputEvent_Key_F8,
        InputEvent_Key_F9,
        InputEvent_Key_F10,
        InputEvent_Key_F11,
        InputEvent_Key_F12,
        InputEvent_Key_F13,
        InputEvent_Key_F14,
        InputEvent_Key_F15,
        InputEvent_Key_F16,
        InputEvent_Key_F17,
        InputEvent_Key_F18,
        InputEvent_Key_F19,
        InputEvent_Key_F20,
        
    };
    
    enum InputAction {
        InputAction_Invalid = -1,
        InputAction_KeyDown,
        InputAction_KeyUp,
        InputAction_KeyRepeat,
        InputAction_MouseDown,
        InputAction_MouseUp,
    };
    
    struct Input {
        InputEvent event;
        InputAction action;
        
        Input() : event(InputEvent_Invalid), action(InputAction_Invalid) {}
        friend bool operator == (const Input&, const Input&);
        friend bool operator < (const Input&, const Input&);
    };

    
}
