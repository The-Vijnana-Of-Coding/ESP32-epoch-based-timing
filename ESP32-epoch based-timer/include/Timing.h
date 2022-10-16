#include <Arduino.h>

// external libs
#include <ESP32Time.h>

// create rtc object
ESP32Time rtc;
// create prev_time variable
time_t prev_time = 0;

//#####  get RTC time and convert to epoch  ######//
time_t getTimeEpoch() { // create now epoch time
    struct tm timeNow = {0};
    timeNow.tm_year = rtc.getYear() - 1900; // This is year-1900
    timeNow.tm_mon = rtc.getMonth();
    timeNow.tm_mday = rtc.getDay();
    timeNow.tm_hour = rtc.getHour(true); // 24hr format
    timeNow.tm_min = rtc.getMinute();
    timeNow.tm_sec = rtc.getSecond();
    time_t timeNowEpoch = mktime(&timeNow);
    return timeNowEpoch;
}
//////////////////////////////////////////////////////////////////////////

//#####  mainTiming function  ######//
void mainTiming() {
    // add time specific tasks here
    // do something every 1 sec
    if (getTimeEpoch() - prev_time >= 1) {
        Serial.println("-------Time Now-------");
        Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S")); // (String) returns time with specified format
        Serial.println("----------------------");
        prev_time = getTimeEpoch();
    }
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
