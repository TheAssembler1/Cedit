#include <gtk/gtk.h>
#include "HeaderBar/HeaderBar.h"
#include "TextEnvironment/TextEnvironment.h"
#include "TextEnvironment/LineNumbers/LineNumbers.h"
#include "SyntaxHighlighting/SyntaxHighlighting.h"
#include "MainData.h"

static gchar* title = "Cedit";

static gint syntax_delay = 1;
static gint line_numbers_delay = 500;

static gint window_width = 640;
static gint window_height = 360;

static GtkWidget* window_box;

struct Main_Data main_data;

static void activate(GtkApplication* app, gpointer user_data){

    main_data.window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(main_data.window), title);
    gtk_window_set_default_size(GTK_WINDOW(main_data.window), window_width, window_height);
    gtk_window_set_position(GTK_WINDOW(main_data.window), GTK_WIN_POS_CENTER_ALWAYS);

    Create_Header_Bar(&main_data, &window_box);

    Create_Text_Environment(window_box, &main_data);

    gtk_widget_show_all(main_data.window);

    //g_timeout_add_seconds(1, Syntax_Highlighting, main_data.current_text_buffer);

    g_timeout_add(line_numbers_delay, Refresh_Line_Numbers, &main_data);
}

int main(int argc, char** argv){
    GtkApplication* app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}