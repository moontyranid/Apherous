//
// Created by jeroen on 9/24/15.
//

#ifndef BINARY_TO_ASCII_TRANSLATOR_AUDIO_MGR_H
#define BINARY_TO_ASCII_TRANSLATOR_AUDIO_MGR_H

#include <iostream>
#include <sstream>
#include <gst/gst.h>

/// Audio Manager
/** This class contains a set of functions for controlling the
 * audio in the program.
 **/
class audioManager
{
public:
    // Constructor and Destructor
    audioManager(int argc, char  **argv);
    ~audioManager();

    // Public routines
    void setState(int state); // Sets the state of the audio player
    void setStream(std::string uri);  // Sets the stream to read from

    // Public variables
    /// An enumeration of the states that the audio manager can be in
    enum class audioStates
    {
        PLAY, ///< 0
        PAUSE, ///< 1
        STOP ///< 2
    };

private:
    // Private variables
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;
    GError *gError = NULL;
};
#endif //BINARY_TO_ASCII_TRANSLATOR_AUDIO_MGR_H
