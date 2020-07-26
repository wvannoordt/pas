import tkinter as tk
import GraphicsWindow
class WindowList:
    def __init__(self, tkListBox):
        self.listbox = tkListBox
        self.windowArray = {}

    def CreateNewWindow(self, newName):
        self.listbox.insert(tk.END, newName)
        self.windowArray[newName] = GraphicsWindow.GraphicsWindow(newName)
