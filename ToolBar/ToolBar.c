#include "ToolBar.h"

void Create_Tool_Bar(GtkWidget* window_box){
    GtkWidget* tool_bar;
    GtkToolItem* make_exec;
    GtkToolItem* run_exec;
    GtkIconSize icon_size;
    GtkWidget* make_exec_button;
    GtkWidget* run_exec_button;

    icon_size = 400;

    tool_bar = gtk_toolbar_new();

    make_exec_button = gtk_image_new_from_icon_name("system-run", icon_size);
    run_exec_button = gtk_image_new_from_icon_name("media-playback-start", icon_size);

    run_exec = gtk_tool_button_new(run_exec_button, "HELLO");
    make_exec = gtk_tool_button_new(make_exec_button, "HELLO");

    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), make_exec, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), run_exec, -1);

    gtk_box_pack_start(GTK_BOX(window_box), tool_bar, FALSE, FALSE, 0);
}