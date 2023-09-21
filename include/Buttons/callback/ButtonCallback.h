#pragma once

#include "Buttons/ButtonDefs.h"

class ButtonCallback
{
public:
    virtual void NofityButtonEvent( Buttons::Event const * event ) = 0;
};
