#-------------------------------------------------
#
# Project created by QtCreator 2019-11-27T10:10:10
#
#-------------------------------------------------

QT += core gui
QT += core
QT += network
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BottleStopQT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        beverage.cpp \
        main.cpp \
        mainwindow.cpp \
        mixratio.cpp \
        pump.cpp \
        devicemanager.cpp \
        RFID/bottlehandler.cpp \
        RFID/serialwrapper.cpp \
        RFID/user.cpp \
        RFID/bottle.cpp \
        beveragefactory.cpp \
        RFID/bottlestate.cpp \
        apiservice.cpp \
        RFID/bottlesignals.cpp \
        staticscreensaver.cpp \
        uimanager.cpp

HEADERS += \
        beverage.h \
        mainwindow.h \
        mixratio.h \
        pump.h \
        devicemanager.h \
        RFID/bottlehandler.h \
        RFID/serialwrapper.h \
        RFID/user.h \
        RFID/bottle.h \
        beveragefactory.h \
        RFID/bottlestate.h \
        apiservice.h \
        RFID/bottlesignals.h \
        staticscreensaver.h \
        uimanager.h


FORMS += \
        mainwindow.ui \
        staticscreensaver.ui

DISTFILES += \
    tmp


    INCLUDEPATH += /opt/qt5pi/sysroot/usr/include
    LIBS += -L/opt/qt5pi/sysroot/usr/lib -lwiringPi

    DEFINES += WIRING_PI

    target.path = /home/pi
    INSTALLS += target


DISTFILES += \
    tmp \
    FontLoader.qml

RESOURCES += \
    Images/mainpage.qrc \
    customfonts.qrc

