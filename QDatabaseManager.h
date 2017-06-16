#ifndef QDATABASEMANAGER
#define QDATABASEMANAGER

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>

/*
 * La estructura del ticket será:
 * A 012345678 2359 1211
 * PdV -> A
 * Folio -> 012345678
 * Hora -> 2359
 * Fecha -> 1211
 *
 */

const QString ventas = "CREATE TABLE IF NOT EXISTS VENTAS("
                       "INDICE INTEGER PRIMARY KEY NOT NULL,"
                       "FOLIO VARCHAR(18) NOT NULL,"
                       "HORA VARCHAR(5) NOT NULL,"
                       "FECHA DATE NOT NULL,"
                       "BOLETERA CHAR(1) NOT NULL,"
                       "TIPO INTEGER NOT NULL,"
                       "COSTO REAL NOT NULL,"
                       "VENDEDOR VARCHAR(8) NOT NULL);";
const QString costos = "CREATE TABLE IF NOT EXISTS COSTOS("
                       "TIPO INTEGER PRIMARY KEY,"
                       "COSTO REAL NOT NULL,"
                       "TOLERANCIA INTEGER);";
const QString login = "CREATE TABLE IF NOT EXISTS LOGIN("
                      "USERNAME VARCHAR(8) PRIMARY KEY,"
                      "PASSWORD VARCHAR(8) NOT NULL);";
const QString tickets = "CREATE TABLE IF NOT EXISTS BOLETERA("
                        "FOLIO VARCHAR(8) PRIMARY KEY,"
                        "HORA VARCHAR(5) NOT NULL,"
                        "FECHA DATE NOT NULL);";
const QString sesion = "CREATE TABLE IF NOT EXISTS SESION("
                       "INDEX INTEGER PRIMARY KEY NOT NULL,"
                       "USERNAME VARCHAR(8) NOT NULL,"
                       "HORA VARCHAR(5) NOT NULL,"
                       "FECHA DATE NOT NULL);";
const QString corte = "CREATE TABLE IF NOT EXISTS CORTE("
                      "FOLIO VARCHAR(8) PRIMARY KEY NOT NULL,"
                      "HORA VARCHAR(5) NOT NULL,"
                      "FECHA DATE NOT NULL,"
                      "TOTAL REAL NOT NULL"
                      ");";

const QString DRIVER = "QSQLITE";

typedef struct
{
    QString username;
    QString password;
} QUserData;

typedef struct
{
    QString folio;
    QString hora;
    QString fecha;
    QString total;
} QCorteData;

typedef QVector<QCorteData> QCorteSet;

class QDatabaseManager
{
public:
    QDatabaseManager(QString& path);
    ~QDatabaseManager();
    bool isOpen() const;
    bool open();
    void close();
    bool executeQuery(const QString& s_query);
    bool addUser(const QString& name, const QString& pass);
    bool deleteUser(const QString& name);
    bool userExist(const QString& name) const;
    bool addTicketToDatabase(const QString& serial);
    bool initAllTables();
    QUserData getUserData(const QString& username);
    QCorteSet getCortes();
    QSqlError lastError() const;
    QSqlDatabase m_db;
private:
    QDate _date;
};

#endif // QDATABASEMANAGER
