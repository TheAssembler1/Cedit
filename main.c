#include <gtk/gtk.h>
#include "HeaderBar/HeaderBar.h"
#include "TextEnvironment/TextEnvironment.h"

static gchar* title = "Cedit";

static gint window_width = 640;
static gint window_height = 360;

static GtkWidget* window;
static GtkWidget* window_box;

static void activate(GtkApplication* app, gpointer user_data){

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_window_set_default_size(GTK_WINDOW(window), window_width, window_height);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS);

    Create_Header_Bar(window, &window_box);

    Create_Text_Environment(window_box);

    gtk_widget_show_all(window);
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