#include "ToolBar.h"

static void Create_File_Tool_Items(struct Main_Data* main_data, GtkWidget* tool_bar);
static void Create_Edit_Tool_Items(struct Main_Data* main_data, GtkWidget* tool_bar, GtkAccelGroup* accel_group);

void Create_Tool_Bar(struct Main_Data* main_data, GtkAccelGroup* accel_group){
    GtkWidget* tool_bar;

    tool_bar = gtk_toolbar_new();

    Create_File_Tool_Items(main_data, tool_bar);
    Create_Edit_Tool_Items(main_data, tool_bar, accel_group);

    gtk_box_pack_start(GTK_BOX(main_data->window_box), tool_bar, FALSE, FALSE, 0);
}

static void Create_File_Tool_Items(struct Main_Data* main_data, GtkWidget* tool_bar){
    GtkToolItem* file_new;
    GtkToolItem* file_open;
    GtkToolItem* file_save;
    GtkToolItem* file_saveas;
    GtkToolItem* seperator;
    GtkWidget* file_new_button;
    GtkWidget* file_open_button;
    GtkWidget* file_save_button;
    GtkWidget* file_savas;

    seperator = gtk_separator_tool_item_new();

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
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), seperator, -1); 

    gtk_tool_item_set_tooltip_text(file_new, "File New");
    gtk_tool_item_set_tooltip_text(file_open, "File Open");
    gtk_tool_item_set_tooltip_text(file_save, "File Save");
    gtk_tool_item_set_tooltip_text(file_saveas, "File Save As...");

    g_signal_connect(file_new, "clicked", G_CALLBACK(File_New_Toolbar), main_data);
    g_signal_connect(file_open, "clicked", G_CALLBACK(File_Open_Toolbar), main_data);
    g_signal_connect(file_save, "clicked", G_CALLBACK(File_Save_Toolbar), main_data);
    g_signal_connect(file_saveas, "clicked", G_CALLBACK(File_Saveas_Toolbar), main_data);
}

static void Create_Edit_Tool_Items(struct Main_Data* main_data, GtkWidget* tool_bar, GtkAccelGroup* accel_group){
    GtkToolItem* Edit_Undo;
    GtkToolItem* Edit_Redo;
    GtkToolItem* Edit_Cut;
    GtkToolItem* Edit_Copy;
    GtkToolItem* Edit_Paste;
    GtkToolItem* seperator;
    GtkWidget* Edit_Undo_Button;
    GtkWidget* Edit_Redo_Button;
    GtkWidget* Edit_Cut_Button;
    GtkWidget* Edit_Copy_Button;
    GtkWidget* Edit_Paste_Button;

    seperator = gtk_separator_tool_item_new();

    Edit_Undo_Button = gtk_image_new_from_icon_name("edit-undo", 0);
    Edit_Redo_Button = gtk_image_new_from_icon_name("edit-redo", 0);
    Edit_Cut_Button = gtk_image_new_from_icon_name("edit-cut", 0);
    Edit_Copy_Button = gtk_image_new_from_icon_name("edit-copy", 0);
    Edit_Paste_Button = gtk_image_new_from_icon_name("edit-paste", 0);

    Edit_Undo = gtk_tool_button_new(Edit_Undo_Button, "_Z");
    Edit_Redo = gtk_tool_button_new(Edit_Redo_Button, "_U");
    Edit_Cut = gtk_tool_button_new(Edit_Cut_Button, NULL);
    Edit_Copy = gtk_tool_button_new(Edit_Copy_Button, NULL);
    Edit_Paste = gtk_tool_button_new(Edit_Paste_Button, NULL);

    gtk_widget_add_accelerator(GTK_WIDGET(Edit_Undo), "clicked", accel_group, GDK_KEY_z, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
    gtk_widget_add_accelerator(GTK_WIDGET(Edit_Redo), "clicked", accel_group, GDK_KEY_y, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), Edit_Undo, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), Edit_Redo, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), seperator, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), Edit_Cut, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), Edit_Copy, -1);
    gtk_toolbar_insert(GTK_TOOLBAR(tool_bar), Edit_Paste, -1);

    gtk_tool_item_set_tooltip_text(Edit_Undo, "Undo");
    gtk_tool_item_set_tooltip_text(Edit_Redo, "Redo");
    gtk_tool_item_set_tooltip_text(Edit_Cut, "Cut");
    gtk_tool_item_set_tooltip_text(Edit_Copy, "Copy");
    gtk_tool_item_set_tooltip_text(Edit_Paste, "Paste");

    g_signal_connect(Edit_Undo, "clicked", G_CALLBACK(Edit_Undo_Toolbar), main_data->text_buffer);
    g_signal_connect(Edit_Redo, "clicked", G_CALLBACK(Edit_Redo_Toolbar), main_data->text_buffer);
    g_signal_connect(Edit_Cut, "clicked", G_CALLBACK(Edit_Cut_Toolbar), main_data);
    g_signal_connect(Edit_Copy, "clicked", G_CALLBACK(Edit_Copy_Toolbar), main_data);
    g_signal_connect(Edit_Paste, "clicked", G_CALLBACK(Edit_Paste_Toolbar), main_data);
}