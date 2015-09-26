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
}

void gtkInterface::pauseBtnOnClick()
{
    std::cout << "Pausing\n";
}

void gtkInterface::stopBtnOnClick()
{
    std::cout << "Stopping\n";
}

int gtkInterface::run()
{
    window->show();
}