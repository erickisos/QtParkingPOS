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
QString database_name = "pos.db";

bool executeQuery(QSqlDatabase& db, QString& unit_query)
{
    QSqlQuery query;
    if(!db.isOpen())
    {
        qWarning() << "Database wasn't opened yet";
        if(!db.open())
        {
            qWarning() << "Error opening db: " << db.lastError().text();
            return false;
        }
        qDebug() << "Database Opened!";
    }
    return query.exec(unit_query);
}

bool startDatabase(QString& name, QSqlDatabase& sdb)
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

void startAllTables(QSqlDatabase& sdb)
{
    QString ventas = "CREATE TABLE IF NOT EXISTS VENTAS("
                        "FOLIO VARCHAR(18) PRIMARY KEY NOT NULL,"
                        "HORA VARCHAR(5) NOT NULL,"
                        "FECHA DATE NOT NULL,"
                        "BOLETERA CHAR(1) NOT NULL,"
                        "TIPO INTEGER NOT NULL,"
                        "COSTO REAL NOT NULL"
                     ");";
    QString costos = "CREATE TABLE IF NOT EXISTS COSTOS("
                        "TIPO INTEGER PRIMARY KEY,"
                        "COSTO REAL NOT NULL,"
                        "TOLERANCIA INTEGER"
                     ");";
    QString login = "CREATE TABLE IF NOT EXISTS LOGIN("
                        "USERNAME VARCHAR(8) PRIMARY KEY,"
                        "PASSWORD VARCHAR(8) NOT NULL"
                    ");";
    QString tickets = "CREATE TABLE IF NOT EXISTS TICKETS("
                        "FOLIO VARCHAR(8) PRIMARY KEY,"
                        "HORA VARCHAR(5) NOT NULL,"
                        "FECHA DATE NOT NULL"
                      ");";

    try
    {
        sdb.open();
        qDebug() << executeQuery(sdb, ventas);
        qDebug() << executeQuery(sdb, costos);
        qDebug() << executeQuery(sdb, login);
        qDebug() << executeQuery(sdb, tickets);

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

void checkAdministrator(QSqlDatabase& sdb)
{
    QSqlQuery query;
    if(!sdb.isOpen())
    {
        qDebug() << "Database isnt opened yet";
        if(!sdb.open())
        {
            qWarning() << "Database couldn't be opened!!: " << sdb.lastError().text();
            return;
        }
    }
    query.prepare("SELECT USERNAME FROM LOGIN WHERE USERNAME = (:usn)))");
    query.bindValue(":usn", "ROOT");
    bool result = query.exec();
    qDebug() << "Result from Exist checking: " << result;
    qDebug() << "Rows Affected: " << query.numRowsAffected();
    if(query.numRowsAffected() < 1)
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
    if(!startDatabase(database_name, sdb))
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
        startAllTables(sdb);
        checkAdministrator(sdb);
        LoginDialog ldial;
        ldial.show();
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
