#include "pasLib.h"
#include <iostream>
#include "GlobalArgs.h"
namespace pasLib
{
    WindowRegistry registry;
    void TestFunction(void)
    {
        std::cout << "hello from " << __FILE__ << std::endl;
    }
    
    void InitGraphicsBuffer(int wid, int hei)
    {
        registry.GetBufferObj()->InitGraphicsBuffer(wid, hei);
    }
    
    void GetWindowBufferInfo(int* wid, int* hei, int** buf)
    {
        *wid = registry.GetBufferObj()->GetWidth();
        *hei = registry.GetBufferObj()->GetHeight();
        *buf = registry.GetBufferObj()->GetBuffer();
    }
    
    void OnDisplay(void)
    {
        registry.GetBufferObj()->OnDisplay();
    }

    void NewGraphicsWindow(std::string title)
    {
        registry.CreateNewGraphicsWindow(title);
    }
}
