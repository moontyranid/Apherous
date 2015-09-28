//
// Created by jeroen on 9/26/15.
//

#include "ui_gtk.h"

gtkInterface::gtkInterface()
{
    // Set up the main window and box
    builder->get_widget("window", window);
    builder->get_widget("mainBox", mainBox);

    // Set up the Filebox
    builder->get_widget("fileBox", fileBox);
    builder->get_widget("browseBtn", browseBtn);
    builder->get_widget("addFileBtn", addFileBtn);
    builder->get_widget("pathEntry", pathEntry);

    // Set up the Controlbox
    builder->get_widget("controlBox", controlBox);
    builder->get_widget("playBtn", playBtn);
    builder->get_widget("pauseBtn", pauseBtn);
    builder->get_widget("stopBtn", stopBtn);
    builder->get_widget("progressBar", progressBar);

    // Connect all the buttons to their event handlers
    playBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::playBtnOnClick));
    pauseBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::pauseBtnOnClick));
    stopBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::stopBtnOnClick));
    browseBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::browseBtnOnClick));
    addFileBtn->signal_clicked().connect(sigc::mem_fun(this, &gtkInterface::addFileBtnOnClick));
}

gtkInterface::~gtkInterface()
{

}

// Button event handlers
void gtkInterface::playBtnOnClick()
{
    aManager->setState(int(audioManager::audioStates::PLAY));
}

void gtkInterface::pauseBtnOnClick()
{
    aManager->setState(int(audioManager::audioStates::PAUSE));
}

void gtkInterface::stopBtnOnClick()
{
    aManager->setState(int(audioManager::audioStates::STOP));
}

void gtkInterface::browseBtnOnClick()
{

}

void gtkInterface::addFileBtnOnClick()
{
    std::stringstream path;
    path << "file://" << pathEntry->get_text();
    aManager->setStream(path.str());
}

void gtkInterface::prevBtnOnClick()
{

}

void gtkInterface::nextBtnOnClick()
{

}

/**
 *****************************************************************************************
 *  @brief      Sets up the interface for running
 *
 *  @usage      This function sets up the interface so it can be used in the GMainLoop
 *
 *  @param      int argc: Holds the total number of arguments passed to the function
 *  @param      char **argv: Holda the arguments passed to the function
 ******************************************************************************************
 **/
int gtkInterface::run(int argc, char **argv)
{
    _argc = argc;
    _argv = argv;
    aManager = new audioManager(_argc, _argv);
    window->show();
}