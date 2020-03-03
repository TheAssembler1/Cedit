#include "File.h"

static void Done_Saving();
static void Done_Loading();

void File_New(GtkWidget* widget, struct Main_Data* main_data){
    //FIXME::WE AREN"T SAVING YET MAKE A SEPERATE CALL BACK FUNCTION TO SAVE BUFFER AND THEN CREATE NEW DOCUEMENT
    //File_Save(NULL, main_data);
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(main_data->text_buffer), "", -1);
}

void File_Open(GtkWidget* widget, struct Main_Data* main_data){
    GtkWidget* dialog;
    GtkFileChooser* chooser;
    GtkFileChooserAction action;
    GFile* target_location;
    GtkSourceFileLoader* file_loader;
    gchar* file_location;
    gint res;

    //FIXME:: FIX FILE SAVE WITH CALLBACK THEN IMPLEMENT THIS
    //File_Save(NULL, main_data);

    action = GTK_FILE_CHOOSER_ACTION_SAVE;

    dialog = gtk_file_chooser_dialog_new("Save File", GTK_WINDOW(main_data->window), action,  "Cancel", GTK_RESPONSE_CANCEL, "Save", GTK_RESPONSE_ACCEPT, NULL);

    chooser = GTK_FILE_CHOOSER(dialog);

    gtk_file_chooser_set_current_name(chooser, "Untitled Document");

    res = gtk_dialog_run(GTK_DIALOG(dialog));

    if(res == GTK_RESPONSE_ACCEPT){
        file_location = gtk_file_chooser_get_filename(chooser);
        target_location = g_file_new_for_path(file_location);
        main_data->source_file = gtk_source_file_new();
        gtk_source_file_set_location(main_data->source_file, target_location);
        file_loader = gtk_source_file_loader_new(main_data->text_buffer, main_data->source_file);
        gtk_source_file_loader_load_async(file_loader, G_PRIORITY_DEFAULT, NULL, NULL, NULL, NULL, Done_Loading, NULL);
    }
    gtk_widget_destroy(dialog);
}

void File_Save(GtkWidget* widget, struct Main_Data* main_data){
    GtkSourceFileSaver* file_saver;

    //FIXME::AS OF NOW THE SOURCE FILE IS COMING OUT NULL
    if(gtk_source_file_is_local(main_data->source_file)){
        file_saver = gtk_source_file_saver_new(main_data->text_buffer, main_data->source_file);
        gtk_source_file_saver_save_async(file_saver, G_PRIORITY_DEFAULT, NULL, NULL, NULL, NULL, Done_Saving, NULL);
    }
    else
        File_Saveas(NULL, main_data);
}

void File_Saveas(GtkWidget* widget, struct Main_Data* main_data){
    GtkWidget* dialog;
    GtkFileChooser* chooser;
    GtkFileChooserAction action;
    GFile* target_location;
    GtkSourceFileSaver* file_saver;
    gchar* file_location;
    gint res;

    action = GTK_FILE_CHOOSER_ACTION_SAVE;

    dialog = gtk_file_chooser_dialog_new("Save File", GTK_WINDOW(main_data->window), action,  "Cancel", GTK_RESPONSE_CANCEL, "Save", GTK_RESPONSE_ACCEPT, NULL);

    chooser = GTK_FILE_CHOOSER(dialog);

    gtk_file_chooser_set_current_name(chooser, "Untitled Document");

    res = gtk_dialog_run(GTK_DIALOG(dialog));

    if(res == GTK_RESPONSE_ACCEPT){
        file_location = gtk_file_chooser_get_filename(chooser);
        target_location = g_file_new_for_path(file_location);
        file_saver = gtk_source_file_saver_new_with_target (main_data->text_buffer, main_data->source_file, target_location);
        gtk_source_file_set_location(main_data->source_file, target_location);
        gtk_source_file_saver_save_async(file_saver, G_PRIORITY_DEFAULT, NULL, NULL, NULL, NULL, Done_Saving, NULL);
    }
    gtk_widget_destroy(dialog);
}

//FIXME::SHOULD PROBABLY DO ERROR CHECKING HERE
static void Done_Saving(){
    g_print("Done Saving");
}

//FIXME::SHOULD PROBABLY DO ERROR CHECKING HERE
static void Done_Loading(){
    g_print("Done Loading");
}