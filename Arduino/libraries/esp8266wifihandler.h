/**
  * \file
  * \brief      Header file of esp8266wifihandler library.
  * \details    This library provides facilities for handling the WiFi with the ESP8266 device.
  *             One aim is to put an effort on producing efficient code once for all and then to provide an easy interface for the user.
  *             Another aim is to demonstrate a possible way of programming the ESP8266, for learning purpose.
  *             Literate programming from Donald E. Knuth shall be used in order to generate a clean and efficient code.
  *             For unavoidable comments, Doxygen standard shall be used.
  * \author     Arkh42 (Alexandre Quenon)
  * \version    0.0
  * \date       Created on 2017-08-04
  * \date       Last update on 2017-08-04
  * \copyright  GNU GPL V3
  */



#ifndef ESP8266WIFIHANDLER_H
#define ESP8266WIFIHANDLER_H



#include "Arduino.h"        // Mandatory to create an Arduino-compatible library
#include "ESP8266WiFi.h"    // Dedicated library for using WiFi with ESP8266


class ESP8266WiFiHandler{

public:
    ESP8266WiFiHandler();

};



#endif // ESP8266WIFIHANDLER_H
