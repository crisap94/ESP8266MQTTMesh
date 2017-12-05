/* This header file defines compatible structs that are not present in ESP32 */
#ifndef _WIFI_COMPAT_
#define _WIFI_COMPAT_

#include <WiFi.h>

#define WIFI_DISCONNECT_REASON_ASSOC_TOOMANY WIFI_REASON_ASSOC_TOOMANY 
struct WiFiEventStationModeGotIP
{
    IPAddress ip;
    IPAddress mask;
    IPAddress gw;
};

struct WiFiEventStationModeDisconnected
{
    String ssid;
    uint8_t bssid[6];
    unsigned int reason;
};

/*
struct WiFiEventSoftAPModeStationConnected
{
    uint8_t mac[6];
    uint8_t aid;
};
*/
#define WiFiEventSoftAPModeStationConnected system_event_ap_staconnected_t
/*
struct WiFiEventSoftAPModeStationDisconnected
{
    uint8_t mac[6];
    uint8_t aid;
};
*/
#define WiFiEventSoftAPModeStationDisconnected system_event_ap_stadisconnected_t

#endif //_WIFI_COMPAT_
