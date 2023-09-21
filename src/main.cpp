#include <Arduino.h>
#include "Wire.h"
#include "SH1106.h"

// std
#include <map>

// project
#include "Screen/PageManager.h"
#include "Buttons/ButtonManager.h"
#include "FieldTimer.h"

// vars
SH1106 screen( 0x3c, SDA, SCL );
FieldTimer timer;
ButtonManager buttonManager;
PageManager * pageManager;

void setup()
{
    Serial.begin( 9600 );
    Serial.println( "" );

    pageManager = new PageManager( screen, buttonManager );
}

void loop()
{
    pageManager->Run();
    buttonManager.Run();
}
