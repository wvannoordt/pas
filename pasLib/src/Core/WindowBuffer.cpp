#include "WindowBuffer.h"
#include "DebugTools.hx"
#include "DrawingOperations.h"
namespace pasLib
{
    WindowBuffer::WindowBuffer(void)
    {
        width = -1;
        height = -1;
        currentBuffer = NULL;
    }
    
    void WindowBuffer::InitGraphicsBuffer(int wid, int hei)
    {
        width = wid;
        height = hei;
#ifndef __APPLE__
        glewInit();
#endif
        glGenBuffers(1, &pbo);
        glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo);
        glBufferData(GL_PIXEL_UNPACK_BUFFER, 4*wid*hei*sizeof(GLubyte), 0,GL_STREAM_DRAW);
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        cudaGraphicsGLRegisterBuffer(&cuda_pbo_resource, pbo, cudaGraphicsMapFlagsWriteDiscard);
    }
    
    int WindowBuffer::GetWidth(void)
    {
        return width;
    }
    
    int WindowBuffer::GetHeight(void)
    {
        return height;
    }
    
    int* WindowBuffer::GetBuffer(void)
    {
        return currentBuffer;
    }
    
    void WindowBuffer::OnDisplay(void)
    {
        int* oglDeviceBuf = 0;
        cudaGraphicsMapResources(1, &cuda_pbo_resource, 0);
        cudaGraphicsResourceGetMappedPointer((void **)&(oglDeviceBuf), NULL, cuda_pbo_resource);
        currentBuffer = oglDeviceBuf;
        Fill(0xff114455);
        //SHARC_SetRenderState();
        //OverrideOGLFrameBuffer(oglDeviceBuf);

        //This is where a list of shaders would be built
        //SHARC_ComputeShader(SHARC_SHDR_ENVIRON);

        cudaGraphicsUnmapResources(1, &cuda_pbo_resource, 0);
        DrawTexture();
    }
    
    void WindowBuffer::DrawTexture(void)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(0, 0);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(0, height);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(width, height);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(width, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    
    WindowBuffer::~WindowBuffer(void)
    {
        if (pbo)
        {
            cudaGraphicsUnregisterResource(cuda_pbo_resource);
            glDeleteBuffers(1, &pbo);
            glDeleteTextures(1, &tex);
        }
    }
}