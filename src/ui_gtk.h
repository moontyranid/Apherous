//
// Created by jeroen on 9/26/15.
//

#ifndef APHEROUS_UI_GTK_H
#define APHEROUS_UI_GTK_H

#include <iostream>
#include <gtkmm.h>
#include <sstream>
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
    void browseBtnOnClick();
    void addFileBtnOnClick();

    // Private variables
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("ui/ui.glade");
    Gtk::Box *mainBox;
    Gtk::Box *controlBox;
    Gtk::Box *fileBox;
    Gtk::Button *playBtn;
    Gtk::Button *pauseBtn;
    Gtk::Button *stopBtn;
    Gtk::Button *browseBtn;
    Gtk::Button *addFileBtn;
    Gtk::Statusbar *progressBar;
    Gtk::Entry *pathEntry;


    audioManager *aManager;
    int _argc;
    char **_argv;
};
#endif //APHEROUS_UI_GTK_H
