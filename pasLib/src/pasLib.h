#ifndef PASLIB_H
#define PASLIB_H
#include "WindowRegistry.h"
#include "GraphicsWindow.h"
#include "GLWindow.h"
namespace pasLib
{
    void TestFunction(void);
    void NewGraphicsWindow(std::string title);
    void GLWindowOpen(void);
    void GLClose(void);
    void Initialize(void);
    void Finalize(void);
}
#endif
