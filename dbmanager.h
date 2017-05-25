#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QVector>
#include <QString>

class DBManager
{
public:
    DBManager(const QString& path);
    ~DBManager();
    bool isOpen();
    bool createTable(const QString& name, QVector<QString>& fields);
    bool addUser(const QString& name, const QString& password);
    bool deleteUser(const QString& name);
    bool personExists(const QString& name) const;
    bool addTicketToDatabase(const QString& serial_number);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
