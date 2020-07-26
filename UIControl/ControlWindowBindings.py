import os
import AssetHandler
from PIL import ImageTk, Image
class ControlWindowBindings:
    def __init__(self, window_in, root_in):
        self.window = window_in
        self.root = root_in
        self.assets = AssetHandler.ImageHandler(os.path.join(os.environ['PAS_BASE'], 'UIControl/assets'))
        self.ConfigureTkWidgets()

    def ConfigureTkWidgets(self):
        self.assets.SetBaseImage(self.window.addWindow, 'add')
        self.window.addWindow.configure(command=self.OnAddWindow)

    def OnAddWindow(self):
        print("A")
