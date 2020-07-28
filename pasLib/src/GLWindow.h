#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <string>
#include "CuGLInterop.h"
#include <thread>

namespace pasLib
{
    class GLWindow
    {
        public:
            GLWindow(void);
            ~GLWindow(void);
            void InitializeGL(void);
            void FinalizeGL(void);
            bool GLIsInitialized(void);
            void GLWindowLoop(void);
        private:
            static void OnKeyPress(unsigned char key, int x, int y);
            static void OnMouseMove(int x, int y);
            static void OnMouseDrag(int x, int y);
            static void OnSpecialKeyPress(int key, int x, int y);
            static void OnDisplay(void);
            static void OnClose(void);
            static void TGLLoop(void);
            
            std::string title;
            bool isInitialized;
            std::thread mThread;
    };
}

#endif