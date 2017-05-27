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
    checkoutwindow.cpp \
    checkinwindow.cpp \
    QDatabaseManager.cpp \
    QRegisterDialog.cpp \
    QAboutDialog.cpp \
    QLoginDialog.cpp \
    QParkingPOS.cpp

HEADERS  += \
    checkoutwindow.h \
    checkinwindow.h \
    QAboutDialog.h \
    QDatabaseManager.h \
    QLoginDialog.h \
    QRegisterDialog.h \
    QParkingPOS.h

FORMS    += \
    checkoutwindow.ui \
    checkinwindow.ui \
    QRegisterDialog.ui \
    QAboutDialog.ui \
    QLoginDialog.ui

RESOURCES += \
    parking_pos.qrc \
    images.qrc
