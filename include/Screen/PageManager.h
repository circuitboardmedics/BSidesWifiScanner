#pragma once

// PIO external
#include "Wire.h"
#include "SH1106.h"
#include "OLEDDisplayUi.h"

// std
#include <map>
#include <vector>

// project
#include "images.h"
#include "FieldTimer.h"
#include "WiFiScanner.h"
#include "FieldTimer.h"

#include "Buttons/ButtonManager.h"
#include "Buttons/callback/ButtonCallback.h"

class PageManager: public ButtonCallback
{
public:
    PageManager( SH1106& screen, ButtonManager& buttonManager );

    void Run();

protected:
    void NofityButtonEvent( Buttons::Event const * event ) override;

private:
    struct Point
    {
        uint8_t x;
        uint8_t y;
    };

    typedef unsigned long ( PageManager::*DrawFunctionType )( SH1106& screen );

    static const uint8_t SCREEN_WIDTH  = 128;
    static const uint8_t SCREEN_HEIGHT = 64;

    SH1106 mScreen;
    FieldTimer mTimer;
    unsigned long mRateMillis;
    int mCurrentPage;
    WifiScanner * mWifiScanner;
    std::vector<Point> mGraphData;
    DrawFunctionType mDrawFunc;

    void decremementPage();
    void incrementPage();
    void selectPage();

    unsigned long drawNetInfo( SH1106& screen );
    unsigned long drawSignalGraph( SH1106& screen );
    unsigned long drawSplashImage( SH1106& screen );
};
