#include "Screen/PageManager.h"

PageManager::PageManager(  SH1106& screen, ButtonManager& buttonManager )
    : mScreen( screen )
    , mRateMillis( 0 )
    , mCurrentPage( 0 )
    , mWifiScanner( new WifiScanner() )
{
    // init display
    mScreen.init();
    mScreen.flipScreenVertically();

    // register button callback
    buttonManager.RegisterCallback( this );

    // init splash screen timer
    mTimer.Add( "SplashScreen", 3000 );
    drawSplashImage( mScreen );

    // start wifi scan
    mWifiScanner->DoScan();

    // set draw function
    mDrawFunc = (DrawFunctionType)&PageManager::drawNetInfo;
}

void PageManager::Run()
{
    // splash screen still going, don't run
    if ( !mTimer.Done( "SplashScreen", false ) ) return;

    // run draw loop
    if ( mTimer.OnTheFly( "RefreshRate", mRateMillis ) )
    {
        mScreen.clear(); // clear display
        mRateMillis = ( this->*mDrawFunc )( mScreen );
        mScreen.display(); // write buffer to display
    }
}

//=============================================================
//                         Protected
//=============================================================
void PageManager::NofityButtonEvent( Buttons::Event const * event ) // override
{
    // get PUSH events, otherwise return early
    if ( Buttons::HOLD == event->action ) return;

    // handle PUSH event
    switch ( event->button )
    {
        case Buttons::BTN_1:
            decremementPage();
        break;

        case Buttons::BTN_2:
            selectPage();
        break;

        case Buttons::BTN_3:
            incrementPage();
        break;
    }
}

//=============================================================
//                         Private
//=============================================================
void PageManager::incrementPage()
{
    if ( mWifiScanner->GetNetCount() > ( mCurrentPage + 1 ) )
    {
        mGraphData.clear();
        mCurrentPage++;
    }
}

void PageManager::decremementPage()
{
    if ( 0 < mCurrentPage )
    {
        mGraphData.clear();
        mCurrentPage--;
    }
}

void PageManager::selectPage()
{
    if ( (DrawFunctionType)&PageManager::drawNetInfo == mDrawFunc )
    {
        mDrawFunc = (DrawFunctionType)&PageManager::drawSignalGraph;
    }
    else
    {
        mDrawFunc = (DrawFunctionType)&PageManager::drawNetInfo;
    }
}

unsigned long PageManager::drawNetInfo( SH1106& screen )
{
    WifiScanner::NetInfo netInfo = mWifiScanner->GetNetInfo( mCurrentPage );
    uint16_t currRowHeight = 0;
    uint16_t rowInc = 10;

    String macRow       = String( "MAC: " )         + netInfo.mac.c_str();
    String encRow       = String( "Encryption: " )  + netInfo.encryptionType.c_str();
    String channelRow   = String( "Channel: " )     + netInfo.channel;
    String rssiRow      = String( "RSSI: " )        + netInfo.rssi;
    String pageString   = String( mCurrentPage + 1 ) + "/" + String( mWifiScanner->GetNetCount() );

    // draw title
    screen.setTextAlignment( TEXT_ALIGN_CENTER );
    screen.setFont( ArialMT_Plain_16 );
    screen.drawString( ( SCREEN_WIDTH / 2 ), currRowHeight, netInfo.ssid.c_str() );
    currRowHeight += 20;

    // mac
    screen.setTextAlignment( TEXT_ALIGN_LEFT );
    screen.setFont( ArialMT_Plain_10 );
    screen.drawString( 0, currRowHeight, macRow );
    currRowHeight += rowInc;

    // encryption
    screen.setFont( ArialMT_Plain_10 );
    screen.drawString( 0, currRowHeight, encRow );
    currRowHeight += rowInc;

    // channel
    screen.setFont( ArialMT_Plain_10 );
    screen.drawString( 0, currRowHeight, channelRow );
    currRowHeight += rowInc;

    // rssi
    screen.setFont( ArialMT_Plain_10 );
    screen.drawString( 0, currRowHeight, rssiRow );

    screen.drawString( 100, currRowHeight, pageString );

    return 0;
}

unsigned long PageManager::drawSignalGraph( SH1106& screen )
{
    WifiScanner::NetInfo netInfo = mWifiScanner->GetNetInfo( mCurrentPage );
    // uint8_t newVal = map( netInfo.rssi, -20, -80, 0, 64 );
    uint8_t newVal = map( netInfo.rssi, -20, -100, 0, 64 );
    uint8_t graphSize = mGraphData.size();

    // draw title
    screen.setTextAlignment( TEXT_ALIGN_CENTER );
    screen.setFont( ArialMT_Plain_16 );
    screen.drawString( ( SCREEN_WIDTH / 2 ), 0, netInfo.ssid.c_str() );

    // update graph data with new signal value
    if ( ( SCREEN_WIDTH / 2 ) > graphSize )
    {
        // add new value
        uint8_t xVal = 2 * graphSize;
        mGraphData.push_back( { xVal, newVal } );
        graphSize++;
    }
    else
    {
        // shift the data to the left
        for( int i = 0; i < graphSize - 1; ++i )
        {
            mGraphData[i].y = mGraphData[i + 1].y;
        }
        // overwrite end-most element with new value
        mGraphData[graphSize - 1].y = newVal;
    }

    // draw graph data
    if( !mGraphData.empty() )
    {
        // Draw graph lines
        for ( int i = 1; i < graphSize; ++i )
        {
            screen.drawLine( mGraphData[i - 1].x, mGraphData[i - 1].y, mGraphData[i].x, mGraphData[i].y );
        }
    }
    return 100;
}

unsigned long PageManager::drawSplashImage( SH1106& screen )
{
    screen.clear();
    screen.drawXbm( 0, 0, 128, 53, bSidesLogo );
    screen.display();
    return 0;
}

