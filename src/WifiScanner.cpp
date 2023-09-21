#include "WiFiScanner.h"

#include "ESP8266WiFi.h"

WifiScanner::WifiScanner()
    : mNetworkCount( 0 )
{
    WiFi.mode( WIFI_STA );
    WiFi.disconnect();
}

void WifiScanner::DoScan()
{
    mNetworks.clear();
    // mNetworkCount = WiFi.scanNetworks( false, true );
    mNetworkCount = WiFi.scanNetworks( false, false );
    for ( int i = 0; i < mNetworkCount; i++ )
    {
        NetInfo info;
        info.ssid       = WiFi.SSID( i ).c_str();
        info.mac        = WiFi.BSSIDstr( i ).c_str();
        info.rssi       = WiFi.RSSI( i );
        info.channel    = WiFi.channel( i );
        info.encryptionType = GetEncryptionString( WiFi.encryptionType( i ) );

        mNetworks.push_back( info );
    }

    Serial.println( mNetworkCount );
}

const WifiScanner::NetInfo& WifiScanner::GetNetInfo( int idx )
{ 
    int netCount = WiFi.scanNetworks( false, false, mNetworks[idx].channel, (uint8_t*)mNetworks[idx].ssid.c_str() );
    if ( 0 < netCount )
    {
        mNetworks[idx].rssi = WiFi.RSSI( 0 );
    }
    return mNetworks[idx];
}

int WifiScanner::GetNetCount()
{
    return mNetworkCount;
}

std::string WifiScanner::GetEncryptionString( int type )
{
    std::string resultStr;
    switch ( type )
    {
        case ENC_TYPE_WEP:
            resultStr = "WEP";
        break;

        case ENC_TYPE_TKIP:
            resultStr = "WPA";
        break;

        case ENC_TYPE_CCMP:
            resultStr = "WPA2";
        break;

        case ENC_TYPE_NONE:
            resultStr = "None";
        break;

        case ENC_TYPE_AUTO:
            resultStr = "Auto";
        break;

        default:
            resultStr = "Unknown";
        break;
    }

    return resultStr;
}
