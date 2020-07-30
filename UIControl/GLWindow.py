import time
import tkinter as tk
from OpenGL import GL
from pyopengltk import OpenGLFrame
import pasLib

#For reference:
#https://pypi.org/project/pyopengltk/

class GLWindow(OpenGLFrame):

    def initgl(self):
        GL.glViewport(0, 0, self.width, self.height)
        GL.glClearColor(0.0, 1.0, 0.0, 0.0)   
        self.start = time.time()
        self.nframes = 0
        self.host = None
        pasLib.InitGraphicsBuffer(self.width, self.height)
    
    def SetHost(self, host_in):
        self.host = host_in

    def redraw(self):
        pasLib.OnDisplay()
        #GL.glClear(GL.GL_COLOR_BUFFER_BIT)
        tm = time.time() - self.start
        self.nframes += 1
        print("fps",self.nframes / tm, end="\r" )