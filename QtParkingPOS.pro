#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T01:39:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += sql

TARGET = QtParkingPOS
TEMPLATE = app


SOURCES += main.cpp\
    QDatabaseManager.cpp \
    QRegisterDialog.cpp \
    QAboutDialog.cpp \
    QLoginDialog.cpp \
    QParkingPOS.cpp \
    QCheckInWindow.cpp \
    QCheckOutWindow.cpp \
    QParkingSplashscreen.cpp #\
    #QCustomSplash.cpp

HEADERS  += \
    QAboutDialog.h \
    QDatabaseManager.h \
    QLoginDialog.h \
    QRegisterDialog.h \
    QParkingPOS.h \
    QCheckInWindow.h \
    QCheckOutWindow.h \
    QParkingSplashscreen.h #\
    #QCustomSplash.h

FORMS    += \
    QRegisterDialog.ui \
    QAboutDialog.ui \
    QLoginDialog.ui \
    QCheckInWindow.ui \
    QCheckOutWindow.ui \
    QParkingSplashscreen.ui

RESOURCES += \
    parking_pos.qrc \
    images.qrc
