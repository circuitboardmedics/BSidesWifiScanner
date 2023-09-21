#pragma once

#include <Arduino.h>
#include <map>
#include "string"

class FieldTimer
{
public:
    FieldTimer();

    void Add( std::string id, unsigned long waitTime );
    void Reset( std::string id );
    bool Done( std::string id, bool reset=true );
    bool Complete( std::string id );
    bool Exists( std::string id );
    void Clear();
    bool OnTheFly( std::string id, unsigned long waitTime );

private:

    struct Alarm
    {
        unsigned long startTime;
        unsigned long timeout;
    };
    
    std::map<std::string, Alarm> mAlarms;
};
