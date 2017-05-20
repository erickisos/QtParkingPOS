#include "logindialog.h"
#include "checkinwindow.h"
#include "checkoutwindow.h"
#include "aboutdialog.h"
#include <QApplication>
#include <sqlite3.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog w;
    CheckinWindow v;
    CheckoutWindow x;
    AboutDialog ab;
    w.show();
    v.show();
    x.show();
    ab.show();

    return a.exec();
}
