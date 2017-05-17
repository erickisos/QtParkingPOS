#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T01:39:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtParkingPOS
TEMPLATE = app


SOURCES += main.cpp\
        logindialog.cpp \
    checkoutwindow.cpp \
    checkinwindow.cpp \
    aboutdialog.cpp

HEADERS  += logindialog.h \
    checkoutwindow.h \
    checkinwindow.h \
    aboutdialog.h

FORMS    += logindialog.ui \
    checkoutwindow.ui \
    checkinwindow.ui \
    aboutdialog.ui
