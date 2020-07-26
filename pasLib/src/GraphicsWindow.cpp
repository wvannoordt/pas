#include "GraphicsWindow.h"
namespace pasLib
{
    GraphicsWindow::GraphicsWindow(std::string title_in)
    {
        title = title_in;
        cleanedUp = false;
    }

    GraphicsWindow::~GraphicsWindow(void)
    {

    }

    void GraphicsWindow::Destroy(void)
    {
        if (~cleanedUp)
        {
            cleanedUp = true;
        }
    }
}
