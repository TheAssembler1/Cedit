#include "LineNumbers.h"
#include <stdio.h>

//FIXME::FIX THE ASSERTION WITH THE TEXT BUFFER
//FIXME::CRASHES AT AROUND LINE 1950
//FIXME::MAKE IT WHERE IT DOES TOWARDS CLOSES LINE

gboolean Refresh_Line_Numbers(gpointer user_data){
    
    struct Main_Data* main_data = user_data;

    guint text_buffer_height = gtk_text_buffer_get_line_count(main_data->current_text_buffer);
    guint line_buffer_height = gtk_text_buffer_get_line_count(main_data->line_numbers_buffer);

    if(text_buffer_height !=  line_buffer_height){
        GtkTextIter iter_start;

        gtk_text_buffer_set_text(main_data->line_numbers_buffer, "", -1);
        gtk_text_buffer_get_start_iter(main_data->line_numbers_buffer, &iter_start);

        for(guint i = 0; i < text_buffer_height; i++){
            
            guint line_numbers = i+1;
            gchar line_numbers_string[(((sizeof(line_numbers)) * CHAR_BIT) + 2)/3 + 2];
            sprintf(line_numbers_string, "%d", line_numbers);

            gtk_text_buffer_insert(main_data->line_numbers_buffer, &iter_start, line_numbers_string, strlen(line_numbers_string));
            if(i != gtk_text_buffer_get_line_count(main_data->current_text_buffer)-1)
                gtk_text_buffer_insert(main_data->line_numbers_buffer, &iter_start, "\n", 1);
        }
    }
    return TRUE;
}