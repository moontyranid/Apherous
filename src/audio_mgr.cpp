//
// Created by jeroen on 9/24/15.
//

#include "audio_mgr.h"

/**
 *****************************************************************************************
 *  @brief      The gst bus callback.
 *
 *  @usage      This function collects data from the GLIB thread that manages the bus
 *
 *  @param      GstBus *bus: A pointer to the gst bus
 *  @param      GstMessage *msg: A pointer to the GstMessage object that holds information returned by the bus thread
 *  @param      gpointer data: the a pointer to the data that will be used in the thread
 ******************************************************************************************
 **/
static gboolean bus_call(GstBus *bus, GstMessage *msg, gpointer data)
{
    GMainLoop *loop = (GMainLoop *) data;

    switch(GST_MESSAGE_TYPE(msg))
    {
        case GST_MESSAGE_EOS:
        {
            g_print("End of stream\n");
            g_main_loop_quit(loop);
            break;
        }

        case GST_MESSAGE_ERROR:
        {
            gchar *debug;
            GError *error;

            gst_message_parse_error(msg, &error, &debug);
            g_free(debug);

            g_printerr("Error: %s\n", error->message);
            g_free(error);

            g_main_loop_quit(loop);
            break;
        }

        default:
        {
            break;
        }
    }

    return TRUE;
}

audioManager::audioManager(int argc, char  **argv)
{
    pipeline = gst_element_factory_make("playbin", NULL);
    loop = g_main_loop_new(NULL, FALSE);
    bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));
    bus_watch_id = gst_bus_add_watch(bus, bus_call, loop);
    gst_init(&argc, &argv);
}

audioManager::~audioManager()
{
    gst_message_unref(msg);
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    g_source_remove(bus_watch_id);
    g_main_loop_unref(loop);
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
        case int(audioStates::PLAY):
        {
            gst_element_set_state(pipeline, GST_STATE_PLAYING);
            break;
        }

        case int(audioStates::PAUSE):
            gst_element_set_state(pipeline, GST_STATE_PAUSED);
            break;

        case int(audioStates::STOP):
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