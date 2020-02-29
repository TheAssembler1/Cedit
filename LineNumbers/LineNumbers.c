#include "LineNumbers.h"

void Create_Line_Numbers(GtkWidget* scrolled_window){
    GtkCellRenderer* renderer;
    GtkWidget* view;
    GtkListStore* store;
    GtkTreeIter iter;

    store = gtk_list_store_new(1, G_TYPE_INT, G_TYPE_UINT);
    view = gtk_tree_view_new();
    renderer = gtk_cell_renderer_text_new();

    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view), -1, "Name", renderer, "text", 0, NULL);
    for(int i = 0; i < 5000; i++){
        gtk_list_store_append(store, &iter);
    }
     gtk_list_store_set(store, &iter, 0, 1, -1);
    gtk_tree_view_set_model(GTK_TREE_VIEW(view), GTK_TREE_MODEL(store));

    g_object_unref(store);

    gtk_container_add(GTK_CONTAINER(scrolled_window), view);
}