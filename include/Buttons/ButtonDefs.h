#pragma once

#include <Arduino.h>

namespace Buttons
{
    static const uint8_t BUTTON_1_PIN = D5;
    static const uint8_t BUTTON_2_PIN = D6;
    static const uint8_t BUTTON_3_PIN = D7;

    typedef uint8_t Id; enum
    {
        BTN_1,
        BTN_2,
        BTN_3,
        BTN_CNT
    };

    typedef uint8_t Action; enum
    {
        PRESS,
        HOLD,
        NONE
    };

    struct Event
    {
        Id button;
        Action action;
    };

};
