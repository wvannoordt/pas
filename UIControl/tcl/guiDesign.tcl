#############################################################################
# Generated by PAGE version 4.26
#  in conjunction with Tcl version 8.6
#  Jul 25, 2020 08:56:46 PM BST  platform: Linux
set vTcl(timestamp) ""


if {!$vTcl(borrow) && !$vTcl(template)} {

set vTcl(actual_gui_font_tooltip_name)  TkDefaultFont
set vTcl(actual_gui_font_treeview_name)  TkDefaultFont
set vTcl(actual_gui_bg) #d9d9d9
set vTcl(actual_gui_fg) #000000
set vTcl(actual_gui_analog) #ececec
set vTcl(actual_gui_menu_analog) #ececec
set vTcl(actual_gui_menu_bg) #d9d9d9
set vTcl(actual_gui_menu_fg) #000000
set vTcl(complement_color) #d9d9d9
set vTcl(analog_color_p) #d9d9d9
set vTcl(analog_color_m) #ececec
set vTcl(active_fg) #000000
set vTcl(actual_gui_menu_active_bg)  #ececec
set vTcl(active_menu_fg) #000000
}




proc vTclWindow.top42 {base} {
    global vTcl
    if {$base == ""} {
        set base .top42
    }
    if {[winfo exists $base]} {
        wm deiconify $base; return
    }
    set top $base
    ###################
    # CREATING WIDGETS
    ###################
    vTcl::widgets::core::toplevel::createCmd $top -class Toplevel \
        -background #262626 -highlightbackground #545454 
    wm focusmodel $top passive
    wm geometry $top 600x450+898+270
    update
    # set in toplevel.wgt.
    global vTcl
    global img_list
    set vTcl(save,dflt,origin) 0
    wm maxsize $top 2545 1410
    wm minsize $top 1 1
    wm overrideredirect $top 0
    wm resizable $top 1 1
    wm deiconify $top
    wm title $top "Control"
    vTcl:DefineAlias "$top" "ControlWindow" vTcl:Toplevel:WidgetProc "" 1
    button $top.but43 \
        -activebackground #ffffff -background #141414 -borderwidth 0 \
        -font TkDefaultFont -foreground $vTcl(actual_gui_fg) \
        -highlightbackground #141414 -highlightcolor black -relief flat 
    vTcl:DefineAlias "$top.but43" "addWindow" vTcl:WidgetProc "ControlWindow" 1
    listbox $top.lis44 \
        -background #141414 -borderwidth 0 -font TkFixedFont \
        -foreground #b7b7b7 -height 156 -highlightbackground #141414 \
        -width 114 
    .top42.lis44 configure -font "TkFixedFont"
    .top42.lis44 insert end text
    vTcl:DefineAlias "$top.lis44" "windowList" vTcl:WidgetProc "ControlWindow" 1
    ###################
    # SETTING GEOMETRY
    ###################
    place $top.but43 \
        -in $top -x 10 -y 10 -width 32 -relwidth 0 -height 32 -relheight 0 \
        -anchor nw -bordermode ignore 
    place $top.lis44 \
        -in $top -x 10 -y 50 -width 114 -relwidth 0 -height 156 -relheight 0 \
        -anchor nw -bordermode ignore 

    vTcl:FireEvent $base <<Ready>>
}

set btop ""
if {$vTcl(borrow)} {
    set btop .bor[expr int([expr rand() * 100])]
    while {[lsearch $btop $vTcl(tops)] != -1} {
        set btop .bor[expr int([expr rand() * 100])]
    }
}
set vTcl(btop) $btop
Window show .
Window show .top42 $btop
if {$vTcl(borrow)} {
    $btop configure -background plum
}

