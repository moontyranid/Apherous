//
// Created by jeroen on 9/26/15.
//

#ifndef APHEROUS_UI_GTK_H
#define APHEROUS_UI_GTK_H

#include <gtkmm.h>

class gtkInterface
{
public:
    // Constructor and Destructor
    gtkInterface();
    ~gtkInterface();

    // Public routines
    void run();

private:
    // Private variables
    Gtk::Window *window;
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("ui/ui.glade");

};
#endif //APHEROUS_UI_GTK_H
