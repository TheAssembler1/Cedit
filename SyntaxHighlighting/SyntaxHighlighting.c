#include "SyntaxHighlighting.h"

gboolean Syntax_Highlighting(gpointer user_data){
    GtkTextBuffer* text_buffer;
    GtkTextTagTable* tag_table;
    GtkTextTag* text_tag;
    GtkTextIter iter_start;
    GtkTextIter iter_end;
    GtkTextIter iter_str_start;
    GtkTextIter iter_str_end;

    text_buffer = user_data;

    gtk_text_buffer_get_start_iter(text_buffer, &iter_start);
    gtk_text_buffer_get_end_iter(text_buffer, &iter_end);
    text_tag = gtk_text_buffer_create_tag(text_buffer, "blue_foreground", "foreground", "blue", NULL);
    gtk_text_buffer_remove_tag(text_buffer, text_tag, &iter_start, &iter_end);

    while(gtk_text_iter_forward_search(&iter_start, "go", GTK_TEXT_SEARCH_VISIBLE_ONLY, &iter_str_start, &iter_str_end, NULL)){
        //gtk_text_buffer_apply_tag(text_buffer, text_tag, &iter_str_start, &iter_str_end);
        gtk_text_iter_forward_chars(&iter_start, 2);
    }

    
    return TRUE;
}