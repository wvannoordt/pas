#include "WindowRegistry.h"
#include <iostream>
namespace pasLib
{
    WindowRegistry::WindowRegistry(void)
    {

    }

    void WindowRegistry::CreateNewGraphicsWindow(std::string title)
    {
        windows.insert({title, new GraphicsWindow(title)});
    }

    WindowRegistry::~WindowRegistry(void)
    {
        for (std::map<std::string, GraphicsWindow*>::iterator it = windows.begin(); it!=windows.end(); it++)
        {
            it->second->Destroy();
            GraphicsWindow* temp = it->second;
            delete temp;
        }
    }
}
