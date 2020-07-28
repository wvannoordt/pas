#include "GLWindow.h"
#include "GlobalArgs.h"
#include <iostream>
#include <thread>
#include "pasLib.h"
namespace pasLib
{
    GLWindow::GLWindow(void)
    {
        title = "pas";
        isInitialized = false;
    }
    
    void GLWindow::InitializeGL(void)
    {
        isInitialized = true;
        glutInit(&globArgc, globArgv);
        int width = 800;
        int height = 800;
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
        glutInitWindowSize(width, height);
        glutCreateWindow(title.c_str());
#ifndef __APPLE__
        glewInit();
#endif
        gluOrtho2D(0, width, height, 0);
        glutKeyboardFunc(OnKeyPress);
        glutSpecialFunc(OnSpecialKeyPress);
        glutPassiveMotionFunc(OnMouseMove);
        glutMotionFunc(OnMouseDrag);
        glutDisplayFunc(OnDisplay);
        //SharcInitPixBuffer();
    }
    
    bool GLWindow::GLIsInitialized(void)
    {
        return isInitialized;
    }
    
    void GLWindow::FinalizeGL(void)
    {
        mThread.join();
    }
    
    void GLWindow::GLWindowLoop(void)
    {
        mThread = std::thread(TGLLoop);
    }
    
    void GLWindow::TGLLoop(void)
    {
        atexit(OnClose);
        glutMainLoop();
    }
    
    void GLWindow::OnKeyPress(unsigned char key, int x, int y)
    {
        char u[1];
        u[0] = key;
        std::cout << u << std::endl;
        glutPostRedisplay();
    }
    
    void GLWindow::OnMouseMove(int x, int y)
    {
        glutPostRedisplay();
    }
    
    void GLWindow::OnMouseDrag(int x, int y)
    {
        glutPostRedisplay();
    }
    
    void GLWindow::OnSpecialKeyPress(int key, int x, int y)
    {
        glutPostRedisplay();
    }
    
    void GLWindow::OnClose(void)
    {
        glutPostRedisplay();
    }
    
    void GLWindow::OnDisplay(void)
    {
        glutPostRedisplay();
    }
    
    GLWindow::~GLWindow(void)
    {
        
    }
}