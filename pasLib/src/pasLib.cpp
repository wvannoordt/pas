#include "pasLib.h"
#include <iostream>
namespace pasLib
{
    WindowRegistry registry;
    void TestFunction(void)
    {
        std::cout << "hello from " << __FILE__ << std::endl;
    }

    void NewGraphicsWindow(std::string title)
    {
        registry.CreateNewGraphicsWindow(title);
    }
}
