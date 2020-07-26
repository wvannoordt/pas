import os
import AssetHandler
import WindowList
import AddWindow
import AddWindowBindings
import tkinter as tk

class ControlWindowBindings:
    def __init__(self, window_in, root_in):
        self.window = window_in
        self.root = root_in
        self.assets = AssetHandler.ImageHandler(os.path.join(os.environ['PAS_BASE'], 'UIControl/assets'))
        self.windows = WindowList.WindowList(self.window.windowList)
        self.ConfigureTkWidgets()

    def ConfigureTkWidgets(self):
        self.assets.SetBaseImage(self.window.addWindow, 'add')
        self.window.addWindow.configure(command=self.OnAddWindow)

    def OnAddWindow(self):
        newRoot = tk.Toplevel(self.root)
        newWindow = AddWindow.AddWindow(newRoot)
        newWindowBindings = AddWindowBindings.AddWindowBindings(newWindow, newRoot, self)

    def OnRecieveNewWindow(self, newName):
        self.windows.CreateNewWindow(newName)
