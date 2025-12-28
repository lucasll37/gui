#include "Engine.h"
#include "windows.h"
#include <sstream>

using std::stringstream;

Window* Engine::window = nullptr;
Input* Engine::input = nullptr;
App* Engine::app = nullptr;

Engine::Engine() {
    window = new Window();
}

Engine::~Engine() {
    delete window;
    delete input;
}

int Engine::Start(App* application) {
    app = application;
    window->Create();
    input = new Input();
    SetWindowLongPtr(window->Id(), GWLP_WNDPROC, (LONG_PTR)EngineProc);

    return Loop();
}

int Engine::Loop() {
    MSG msg = { 0 };
    app->Init();

    do {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            app->Update();
            app->Draw();
            MsgWaitForMultipleObjects(0, NULL, FALSE, 10, QS_ALLINPUT);
        }

    }
    while (msg.message != WM_QUIT);

    app->Finalize();

    return int(msg.wParam);
}

LRESULT CALLBACK Engine::EngineProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if(msg == WM_PAINT) {
        app->Display();
    }

    return CallWindowProc(Input::InputProc, hwnd, msg, wParam, lParam);
}