#ifndef WINDOW_H
#define WINDOW_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <string>

using std::string;

enum WindowModes {FULLSCREEN, WINDOWED};

class Window {
private:
    HWND windowId;
    int windowWidth;
    int windowHeight;
    HICON windowIcon;
    HCURSOR windowCursor;
    COLORREF windowColor;
    string windowTitle;
    DWORD windowStyle;
    int windowMode;
    int windowPosX;
    int windowPosY;
    int windowCenterX;
    int windowCenterY;

    static void (*inFocus)();
    static void (*lostFocus)();

    
    public:
    Window();
    
    HWND Id() const;
    int Width() const;
    int Height() const;
    int Mode() const;
    int CenterX() const;
    int CenterY() const;
    string Title() const;
    COLORREF Color() const;
    
    void Icon(const unsigned int icon);
    void Cursor(const  unsigned int cursor);
    void Title(const string title);
    void Size(int width, int height);
    void Mode(int mode);
    void Color(int r, int g, int b);
    
    void HideCursor(bool hide);
    void Print(string text, int x, int y, COLORREF color);
    void Clear();
    void Close();
    bool Create();
    
    void InFocus(void(*func)());
    void LostFocus(void(*func)());

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};


inline HWND Window::Id() const {
    return windowId;
}

inline int Window::Width() const {
    return windowWidth;
}

inline int Window::Height() const {
    return windowHeight;
}

inline int Window::Mode() const {
    return windowMode;
}

inline int Window::CenterX() const {
    return windowCenterX;
}

inline int Window::CenterY() const {
    return windowCenterY;
}

inline string Window::Title() const {
    return windowTitle;
}

inline COLORREF Window::Color() const {
    return windowColor;
}

inline void Window::Icon(const unsigned int icon) {
    windowIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(icon));
}

inline void Window::Cursor(const unsigned int cursor) {
    windowCursor = LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(cursor));
}

inline void Window::Title(const string title) {
    windowTitle = title;
}

inline void Window::Color(int r, int g, int b) {
    windowColor = RGB(r, g, b);
}

inline void Window::HideCursor(bool hide) {
    ShowCursor(!hide);
}

inline void Window::Close() {
    PostMessage(windowId, WM_DESTROY, 0, 0);
}

inline void Window::InFocus(void(*func)()) {
    inFocus = func;
}

inline void Window::LostFocus(void(*func)()) {
    lostFocus = func;
}

#endif