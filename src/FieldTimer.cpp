#include "FieldTimer.h"

FieldTimer::FieldTimer()
    : mAlarms()
{ }

void FieldTimer::Add( std::string id, unsigned long waitTime )
{
    unsigned long currTime = millis();

    if ( mAlarms.end() == mAlarms.find( id ) )
    {
        // new alarm
        mAlarms[id] = { currTime, waitTime };
    }
    else
    {
        // alarm already exists
        mAlarms[id].startTime = currTime;
        mAlarms[id].timeout = waitTime;
    }
}

bool FieldTimer::Done( std::string id, bool reset )
{
    bool timeoutResult = false;
    if ( mAlarms.end() != mAlarms.find( id ) )
    {
        Alarm alarm = mAlarms[id];
        if ( ( 0                != alarm.timeout              ) &&
             ( alarm.timeout < ( millis() - alarm.startTime ) ) )
        {
            // alarm done
            timeoutResult = true;
            if ( reset )
                Reset( id );
        }
    }
    return timeoutResult;
}


bool FieldTimer::Complete( std::string id )
{
    bool timeoutResult = false;
    if ( mAlarms.end() != mAlarms.find( id ) )
    {
        Alarm alarm = mAlarms[id];
        if ( ( 0                != alarm.timeout              ) &&
             ( alarm.timeout < ( millis() - alarm.startTime ) ) )
        {
            // alarm done
            timeoutResult = true;
            mAlarms.erase( id );
        }
    }
    return timeoutResult;
}

bool FieldTimer::Exists( std::string id )
{
    return ( ( !mAlarms.empty()                    ) && // list isn't empty
             ( mAlarms.end() != mAlarms.find( id ) ) ); // id is present
}

void FieldTimer::Reset( std::string id )
{
    mAlarms[id].startTime = millis();
}

bool FieldTimer::OnTheFly( std::string id, unsigned long waitTime )
{
    bool timeoutResult = false;
    unsigned long currTime = millis();

    if ( 0 == mAlarms.count( id ) )
    {
        // add alarm
        //              start     timeout
        mAlarms[id] = { currTime, waitTime };
    }
    else
    {
        Alarm alarm = mAlarms[id];
        if ( alarm.timeout < ( millis() - alarm.startTime )  )
        {

            // alarm done
            timeoutResult = true;
            mAlarms.erase( id );
        }
    }
    return timeoutResult;
}

void FieldTimer::Clear()
{
    mAlarms.clear();
}
