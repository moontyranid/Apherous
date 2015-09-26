//
// Created by jeroen on 9/26/15.
//

#ifndef APHEROUS_UI_GTK_H
#define APHEROUS_UI_GTK_H

#include <iostream>
#include <gtkmm.h>
#include "audio_mgr.h"

class gtkInterface
{
public:
    // Constructor and Destructor
    gtkInterface();
    ~gtkInterface();

    // Public routines
    int run(int argc, char **argv);

    // Public variables
    Gtk::Window *window;

private:
    // Private routines
    void playBtnOnClick();
    void pauseBtnOnClick();
    void stopBtnOnClick();

    // Private variables
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("ui/ui.glade");
    Gtk::Box *controlBox;
    Gtk::Button *playBtn;
    Gtk::Button *pauseBtn;
    Gtk::Button *stopBtn;

    audioManager *aManager;
    int _argc;
    char **_argv;
};
#endif //APHEROUS_UI_GTK_H
