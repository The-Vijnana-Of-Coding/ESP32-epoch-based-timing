#include <Arduino.h>

// private libs
#include <Timing.h>

//#####  main Setup  ######//
void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    rtc.setTime(0, 0, 0, 1, 1, 2022); //(sec,min,hr,day,month,year)
}
//////////////////////////////////////////////////////////////////////////

//#####  main Loop  ######//
void loop() {
    // put your main code here, to run repeatedly:
    mainTiming();
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
