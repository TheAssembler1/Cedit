#include "FileSubmenu.h"

static gchar* Get_Text_In_Buffer(GtkTextBuffer* text_buffer){
    GtkTextIter iter_start;
    GtkTextIter iter_end;
    gtk_text_buffer_get_start_iter(text_buffer, &iter_start);
    gtk_text_buffer_get_end_iter(text_buffer, &iter_end);
    return gtk_text_buffer_get_text(text_buffer, &iter_start, &iter_end, TRUE);
}

void File_New(GtkWidget* widget, struct Main_Data* main_data){
    g_print("FILE NEW");
}

void File_Open(GtkWidget* widget, struct Main_Data* main_data){
    GtkWidget* dialog;
    GtkFileChooserAction action;
    gint res;

    action = GTK_FILE_CHOOSER_ACTION_OPEN;

    dialog = gtk_file_chooser_dialog_new("Open File", GTK_WINDOW(main_data->window), action, "Cancel", GTK_RESPONSE_CANCEL, "OPEN", GTK_RESPONSE_ACCEPT, NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));

    if(res == GTK_RESPONSE_ACCEPT){
        gchar* filename;
        gchar* file_buffer;
        GtkFileChooser* chooser;
        size_t size;
        FILE* fp;

        chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);

        fp = fopen(filename, "r");\

        fseek(fp, 0L, SEEK_END);
        size = ftell(fp);
        file_buffer = calloc(1, size);
        rewind(fp);
        fread(file_buffer, size, sizeof(char), fp); 

        fclose(fp);

        g_free(filename);

        gtk_text_buffer_set_text(main_data->current_text_buffer, file_buffer, -1);   
    }
    gtk_widget_destroy(dialog);
}

void File_Save(GtkWidget* widget, struct Main_Data* main_data){
    g_print("FILE SAVE");
}

void File_Saveas(GtkWidget* widget, struct Main_Data* main_data){
    GtkWidget* dialog;
    GtkFileChooser* chooser;
    GtkFileChooserAction action;
    gint res;

    action = GTK_FILE_CHOOSER_ACTION_SAVE;

    dialog = gtk_file_chooser_dialog_new("Save File", GTK_WINDOW(main_data->window), action,  "Cancel", GTK_RESPONSE_CANCEL, "Save", GTK_RESPONSE_ACCEPT, NULL);

    chooser = GTK_FILE_CHOOSER(dialog);

    //FIXME::CHECK IF FILE HAS BEEN EDITED AND WRITE ACCORDINGLY
    if(1){
        gtk_file_chooser_set_current_name(chooser, "NoName");
    }else{
        gtk_file_chooser_set_filename(chooser, "NOTHING");
    }

    res = gtk_dialog_run(GTK_DIALOG(dialog));

    if(res == GTK_RESPONSE_ACCEPT){
        gchar* filename;
        gchar* file_buffer;
        FILE* fp;

        file_buffer = Get_Text_In_Buffer(main_data->current_text_buffer);

        filename = gtk_file_chooser_get_filename(chooser);

        fp = fopen(filename, "w");

        fwrite(file_buffer, strlen(file_buffer), 1, fp);

        fclose(fp);

        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}