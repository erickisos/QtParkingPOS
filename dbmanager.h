#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>

typedef struct
{
    QString username;
    QString password;
} QUserData;

class DBManager
{
public:
    DBManager(const QString& path);
    ~DBManager();
    bool isOpen();
    bool open();
    QSqlError lastError() const;
    bool createTable(const QString& name, QVector<QString>& fields);
    bool addUser(const QString& name, const QString& password);
    bool deleteUser(const QString& name);
    bool userExists(const QString& name) const;
    bool addTicketToDatabase(const QString& serial_number);
    QUserData& getUserData(const QString& username);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
