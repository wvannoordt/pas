#ifndef WINDOWREG_H
#define WINDOWREG_H

#include <string>
#include <map>
#include "GraphicsWindow.h"
#include "WindowBuffer.h"

namespace pasLib
{
    class WindowRegistry
    {
        public:
            WindowRegistry(void);
            ~WindowRegistry(void);
            void CreateNewGraphicsWindow(std::string title);
            WindowBuffer* GetBufferObj(void);
        private:
            std::map<std::string,GraphicsWindow*> windows;
            WindowBuffer bufferObj;
    };
}

#endif
