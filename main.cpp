#include "checkoutwindow.h"

#include <QLoginDialog.h>
#include <QAboutDialog.h>
#include <QRegisterDialog.h>
#include <QDatabaseManager.h>
#include <QCheckInWindow.h>
#include <QCheckOutWindow.h>
#include <QParkingSplashscreen.h>

#include <QApplication>
#include <QSplashScreen>
#include <QDir>

QString admin = "ROOT";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap splash_pixmap(":/images/splash");
    QSplashScreen splash(splash_pixmap);
    QParkingSplashscreen ps;

    splash.show();

    ps.show();

    a.processEvents();
    splash.showMessage("Starting Database connections...", Qt::AlignLeft | Qt::AlignTop, Qt::white);
    QString database_name = qApp->applicationDirPath()
            + QDir::separator()
            + "POS.db";
    QDatabaseManager db(database_name);

    splash.showMessage("Starting application...", Qt::AlignLeft | Qt::AlignTop, Qt::white);
    QRegisterDialog r;
    QLoginDialog l;
    QCheckInWindow i;
    QCheckOutWindow o;

    qDebug() << "initAllTables: " << db.initAllTables();

    splash.showMessage("Initializing database manager...", Qt::AlignLeft | Qt::AlignTop, Qt::white);
    r.setDatabaseManager(db);
    l.setDatabaseManager(db);
    i.setDatabaseManager(db);
    o.setDatabaseManager(db);
    splash.finish(&l);
    if(!db.userExist(admin))
    {
        qDebug() << "User ROOT doesn't exist!";
        r.show();
    }

    l.show();
    return a.exec();
}
