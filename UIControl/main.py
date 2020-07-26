import os
import sys
import tkinter as tk
sys.path.append(os.path.join(os.environ['PAS_BASE'], 'UIControl'))
import AssetHandler
import ControlWindow
import ControlWindow_support
import ControlWindowBindings

root = tk.Tk()
top = ControlWindow.ControlWindow (root)
bindings = ControlWindowBindings.ControlWindowBindings(top, root)
ControlWindow_support.init(root, top)
root.mainloop()
sys.exit()
print("a")
