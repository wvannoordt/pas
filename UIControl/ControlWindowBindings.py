import os
import sys
import AssetHandler
import WindowList
import AddWindow
import AddWindowBindings
import tkinter as tk
import GLWindow

class ControlWindowBindings:
    def __init__(self, window_in, root_in):
        self.window = window_in
        self.root = root_in
        self.assets = AssetHandler.ImageHandler(os.path.join(os.environ['PAS_BASE'], 'UIControl/assets'))
        self.windows = WindowList.WindowList(self.window.windowList)
        self.glWindowWid = 1011
        self.glWindowHei = 681
        self.glWindowX = 240
        self.glWindowY = 10
        self.ConfigureTkWidgets()

    def ConfigureTkWidgets(self):
        self.assets.SetBaseImage(self.window.addWindow, 'add')
        self.window.addWindow.configure(command=self.OnAddWindow)
        canx = self.window.prototypeCanvas.winfo_rootx()
        cany = self.window.prototypeCanvas.winfo_rooty()
        self.window.prototypeCanvas.place(x=canx, y=cany)
        self.scene = GLWindow.GLWindow(self.root, width=self.glWindowWid, height=self.glWindowHei)
        self.scene.place(x=self.glWindowX, y=self.glWindowY)
        self.scene.animate = 1
        self.scene.SetHost(self)
        

    def OnAddWindow(self):
        newRoot = tk.Toplevel(self.root)
        newWindow = AddWindow.AddWindow(newRoot)
        newWindowBindings = AddWindowBindings.AddWindowBindings(newWindow, newRoot, self)

    def OnRecieveNewWindow(self, newName):
        self.windows.CreateNewWindow(newName)
