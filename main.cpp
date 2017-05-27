#include "checkinwindow.h"
#include "checkoutwindow.h"

#include <QLoginDialog>
#include <QAboutDialog>
#include <QRegisterDialog>
#include <QDatabaseManager>

#include <QApplication>
#include <QDir>

QString database_name = qApp->applicationDirPath()
        + QDir::separator()
        + "POS.db";
QString admin = "ROOT";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDatabaseManager db(database_name);

    QRegisterDialog r;
    QLoginDialog l;

    qDebug() << "initAllTables: " << db.initAllTables();

    r.setDatabaseManager(db);
    l.setDatabaseManager(db);

    if(!db.userExist(admin))
    {
        QDebug() << "User ROOT doesn't exist!";
        r.show();
    }

    l.show();

    return a.exec();
}
