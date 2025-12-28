#include "App.h"
#include "Engine.h"

Window* App::window = nullptr;
Input* App::input = nullptr;

App::App() {
    if(!window) {
        window = Engine::window;
        input = Engine::input;
    }
}

App::~App() {}