//
// Created by jeroen on 9/24/15.
//

#include "audio_mgr.h"

audioManager::audioManager(int argc, char  **argv)
{
    gst_init(&argc, &argv);
}

audioManager::~audioManager()
{
    gst_message_unref(msg);
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
}
/**
 *****************************************************************************************
 *  @brief      Sets the state of the audio player
 *
 *  @usage      This function can be called from the audioManager class
 *
 *  @param      int state: The state top put the audio player in.(Being PLAY,PAUSE or STOP)
 ******************************************************************************************
 **/
void audioManager::setState(int state)
{
    switch(state)
    {
        case PLAY:
        {
            gst_element_set_state(pipeline, GST_STATE_PLAYING);
            bus = gst_element_get_bus(pipeline);
            msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GstMessageType(GST_MESSAGE_ERROR
                                                                                      | GST_MESSAGE_EOS));
            break;
        }

        case PAUSE:
            gst_element_set_state(pipeline, GST_STATE_PAUSED);
            break;

        case STOP:
            gst_element_set_state(pipeline, GST_STATE_NULL);
            break;

        default:
            break;
    }
}

/**
 *****************************************************************************************
 *  @brief      Sets the stream for the audio manager
 *-
 *  @usage      This sets the audio stream/file to use for the audio player
 *
 *  @param      std::string uri: The URI used for the audio player
 ******************************************************************************************
 **/
void audioManager::setStream(std::string uri)
{
    std::stringstream uriStream;
    uriStream << "playbin uri=\"" << uri << "\"";

    pipeline = gst_parse_launch(uriStream.str().c_str(), &gError);
    if(gError != nullptr)
    {
        std::cout << "Glib Error:" << gError->message << "\n";
    }
}