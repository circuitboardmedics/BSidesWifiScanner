#pragma once

#include <list>

#include "Buttons/ButtonDefs.h"
#include "Buttons/PushButton.h"
#include "Buttons/callback/ButtonCallback.h"

using namespace Buttons;

class ButtonManager
{
public:
    ButtonManager()
        : mCallbacks()
    {
        buttons[BTN_1] = new PushButton( BUTTON_1_PIN );
        buttons[BTN_2] = new PushButton( BUTTON_2_PIN );
        buttons[BTN_3] = new PushButton( BUTTON_3_PIN );

        for ( int i = 0; i < BTN_CNT; i++ )
        {
            buttons[i]->begin();
        }
    }

    void Run()
    {
        // static const int buttonDebounce = 100;
        static const int buttonDebounce = 10;
        static unsigned long prevPressMillis = 0;
        unsigned long currMillis = millis();

        if ( ( buttonDebounce <= ( currMillis - prevPressMillis ) ) &&
            ( HasEvent()                                         ) )
        {
            prevPressMillis = currMillis;
            notify();
        }
    }

    bool HasEvent()
    {
        bool hasEvent = false;
        mCurrentEvent.button = BTN_CNT;

        for ( int i = 0; i < BTN_CNT; i++ )
        {
            bool btnPressed = buttons[i]->pressed();
            bool btnHeld = buttons[i]->held();

            // check to create event 
            hasEvent |= ( btnPressed || btnHeld );
            if ( hasEvent )
            {
                // create event
                mCurrentEvent.button = i;
                mCurrentEvent.action = btnPressed ? PRESS : HOLD;
                break;
            }
        }
        return hasEvent;
    }

    Buttons::Event const * GetEvent()
    {
        return &mCurrentEvent;
    }

    void RegisterCallback( ButtonCallback * callback )
    {
        mCallbacks.push_back( callback );
    }


    
private:
    PushButton * buttons[Buttons::BTN_CNT];
    Buttons::Event mCurrentEvent;
    std::list<ButtonCallback *> mCallbacks;

    void notify()
    {
        for ( ButtonCallback * callback : mCallbacks )
        {
            callback->NofityButtonEvent( &mCurrentEvent );
        }
    }

};
