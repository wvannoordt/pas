import os
import sys
import tkinter as tk
class ImageHandler:
    def __init__(self, assetPath_in):
        self.assetPath = assetPath_in
        self.contents = {}
        self.AddAsset('add')
        self.AddAsset('check')

    def AddAsset(self, key):
        self.contents[key] = tk.PhotoImage(file=self.GetAsset(key))

    def GetAsset(self, key):
        filename = os.path.join(self.assetPath, "{}.png".format(key))
        if not os.path.isfile(filename):
            print("Could not find requested asset {}.".format(filename))
            sys.exit(133)
        else:
            return filename

    def SetBaseImage(self, tkObj, key):
        tkObj.configure(image=self.contents[key])
