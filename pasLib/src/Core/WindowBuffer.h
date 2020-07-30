#ifndef WINDOW_BUFFER_H
#define WINDOW_BUFFER_H
#include "CuGLInterop.h"
#include <iostream>
namespace pasLib
{
    class WindowBuffer
    {
        public:
            WindowBuffer(void);
            ~WindowBuffer(void);
            void InitGraphicsBuffer(int wid, int hei);
            void OnDisplay(void);
            void DrawTexture(void);
            int  GetWidth(void);
            int  GetHeight(void);
            int* GetBuffer(void);
        private:
            GLuint pbo = 0;     // OpenGL pixel buffer object
            GLuint tex = 0;     // OpenGL texture object
            struct cudaGraphicsResource *cuda_pbo_resource;
            int width, height;
            int* currentBuffer;
    };
}

#endif