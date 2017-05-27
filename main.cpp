#include "checkinwindow.h"
#include "checkoutwindow.h"

#include <QLoginDialog.h>
#include <QAboutDialog.h>
#include <QRegisterDialog.h>
#include <QDatabaseManager.h>

#include <QApplication>
#include <QSplashScreen>
#include <QDir>

QString admin = "ROOT";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap splash_pixmap(":/images/splash");
    QSplashScreen splash(splash_pixmap);
    splash.show();
    a.processEvents();
    splash.showMessage("Starting Database connections...");
    QString database_name = qApp->applicationDirPath()
            + QDir::separator()
            + "POS.db";
    QDatabaseManager db(database_name);

    splash.showMessage("Starting application...");
    QRegisterDialog r;
    QLoginDialog l;

    qDebug() << "initAllTables: " << db.initAllTables();

    splash.showMessage("initializing database manager...");
    r.setDatabaseManager(db);
    l.setDatabaseManager(db);
    splash.finish(&l);
    if(!db.userExist(admin))
    {
        qDebug() << "User ROOT doesn't exist!";
        r.show();
    }

    l.show();

    return a.exec();
}
