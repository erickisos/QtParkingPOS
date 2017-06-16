#include "checkoutwindow.h"

#include <QLoginDialog.h>
#include <QAboutDialog.h>
#include <QRegisterDialog.h>
#include <QDatabaseManager.h>
#include <QCheckInWindow.h>
#include <QCheckOutWindow.h>
#include <QParkingSplashscreen.h>
#include <QAdministratorWindow.h>

#include <QApplication>
#include <QSplashScreen>
#include <QDir>

QString admin = "ROOT";
QString session;
QString l_name;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap splash_pixmap(":/images/splash");
    QSplashScreen splash(splash_pixmap);

    splash.show();

    //ps.show();

    a.processEvents();
    splash.showMessage("Starting Database connections...", Qt::AlignLeft | Qt::AlignTop);
    QString database_name = qApp->applicationDirPath()
            + QDir::separator()
            + "POS.db";
    QDatabaseManager db(database_name);

    splash.showMessage("Starting application...", Qt::AlignLeft | Qt::AlignTop);

    QLoginDialog l;
    QRegisterDialog r;
    QCheckInWindow i;
    QCheckOutWindow o;
    QAdministratorWindow adminWindow;

    qDebug() << "initAllTables: " << db.initAllTables();

    splash.showMessage("Initializing database manager...", Qt::AlignLeft | Qt::AlignTop);
    r.setDatabaseManager(db);
    l.setDatabaseManager(db);
    i.setDatabaseManager(db);
    o.setDatabaseManager(db);
    adminWindow.setDatabaseManager(db);

    l.setSessionString(session);
    l.setLoginName(l_name);

    splash.finish(&l);
    while(!db.userExist(admin))
    {
        qDebug() << "User ROOT doesn't exist!";
        r.exec();
    }
    l.exec();
    qDebug() << "Esta es la salida seleccionada: " << session;
    if(session == "Caseta")
    {
        o.show();
    }
    else if(session == "Boletera")
    {
        i.show();
    }
    else if(session == "Administrador")
    {
        adminWindow.show();
    }
    return a.exec();
}
