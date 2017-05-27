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
        logindialog.cpp \
    checkoutwindow.cpp \
    checkinwindow.cpp \
    aboutdialog.cpp \
    paydialog.cpp \
    dbmanager.cpp \
    QDatabaseManager.cpp \
    QRegisterDialog.cpp \
    QAboutDialog.cpp \
    QLoginDialog.cpp

HEADERS  += logindialog.h \
    checkoutwindow.h \
    checkinwindow.h \
    aboutdialog.h \
    paydialog.h \
    dbmanager.h \
    QDatabaseManager \
    QRegisterDialog \
    QAboutDialog \
    QLoginDialog

FORMS    += logindialog.ui \
    checkoutwindow.ui \
    checkinwindow.ui \
    aboutdialog.ui \
    paydialog.ui \
    QRegisterDialog.ui \
    QAboutDialog.ui \
    QLoginDialog.ui

RESOURCES += \
    parking_pos.qrc
