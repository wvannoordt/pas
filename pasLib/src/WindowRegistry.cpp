#include "WindowRegistry.h"
#include <iostream>
#include "GlobalArgs.h"
namespace pasLib
{
    WindowRegistry::WindowRegistry(void)
    {
        if (!globInitialized)
        {
            globInitialized = true;
            globArgc = 0;
            globArgv = new char* [GLOB_ARG_MAX];
        }
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
            delete[] globArgv;
        }
    }
}
