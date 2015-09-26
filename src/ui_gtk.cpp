//
// Created by jeroen on 9/26/15.
//

#include "ui_gtk.h"

gtkInterface::gtkInterface()
{
    builder->get_widget("window", window);
    builder->get_widget("controlBox", controlBox);
    builder->get_widget("playBtn", playBtn);
    builder->get_widget("pauseBtn", pauseBtn);
    builder->get_widget("stopBtn", stopBtn);

    playBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::playBtnOnClick));
    pauseBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::pauseBtnOnClick));
    stopBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::stopBtnOnClick));
}

gtkInterface::~gtkInterface()
{

}

void gtkInterface::playBtnOnClick()
{
    std::cout << "Playing\n";
    aManager->setState(int(audioManager::audioStates::PLAY));
}

void gtkInterface::pauseBtnOnClick()
{
    std::cout << "Pausing\n";
    aManager->setState(int(audioManager::audioStates::PAUSE));
}

void gtkInterface::stopBtnOnClick()
{
    aManager->setState(int(audioManager::audioStates::STOP));
    std::cout << "Stopping\n";
}

int gtkInterface::run(int argc, char **argv)
{
    _argc = argc;
    _argv = argv;
    aManager = new audioManager(_argc, _argv);
    aManager->setStream("file:///home/jeroen/test.mp3");
    window->show();
}