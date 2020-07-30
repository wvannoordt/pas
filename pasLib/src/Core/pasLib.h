#ifndef PASLIB_H
#define PASLIB_H
#include "WindowRegistry.h"
#include "GraphicsWindow.h"
namespace pasLib
{
    void TestFunction(void);
    void NewGraphicsWindow(std::string title);
    void InitGraphicsBuffer(int wid, int hei);
    void OnDisplay(void);
    void GetWindowBufferInfo(int* wid, int* hei, int** buf);
    void Initialize(void);
    void Finalize(void);
}
#endif
