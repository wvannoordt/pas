#! /usr/bin/env python
#  -*- coding: utf-8 -*-
#
# GUI module generated by PAGE version 4.26
#  in conjunction with Tcl version 8.6
#    Jul 26, 2020 02:25:24 AM BST  platform: Linux

import sys

try:
    import Tkinter as tk
except ImportError:
    import tkinter as tk

try:
    import ttk
    py3 = False
except ImportError:
    import tkinter.ttk as ttk
    py3 = True

import AddWindow_support

def vp_start_gui():
    '''Starting point when module is the main routine.'''
    global val, w, root
    root = tk.Tk()
    top = AddWindow (root)
    AddWindow_support.init(root, top)
    root.mainloop()

w = None
def create_AddWindow(root, *args, **kwargs):
    '''Starting point when module is imported by another program.'''
    global w, w_win, rt
    rt = root
    w = tk.Toplevel (root)
    top = AddWindow (w)
    AddWindow_support.init(w, top, *args, **kwargs)
    return (w, top)

def destroy_AddWindow():
    global w
    w.destroy()
    w = None

class AddWindow:
    def __init__(self, top=None):
        '''This class configures and populates the toplevel window.
           top is the toplevel containing window.'''
        _bgcolor = '#d9d9d9'  # X11 color: 'gray85'
        _fgcolor = '#000000'  # X11 color: 'black'
        _compcolor = '#d9d9d9' # X11 color: 'gray85'
        _ana1color = '#d9d9d9' # X11 color: 'gray85'
        _ana2color = '#ececec' # Closest X11 color: 'gray92'
        font9 = "-family {DejaVu Sans} -size 13 -weight normal -slant "  \
            "roman -underline 0 -overstrike 0"

        top.geometry("299x49+913+211")
        top.minsize(1, 1)
        top.maxsize(2545, 1410)
        top.resizable(1, 1)
        top.title("Add Window")
        top.configure(background="#262626")

        self.Label1 = tk.Label(top)
        self.Label1.place(relx=0.033, rely=0.204, height=31, width=69)
        self.Label1.configure(activebackground="#262626")
        self.Label1.configure(activeforeground="white")
        self.Label1.configure(background="#262626")
        self.Label1.configure(font=font9)
        self.Label1.configure(foreground="#dddddd")
        self.Label1.configure(justify='left')
        self.Label1.configure(text='''Title:''')

        self.titleEntry = tk.Entry(top)
        self.titleEntry.place(relx=0.268, rely=0.204,height=32, relwidth=0.555)
        self.titleEntry.configure(background="#141414")
        self.titleEntry.configure(font="TkFixedFont")
        self.titleEntry.configure(foreground="#dddddd")
        self.titleEntry.configure(highlightbackground="#141414")
        self.titleEntry.configure(highlightthickness="0")
        self.titleEntry.configure(relief="flat")

        self.acceptNewWindow = tk.Button(top)
        self.acceptNewWindow.place(relx=0.836, rely=0.204, height=32, width=32)
        self.acceptNewWindow.configure(background="#141414")
        self.acceptNewWindow.configure(borderwidth="0")
        self.acceptNewWindow.configure(highlightbackground="#141414")
        self.acceptNewWindow.configure(relief="flat")

if __name__ == '__main__':
    vp_start_gui()





