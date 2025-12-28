#ifndef MY_APP_H
#define MY_APP_H

#include <sstream>
#include "App.h"

using std::stringstream;

class MyApp: public App {

private:
    stringstream textSize;
    stringstream textMode;
    stringstream textMouse;

    int lastX = 0;
    int lastY = 0;

public:
    void Init();
    void Update();
    void Display();
    void Finalize();
};

#endif

