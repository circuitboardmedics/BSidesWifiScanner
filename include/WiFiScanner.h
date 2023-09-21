#pragma once

#include <string>
#include <vector>

#include "FieldTimer.h"

class WifiScanner
{
public:
    struct NetInfo
    {
        std::string ssid;
        std::string mac;
        int32_t rssi;
        int32_t channel;
        std::string encryptionType;
    };

    WifiScanner();

    void DoScan();
    const NetInfo& GetNetInfo( int idx );
    int GetNetCount();

private:
    int mNetworkCount;

    std::string GetEncryptionString( int type );
    NetInfo mNetInfo;
    std::vector<NetInfo> mNetworks;
};
