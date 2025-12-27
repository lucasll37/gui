#ifndef INPUT_H
#define INPUT_H

#include "Window.h"

class Input {
private:
    static bool keys[256];
    static bool ctrl[256];
    static unsigned int mouseX;
    static unsigned mouseY;
    static short mouseWheel;

    static const unsigned int textLimit = 80;
    static unsigned textIndex;
    static char text[textLimit];

public:
    Input();
    ~Input();

    bool KeyDown(int vkcode);
    bool KeyUp(int vkcode);
    bool KeyPress(int vkcode);

    void Read();
    static char *Text();

    unsigned int MouseX() const;
    unsigned int MouseY() const;
    short MouseWheel();
    
    static LRESULT CALLBACK Reader(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK InputProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

inline bool Input::KeyDown(int vkcode) {
    return keys[vkcode];
}

inline bool Input::KeyUp(int vkcode) {
    return !keys[vkcode];
}

inline char *Input::Text() {
    return text;
}

inline unsigned int Input::MouseX() const {
    return mouseX;
}

inline unsigned int Input::MouseY() const {
    return mouseY;
}

#endif