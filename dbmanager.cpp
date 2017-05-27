#include "dbmanager.h"

DBManager::DBManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase(DRIVER);
    m_db.setDatabaseName(path);
    if(!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
        qDebug() << "Error:" << m_db.lastError();
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DBManager::~DBManager()
{
    if(m_db.isOpen())
    {
        m_db.close();
    }
}

QSqlError DBManager::lastError() const
{
    return m_db.lastError();
}

bool DBManager::open()
{
    return m_db.open();
}

bool DBManager::isOpen() const
{
    return m_db.isOpen();
}

void DBManager::close()
{
    m_db.close();
}

bool DBManager::createTable(const QString &name, QVector<QString> &fields)
{
    int data_fields = fields.length();
    bool success = false;
    QString full_query = "CREATE TABLE " + name + "(";
    for(int i = 0; i < data_fields; i++)
    {
        full_query += fields[i];
    }
    full_query += ");";
    QSqlQuery query;
    if(!query.exec(full_query))
    {
        qDebug() << "Couldn't create the table "
                 << name << ": one might already exist.";
        success = false;
    }
    else
    {
        success = true;
    }
    return success;
}

bool DBManager::addUser(const QString &name, const QString &password)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO LOGIN(USERNAME, PASSWORD) VALUES(:usn, :pss)");
    query.bindValue(":usn", name);
    query.bindValue(":pss", password);
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "AddPerson error:"
                 << query.lastError();
    }
    return success;
}

bool DBManager::deleteUser(const QString &name)
{
    QSqlQuery query;
    bool success = false;
    if(userExists(name))
    {
        query.prepare("DELETE FROM LOGIN WHERE USERNAME = (:name)");
        query.bindValue(":name", name);
        success = query.exec();
        if(!success)
        {
            qDebug() << "deleteUser error:"
                     << query.lastError();
        }
    }
    return success;
}

bool DBManager::userExists(const QString &name) const
{
    bool exists = false;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT USERNAME FROM LOGIN WHERE USERNAME = (:name)");
    checkQuery.bindValue(":name", name);
    if(checkQuery.exec())
    {
        if(checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "userExists failed:"
                 << checkQuery.lastError();
    }
    return exists;
}

bool DBManager::addTicketToDatabase(const QString &serial_number)
{
    QString folio, hora, fecha;
    folio = serial_number;
    hora = folio[0];
    fecha = folio[1];
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO TICKETS VALUE(:folio, :hora, :fecha)");
    query.bindValue(":folio", folio);
    query.bindValue(":hora", hora);
    query.bindValue(":fecha", fecha);
    if(query.exec())
    {
        qDebug() << "inserted ticket to database!";
        success = true;
    }
    else
    {
        qDebug() << "addTicketToDB ailed:"
                 << query.lastError();
    }
    return success;
}

QUserData& DBManager::getUserData(const QString &username)
{
    QUserData data;
    data.password = "";
    data.username = "";
    if(userExists(username))
    {
        QSqlQuery query;
        query.prepare("SELECT USERNAME, PASSWORD FROM LOGIN WHERE USERNAME = (:uname);");
        query.bindValue(":uname", username);
        if(query.exec())
        {
            if(query.next())
            {
                data.username = query.value(0).toString();
                data.password = query.value(1).toString();
            }
        }
        else
        {
            qDebug() << "getUserData failed:"
                     << query.lastError();
        }
    }
    return data;
}

