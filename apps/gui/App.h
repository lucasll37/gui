#ifndef APP_H
#define APP_H

#include "Window.h"
#include "Input.h"

class App {

protected:
    static Window* window;
    static Input* input;

public:
    App();
    virtual ~App();

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void  Finalize() = 0;

    virtual void Draw() {}
    virtual void Display() {}
};

#endif