//
// Created by jeroen on 9/24/15.
//

#ifndef BINARY_TO_ASCII_TRANSLATOR_AUDIO_MGR_H
#define BINARY_TO_ASCII_TRANSLATOR_AUDIO_MGR_H

#include <iostream>
#include <sstream>
#include <gst/gst.h>

class audioManager
{
public:
    // Constructor and Destructor
    audioManager(int argc, char  **argv);
    ~audioManager();

    // Public routines
    void setState(int state);
    void setStream(std::string uri);  /// Sets the stream to read from

    // Public variables
    enum    // An enumeration of the state the audio manager can be in
    {
        PLAY,
        PAUSE,
        STOP
    };

private:
    // Private variables
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;
    GError *gError;
};
#endif //BINARY_TO_ASCII_TRANSLATOR_AUDIO_MGR_H
