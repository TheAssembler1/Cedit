#include "HeaderBar.h"

GtkWidget* Create_Header_Bar(GtkWidget* window){
    GtkWidget* header_bar;
    GtkWidget* window_box;
    GtkWidget* file_item;
    GtkWidget* file_submenu;
    GtkWidget* file_new_submenu_item;
    GtkWidget* file_open_submenu_item;
    GtkWidget* file_save_submenu_item;
    GtkWidget* file_saveas_submenu_item;

    window_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    header_bar = gtk_menu_bar_new();

    gtk_container_add(GTK_CONTAINER(window), window_box);
    gtk_box_pack_start(GTK_BOX(window_box), header_bar, FALSE, FALSE, 0);

    file_item = gtk_menu_item_new_with_label("File");

    gtk_menu_shell_append(GTK_MENU_SHELL(header_bar), file_item);  

    file_submenu = gtk_menu_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_item), file_submenu);

    file_new_submenu_item = gtk_menu_item_new_with_label("New");
    file_open_submenu_item = gtk_menu_item_new_with_label("Open");
    file_save_submenu_item = gtk_menu_item_new_with_label("Save");
    file_saveas_submenu_item = gtk_menu_item_new_with_label("Save As...");

    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_new_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_open_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_save_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_saveas_submenu_item);

    g_signal_connect(file_new_submenu_item, "activate", G_CALLBACK(File_New), NULL);
    g_signal_connect(file_open_submenu_item, "activate", G_CALLBACK(File_Open), NULL);
    g_signal_connect(file_save_submenu_item, "activate", G_CALLBACK(File_Save), NULL);
    g_signal_connect(file_saveas_submenu_item, "activate", G_CALLBACK(File_Saveas), NULL);

    return window_box;
}