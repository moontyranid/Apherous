/*
 * File:main.cpp
 * Description:Main point of execution in the program.
 * Author:Jeroen Mathon
 */

#define GUI "gtk"
//#define GUI "cli"

#include "audio_mgr.h"
#include "ui_gtk.h"

int main(int argc, char **argv)
{
    if(GUI == "gtk")
    {
        Glib::RefPtr<Gtk::Application> app =
                Gtk::Application::create(argc, argv, "JeroenMathon.Apherous");
        gtkInterface gInterface;
        gInterface.run(argc, argv);

        return app->run(*gInterface.window);
    }

    // TODO:Implement a CLI Interface
    else if(GUI == "cli")
    {
        audioManager aManager(argc, argv);
        aManager.setStream("file:///home/jeroen/test.mp3");
        aManager.setState(int(audioManager::audioStates::PLAY));

        return 0;
    }


    return 0;
}