import pasLib
class GraphicsWindow:
    def __init__(self, windowName):
        self.name = windowName
        pasLib.CreateNewGraphicsWindow(windowName)
