#include "Window.h"

void (*Window::inFocus)() = nullptr;
void (*Window::lostFocus)() = nullptr;

Window::Window() {
    windowId = 0;
    windowWidth = GetSystemMetrics(SM_CXSCREEN);
    windowHeight = GetSystemMetrics(SM_CYSCREEN);
    windowIcon = LoadIcon(NULL, IDI_APPLICATION);
    windowCursor = LoadCursor(NULL, IDC_ARROW);
    windowColor = RGB(0, 0, 0);
    windowTitle = string("Windows App");
    windowStyle = WS_POPUP | WS_VISIBLE;
    windowMode = FULLSCREEN;
    windowPosX = 0;
    windowPosY = 0;
    windowCenterX = windowWidth/2;
    windowCenterY = windowHeight/2;
}


void Window::Mode(int mode) {
    if(mode == WINDOWED) {
        windowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE;
    }
    else {
        windowStyle = WS_EX_TOPMOST | WS_POPUP | WS_VISIBLE;
    }
}

void Window::Size(int width, int height) {
    windowWidth = width;
    windowHeight = height;

    windowCenterX = windowWidth / 2;
    windowCenterY = windowHeight / 2;

    windowPosX = (GetSystemMetrics(SM_CXSCREEN) / 2) - (windowWidth / 2);
    windowPosY = (GetSystemMetrics(SM_CYSCREEN) / 2) - (windowHeight / 2);
}

void Window::Print(string text, int x, int y, COLORREF color) {
    HDC xdc = GetDC(windowId);
    SetTextColor(xdc, color);
    SetBkMode(xdc, TRANSPARENT);
    TextOut(xdc, x, y, text.c_str(), (int)text.size());
    ReleaseDC(windowId, xdc);
}

void Window::Clear() {
    HDC xdc = GetDC(windowId);
    RECT rect;
    GetClientRect(windowId, &rect);
    FillRect(xdc, &rect, CreateSolidBrush(Color()));
    ReleaseDC(windowId, xdc);
}

bool Window::Create() {
    HINSTANCE appId = GetModuleHandle(NULL);
    WNDCLASSEX wndClass;

    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = Window::WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = appId;
    wndClass.hIcon = windowIcon;
    wndClass.hCursor = windowCursor;
    wndClass.hbrBackground = (HBRUSH) CreateSolidBrush(windowColor);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = "AppWindow";
    wndClass.hIconSm = windowIcon;

    if(!RegisterClassEx(&wndClass)) {
        // MessageBox(NULL, "Erro na criação da janela!", "Aplicação", MB_ICONERROR);
        return false;
    }
    
    windowId = CreateWindowEx(
        0,
        "AppWindow",
        windowTitle.c_str(),
        windowStyle,
        windowPosX,
        windowPosY,
        windowWidth,
        windowHeight,
        NULL,
        NULL,
        appId,
        NULL
    );

    if(windowMode == WINDOWED) {
        RECT winRect = {0, 0, windowWidth, windowHeight};

        AdjustWindowRectEx(
            &winRect,
            GetWindowStyle(windowId),
            GetMenu(windowId) != NULL,
            GetWindowExStyle(windowId)
        );

        windowPosX = (GetSystemMetrics(SM_CXSCREEN) / 2) - ((winRect.right - winRect.left) / 2);
        windowPosY = (GetSystemMetrics(SM_CYSCREEN) / 2) - ((winRect.bottom - winRect.top) / 2);

        MoveWindow(
            windowId,
            windowPosX,
            windowPosY,
            winRect.right - winRect.left,
            winRect.bottom - winRect.top,
            TRUE
        );

    }

    return (windowId ? true : false);
}

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
    switch (message) {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0; // break

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0; // break

    case WM_SETFOCUS:
        if(inFocus) {
            inFocus();
        }
        return 0; // break

    case WM_KILLFOCUS:
        if(lostFocus) {
            lostFocus();
        }
        return 0; // break

    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
}
}