#include "Edit.h"

void Edit_Undo(GtkWidget* widget, GtkSourceBuffer* text_buffer){
    if(gtk_source_buffer_can_undo(text_buffer))
        gtk_source_buffer_undo(text_buffer);
}

void Edit_Redo(GtkWidget* widget, GtkSourceBuffer* text_buffer){
    if(gtk_source_buffer_can_redo(text_buffer))
        gtk_source_buffer_redo(text_buffer);
}

void Edit_Cut(GtkWidget* widget, struct Main_Data* main_data){
    gtk_text_buffer_cut_clipboard(GTK_TEXT_BUFFER(main_data->text_buffer), main_data->clipboard, TRUE);
}

void Edit_Copy(GtkWidget* widget, struct Main_Data* main_data){
    gtk_text_buffer_copy_clipboard(GTK_TEXT_BUFFER(main_data->text_buffer), main_data->clipboard);
}

void Edit_Paste(GtkWidget* widget, struct Main_Data* main_data){
    //FIXME::PRINTS NULL IF CLIPBOARD IS EMPTY
    gtk_text_buffer_paste_clipboard(GTK_TEXT_BUFFER(main_data->text_buffer), main_data->clipboard, NULL, TRUE);
}