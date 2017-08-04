TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += \
    ../

SOURCES += \
    ../esp8266wifihandler.cpp \
    ../esp8266serialhandler.cpp

HEADERS += \
    ../esp8266wifihandler.h \
    ../esp8266serialhandler.h
