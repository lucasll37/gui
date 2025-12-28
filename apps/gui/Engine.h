#ifndef ENGINE_H
#define ENGINE_H

#include "App.h"
#include "Window.h"
#include "Input.h"

class Engine {
private:
    static App* app;
    int Loop();

public:
    static Window* window;
    static Input* input;

    Engine();
    ~Engine();

    int Start(App* application);

    static LRESULT CALLBACK EngineProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif