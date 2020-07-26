#ifndef WINDOWREG_H
#define WINDOWREG_H

#include <string>
#include <map>
#include "GraphicsWindow.h"

namespace pasLib
{
    class WindowRegistry
    {
        public:
            WindowRegistry(void);
            ~WindowRegistry(void);
            void CreateNewGraphicsWindow(std::string title);
        private:
            std::map<std::string,GraphicsWindow*> windows;
    };
}

#endif
