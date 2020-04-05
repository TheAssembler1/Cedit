#include "HeaderBar.h"

static void Create_File_Menu(GtkWidget* header_bar, struct Main_Data* main_data, GtkAccelGroup* accel_group);
static void Create_Edit_Menu(GtkWidget* header_bar, struct Main_Data* main_data);
static void Create_Help_Menu(GtkWidget* header_bar, GtkWidget* window);

GtkWidget* Create_Header_Bar(struct Main_Data* main_data, GtkAccelGroup* accel_group){
    GtkWidget* header_bar;

    main_data->window_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    header_bar = gtk_menu_bar_new();

    gtk_container_add(GTK_CONTAINER(main_data->window), main_data->window_box);
    gtk_box_pack_start(GTK_BOX(main_data->window_box), header_bar, FALSE, FALSE, 0);

    Create_File_Menu(header_bar, main_data, accel_group);
    Create_Edit_Menu(header_bar, main_data);
    Create_Help_Menu(header_bar, main_data->window);
}

static void Create_File_Menu(GtkWidget* header_bar, struct Main_Data* main_data, GtkAccelGroup* accel_group){
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

    file_new_submenu_item = gtk_menu_item_new_with_mnemonic("_New"); 
    file_open_submenu_item = gtk_menu_item_new_with_mnemonic("_Open");
    file_save_submenu_item = gtk_menu_item_new_with_mnemonic("_Save");
    file_saveas_submenu_item = gtk_menu_item_new_with_label("Save As...");

    gtk_widget_add_accelerator(file_new_submenu_item, "activate", accel_group, GDK_KEY_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(file_open_submenu_item, "activate", accel_group, GDK_KEY_o, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(file_save_submenu_item, "activate", accel_group, GDK_KEY_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_new_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_open_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_save_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_submenu), file_saveas_submenu_item);

    g_signal_connect(file_new_submenu_item, "activate", G_CALLBACK(File_New), main_data);
    g_signal_connect(file_open_submenu_item, "activate", G_CALLBACK(File_Open), main_data);
    g_signal_connect(file_save_submenu_item, "activate", G_CALLBACK(File_Save), main_data);
    g_signal_connect(file_saveas_submenu_item, "activate", G_CALLBACK(File_Saveas), main_data);
}

static void Create_Edit_Menu(GtkWidget* header_bar, struct Main_Data* main_data){
    GtkWidget* edit_item;
    GtkWidget* edit_submenu;
    GtkWidget* edit_undo_submenu_item;
    GtkWidget* edit_redo_submenu_item;
    GtkWidget* edit_cut_submenu_item;
    GtkWidget* edit_copy_submenu_item;
    GtkWidget* edit_paste_submenu_item;
    GtkWidget* seperator;

    edit_item = gtk_menu_item_new_with_label("Edit");

    edit_submenu = gtk_menu_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit_item), edit_submenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(header_bar), edit_item);

    edit_undo_submenu_item = gtk_menu_item_new_with_label("Undo");
    edit_redo_submenu_item = gtk_menu_item_new_with_label("Redo");
    edit_cut_submenu_item = gtk_menu_item_new_with_label("Cut");
    edit_copy_submenu_item = gtk_menu_item_new_with_label("Copy");
    edit_paste_submenu_item = gtk_menu_item_new_with_label("Paste");
    seperator = gtk_separator_menu_item_new();

    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_undo_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_redo_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), seperator);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_cut_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_copy_submenu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(edit_submenu), edit_paste_submenu_item);

    g_signal_connect(edit_undo_submenu_item, "activate", G_CALLBACK(Edit_Undo), main_data->text_buffer);
    g_signal_connect(edit_redo_submenu_item, "activate", G_CALLBACK(Edit_Redo), main_data->text_buffer);
    g_signal_connect(edit_cut_submenu_item, "activate", G_CALLBACK(Edit_Cut), main_data);
    g_signal_connect(edit_copy_submenu_item, "activate", G_CALLBACK(Edit_Copy), main_data);
    g_signal_connect(edit_paste_submenu_item, "activate", G_CALLBACK(Edit_Paste), main_data);
}

static void Create_Help_Menu(GtkWidget* header_bar, GtkWidget* window){
    GtkWidget* help_item;
    GtkWidget* help_submenu;
    GtkWidget* help_about_submenu_item;

    help_item = gtk_menu_item_new_with_label("Help");

    help_submenu = gtk_menu_new();

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_item), help_submenu);

    gtk_menu_shell_append(GTK_MENU_SHELL(header_bar), help_item);

    help_about_submenu_item = gtk_menu_item_new_with_label("About");

    gtk_menu_shell_append(GTK_MENU_SHELL(help_submenu), help_about_submenu_item);

    g_signal_connect(help_about_submenu_item, "activate", G_CALLBACK(Help_About), window);
}