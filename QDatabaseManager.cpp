#include "QDatabaseManager"

QDatabaseManager::QDatabaseManager(QString& path)
{
    m_db = QSqlDatabase::addDatabase(DRIVER);
    m_db.setDatabaseName(path);
    if(!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
        qDebug() << "Error:"
                 << m_db.lastError();
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

QDatabaseManager::~QDatabaseManager()
{
    if(m_db.isOpen())
    {
        m_db.close();
    }
}

bool QDatabaseManager::isOpen() const
{
    return m_db.isOpen();
}

bool QDatabaseManager::open()
{
    return m_db.open();
}

void QDatabaseManager::close()
{
    m_db.close();
}

bool QDatabaseManager::addUser(const QString& name, const QString& password)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO LOGIN(USERNAME, PASSWORD) VALUES(:user, :pass);");
    query.bindValue(":user", name);
    query.bindValue(":pass", password);
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addUser error:"
                 << query.lastError();
    }
    return success;
}

bool QDatabaseManager::deleteUser(const QString &name)
{
    QSqlQuery query;
    bool success = false;
    if(userExist(name))
    {
        query.prepare("DELETE FROM LOGIN WHERE USERNAME = (:user)");
        query.bindValue(":user", name);
        success = query.exec();
        if(!success)
        {
            qDebug() << "deleteUser error:"
                     << query.lastError();
        }
    }
    return success;
}

bool QDatabaseManager::userExist(const QString &name) const
{
    bool exist = false;
    QSqlQuery query;
    query.prepare("SELECT USERNAME FROM LOGIN WHERE USERNAME = (:user)");
    query.bindValue(":user", name);
    if(query.exec())
    {
        if(query.next())
        {
            exist = true;
        }
    }
    else
    {
        qDebug() << "userExist error:"
                 << query.lastError();
    }
    return exist;
}

bool QDatabaseManager::addTicketToDatabase(const QString &serial_number)
{
    bool success = false;
    return success;
}

bool QDatabaseManager::executeQuery(const QString &s_query)
{
    QSqlQuery query;
    return query.exec(s_query);
}

bool QDatabaseManager::initAllTables()
{
    bool success = false;
    try
    {
        qDebug() << "init ventas table:"
                 << executeQuery(ventas);
        qDebug() << "init costos table:"
                 << executeQuery(costos);
        qDebug() << "init login table:"
                 << executeQuery(login);
        qDebug() << "init tickets table:"
                 << executeQuery(tickets);
        success = true;
    }
    catch(std::exception& ex)
    {
        qDebug() << "initAllTables error:"
                 << lastError();
    }
    return success;
}

QUserData QDatabaseManager::getUserData(const QString &username)
{
    QUserData data;
    data.username = "";
    data.password = "";
    if(userExist(username))
    {
        QSqlQuery query;
        query.prepare("SELECT USERNAME, PASSWORD FROM LOGIN WHERE USERNAME = (:user)");
        query.bindValue(":user", username);
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
            qDebug() << "getUserData error:"
                     << query.lastError();
        }
    }
    return data;
}

QSqlError QDatabaseManager::lastError() const
{
    return m_db.lastError();
}
