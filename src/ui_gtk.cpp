//
// Created by jeroen on 9/26/15.
//

#include "ui_gtk.h"

gtkInterface::gtkInterface()
{
    builder->get_widget("window", window);
}

gtkInterface::~gtkInterface()
{

}

int gtkInterface::run()
{
    window->show();
}