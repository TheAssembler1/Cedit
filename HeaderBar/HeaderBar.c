#include "HeaderBar.h"

static void Create_File_Menu(GtkWidget* header_bar, GtkSourceBuffer* text_buffer);
static void Create_Edit_Menu(GtkWidget* header_bar);

GtkWidget* Create_Header_Bar(GtkWidget* window, GtkSourceBuffer text_buffer){
    GtkWidget* header_bar;
    GtkWidget* window_box;

    window_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    header_bar = gtk_menu_bar_new();

    gtk_container_add(GTK_CONTAINER(window), window_box);
    gtk_box_pack_start(GTK_BOX(window_box), header_bar, FALSE, FALSE, 0);

    Create_File_Menu(header_bar, &text_buffer);
    Create_Edit_Menu(header_bar);

    return window_box;
}

static void Create_File_Menu(GtkWidget* header_bar, GtkSourceBuffer* text_buffer){
    GtkWidget* file_item;
    GtkWidget* file_submenu;
    GtkWidget* file_new_submenu_item;
    GtkWidget* file_open_submenu_item;
    GtkWidget* file_save_submenu_item;
    GtkWidget* file_saveas_submenu_item;

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

    g_signal_connect(file_new_submenu_item, "activate", G_CALLBACK(File_New), text_buffer);
    g_signal_connect(file_open_submenu_item, "activate", G_CALLBACK(File_Open), text_buffer);
    g_signal_connect(file_save_submenu_item, "activate", G_CALLBACK(File_Save), text_buffer);
    g_signal_connect(file_saveas_submenu_item, "activate", G_CALLBACK(File_Saveas), text_buffer);
}

static void Create_Edit_Menu(GtkWidget* header_bar){
    GtkWidget* edit_item;
    GtkWidget* edit_submenu;
    GtkWidget* edit_undo_submenu_item;
    GtkWidget* edit_redo_submenu_item;
    GtkWidget* edit_cut_submenu_item;
    GtkWidget* edit_copy_submenu_item;
    GtkWidget* edit_paste_submenu_item;

    edit_item = gtk_menu_item_new_with_label("Edit");

    edit_submenu = gtk_menu_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_item), edit_submenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(header_bar), edit_item);

    edit_undo_submenu_item = gtk_menu_item_new_with_label("Undo");
    edit_redo_submenu_item = gtk_menu_item_new_with_label("Redo");
    edit_cut_submenu_item = gtk_menu_item_new_with_label("Cut");
    edit_copy_submenu_item = gtk_menu_item_new_with_label("Copy");
    edit_paste_submenu_item = gtk_menu_item_new_with_label("Paste");

    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_undo_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_redo_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_cut_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_copy_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_paste_submenu_item);
}