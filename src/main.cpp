/*
 * File:main.cpp
 * Description:Main point of execution in the program.
 * Author:Jeroen Mathon
 */

#include "audio_mgr.h"

int main(int argc, char **argv)
{
    audioManager aManager(argc, argv);
    aManager.setStream("file:///home/jeroen/test.mp3");
    aManager.setState(aManager.PLAY);

    return 0;
}