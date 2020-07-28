#include "pasLib.h"
#include <iostream>
#include "GlobalArgs.h"
#include "GLWindow.h"
namespace pasLib
{
    WindowRegistry registry;
    GLWindow oglContext;
    void TestFunction(void)
    {
        std::cout << "hello from " << __FILE__ << std::endl;
    }
    
    void Initialize(void)
    {
        
    }
    
    void Finalize(void)
    {
        
    }
    
    void GLWindowOpen(void)
    {
        if (!oglContext.GLIsInitialized())
        {
            oglContext.InitializeGL();
            oglContext.GLWindowLoop();
        }
    }
    
    void GLClose(void)
    {
        oglContext.FinalizeGL();
    }

    void NewGraphicsWindow(std::string title)
    {
        registry.CreateNewGraphicsWindow(title);
    }
}
