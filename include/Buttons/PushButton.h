#pragma once

#include <Arduino.h>

class PushButton
{
public:
    const static bool PRESSED = LOW;
    const static bool RELEASED = HIGH;

    PushButton(uint8_t pin, uint16_t debounce_ms = 100)
    :  _pin(pin)
    ,  _delay(debounce_ms)
    ,  _state(HIGH)
    ,  _ignore_until(0)
    ,  _has_changed(false)
    {
    }

    void begin()
    {
        pinMode(_pin, INPUT_PULLUP);
    }

    bool read()
    {
        // ignore pin changes until after this delay time
        if (_ignore_until > millis())
        {
            // ignore any changes during this period
        }
        
        // pin has changed 
        else if (digitalRead(_pin) != _state)
        {
            _ignore_until = millis() + _delay;
            _state = !_state;
            _has_changed = true;
        }
        
        return _state;
    }

    // has the button been toggled from on -> off, or vice versa
    bool toggled()
    {
        read();
        return has_changed();
    }

    // mostly internal, tells you if a button has changed after calling the read() function
    bool has_changed()
    {
        if (_has_changed)
        {
            _has_changed = false;
            return true;
        }
        return false;
    }

    // has the button gone from off -> on
    bool pressed()
    {
        return (read() == PRESSED && has_changed());
    }

    bool held()
    {
        return (read() == PRESSED );
    }

    // has the button gone from on -> off
    bool released()
    {
        return (read() == RELEASED && has_changed());
    }

private:
    uint8_t  _pin;
    uint16_t _delay;
    bool     _state;
    uint32_t _ignore_until;
    bool     _has_changed;
};
