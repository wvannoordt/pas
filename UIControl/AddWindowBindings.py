class AddWindowBindings:
    def __init__(self, window_in, root_in, hostBindings_in):
        self.window = window_in
        self.root = root_in
        self.hostBindings = hostBindings_in
        self.ConfigureTkWidgets()

    def ConfigureTkWidgets(self):
        self.hostBindings.assets.SetBaseImage(self.window.acceptNewWindow, 'check')
        self.window.acceptNewWindow.configure(command=self.OnAcceptNewWindow)
        self.window.titleEntry.insert(0, "newWindow")

    def OnAcceptNewWindow(self):
        newName = self.window.titleEntry.get()
        if newName:
            self.hostBindings.OnRecieveNewWindow(newName)
        self.root.destroy()
