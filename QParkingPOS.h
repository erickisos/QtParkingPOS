#ifndef QPARKINGPOS_H
#define QPARKINGPOS_H

#include <QAboutDialog.h>
#include <QLoginDialog.h>
#include <QRegisterDialog.h>
#include <QDatabaseManager.h>


class QParkingPOS
{
public:
    QParkingPOS();
    ~QParkingPOS();
private:
    QLoginDialog _log;
    QRegisterDialog _reg;
};

#endif // QPARKINGPOS_H
