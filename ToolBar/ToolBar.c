#include "ToolBar.h"

void Create_Tool_Bar(struct Main_Data* main_data){
    GtkWidget* tool_bar;
    GtkToolItem* file_new;
    GtkToolItem* file_open;
    GtkToolItem* file_save;
    GtkToolItem* file_saveas;
    GtkWidget* file_new_button;
    GtkWidget* file_open_button;
    GtkWidget* file_save_button;
    GtkWidget* file_savas;

    tool_bar = gtk_toolbar_new();

    file_new_button = gtk_image_new_from_icon_name("document-new", 0);
    file_open_button = gtk_image_new_from_icon_name("document-open", 0);
    file_save_button = gtk_image_new_from_icon_name("document-save", 0);
    file_savas = gtk_image_new_from_icon_name("document-save-as", 0);

    file_new = gtk_tool_button_new(file_new_button, NULL);
    file_open = gtk_tool_button_new(file_open_button, NULL);
    file_save = gtk_tool_button_new(file_save_button, NULL);
    file_saveas = gtk_tool_button_new(file_savas, NULL);

    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), file_new, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), file_open, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), file_save, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), file_saveas, -1);

    g_signal_connect(file_new, "clicked", G_CALLBACK(File_New_Toolbar), main_data);
    g_signal_connect(file_open, "clicked", G_CALLBACK(File_Open_Toolbar), main_data);
    g_signal_connect(file_save, "clicked", G_CALLBACK(File_Save_Toolbar), main_data);
    g_signal_connect(file_saveas, "clicked", G_CALLBACK(File_Saveas_Toolbar), main_data);

    gtk_box_pack_start(GTK_BOX(main_data->window_box), tool_bar, FALSE, FALSE, 0);
}