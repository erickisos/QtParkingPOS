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
    QDatabaseManager.cpp \
    QRegisterDialog.cpp \
    QAboutDialog.cpp \
    QLoginDialog.cpp \
    QParkingPOS.cpp \
    QCheckInWindow.cpp \
    QCheckOutWindow.cpp \
    QCheckOutWindow.cpp

HEADERS  += \
    checkoutwindow.h \
    QAboutDialog.h \
    QDatabaseManager.h \
    QLoginDialog.h \
    QRegisterDialog.h \
    QParkingPOS.h \
    QCheckInWindow.h \
    QCheckOutWindow.h \
    QCheckOutWindow.h

FORMS    += \
    checkoutwindow.ui \
    QRegisterDialog.ui \
    QAboutDialog.ui \
    QLoginDialog.ui \
    QCheckInWindow.ui \
    QCheckOutWindow.ui \
    QCheckOutWindow.ui

RESOURCES += \
    parking_pos.qrc \
    images.qrc
