#include "logindialog.h"
#include "checkinwindow.h"
#include "checkoutwindow.h"
#include <QApplication>
#include <sqlite3.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    CheckinWindow v;
    CheckoutWindow x;
    w.show();
    v.show();
    x.show();

    return a.exec();
}
