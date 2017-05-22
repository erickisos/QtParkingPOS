#include "logindialog.h"
#include "checkinwindow.h"
#include "checkoutwindow.h"
#include "aboutdialog.h"
#include "registerdialog.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

QString creator = "CREATE TABLE IF NOT EXISTS VENTAS("
                  "FOLIO VARCHAR(18) PRIMARY KEY NOT NULL,"
                  "HORA VARCHAR(5) NOT NULL,"
                  "FECHA DATE NOT NULL,"
                  "BOLETERA CHAR(1) NOT NULL,"
                  "TIPO INTEGER NOT NULL,"
                  "COSTO REAL NOT NULL"
                  ");"
                  "CREATE TABLE IF NOT EXISTS COSTOS("
                  "TIPO INTEGER PRIMARY KEY,"
                  "COSTO REAL NOT NULL,"
                  "TOLERANCIA INTEGER"
                  ");"
                  "CREATE TABLE IF NOT EXISTS LOGIN("
                  "USERNAME VARCHAR(8) PRIMARY KEY,"
                  "PASSWORD VARCHAR(8) NOT NULL"
                  ");"
                  "CREATE TABLE IF NOT EXISTS TICKETS("
                  "FOLIO VARCHAR(8) PRIMARY KEY,"
                  "HORA VARCHAR(5) NOT NULL,"
                  "FECHA DATE NOT NULL"
                  ");";

const QString DRIVER("QSQLITE");


bool startDatabase(QString name, QSqlDatabase& sdb)
{
    if(QSqlDatabase::isDriverAvailable(DRIVER))
    {
        sdb = QSqlDatabase::addDatabase(DRIVER);
        sdb.setDatabaseName(qApp->applicationDirPath()
                            + QDir::separator()
                            + name);
        return sdb.open();
    }
    else
    {
        return false;
    }
}

void startAllTables(QSqlDatabase& sdb, QSqlQuery& query)
{
    try
    {
        sdb.open();
        query.exec(creator);
    }
    catch(std::exception& ex)
    {
        qDebug() << sdb.lastError().text();
        QMessageBox msb;
        msb.setIcon(QMessageBox::Critical);
        msb.setText(sdb.lastError().text());
        msb.setStandardButtons(QMessageBox::Ok);
        msb.exec();
    }
}

void checkAdministrator(QSqlQuery& query, QSqlDatabase& sdb)
{
    if(!query.exec("IF(EXISTS(SELECT * FROM LOGIN WHERE USERNAME = 'ROOT'))"))
    {
        registerDialog rd;
        rd.setDatabase(sdb);
        rd.setMessage("No se ha encontrado ninguna cuenta de Administrador, ingrese una contraseña para comenzar.");
        rd.setWindowTitle("ParkingPOS - Registro");
        rd.setDefaultUsername("ROOT");
        rd.lockUsername();
        rd.exec();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase sdb;
    QSqlQuery query;
    if(!startDatabase("pos.db", sdb))
    {
        qDebug() << sdb.lastError().text();
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText(sdb.lastError().text());
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        startAllTables(sdb, query);
        //checkAdministrator(query, sdb);
        //LoginDialog ldial;
        //ldial.show();
    }
    /*
    LoginDialog w;
    CheckinWindow v;
    CheckoutWindow x;
    AboutDialog ab;
    w.show();
    v.show();
    x.show();
    ab.show();
    */
    return a.exec();
}
