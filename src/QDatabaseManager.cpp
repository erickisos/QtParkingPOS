#include "QDatabaseManager.h"

QDatabaseManager::QDatabaseManager()
{

}

//QDatabaseManager::QDatabaseManager(QString& path)
QDatabaseManager::QDatabaseManager(QString driver, QString hostname, QString username, QString password, QString db_name)
{
    m_db = QSqlDatabase::addDatabase(driver);
    m_db.setHostName(hostname);
    m_db.setDatabaseName(db_name);
    m_db.setUserName(username);
    m_db.setPassword(password);
    /*
    m_db = QSqlDatabase::addDatabase(DRIVER);
    m_db.setDatabaseName(path);
    */
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
    QString folio, hora, fecha;
    folio = serial_number;
    hora = serial_number.mid(10, 2) + ":" + serial_number.mid(12, 2);
    fecha = serial_number.mid(14, 2) +
            "/" +
            serial_number.mid(16, 2) +
            "/" +
            QString::number(_date.year());
    qDebug() << "Folio: " << folio;
    qDebug() << "Hora: " << hora;
    qDebug() << "Fecha: " << fecha;
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
        qDebug() << "init cortes table:"
                 << executeQuery(corte);
        qDebug() << "init sesion table:"
                 << executeQuery(sesion);
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

QCorteSet QDatabaseManager::getCortes()
{
    QCorteSet cortes;
    QSqlQuery query;
    query.prepare("SELECT * FROM CORTE");
    if(query.exec())
    {
        while(query.next())
        {
            QCorteData data;
            data.folio = query.value("FOLIO").toString();
            data.fecha = query.value("FECHA").toString();
            data.hora = query.value("HORA").toString();
            data.total = query.value("TOTAL").toString();
            cortes.append(data);
        }
    }
    return cortes;
}

bool QDatabaseManager::registerLogin(const QString& user)
{
    bool success = false;
    QString fecha;
    QString hora;
    int indice = 0;
    int an_index = 0;
    if(this->userExist(user))
    {
        QSqlQuery query;
        query.exec("SELECT INDICE FROM SESION");
        qDebug() << "Elementos retornados: " << query.size();
        while(query.next())
        {
            an_index++;
            indice = query.value("INDICE").toInt();
        }
        query.prepare("INSERT INTO SESION(INDICE, USERNAME, HORA, FECHA) VALUES(:idx, :usn, :hra, :fecha)");
        qDebug() << "Current date: " << _date.currentDate().toString("dd/MM/yyyy");
        qDebug() << "Current Time: " << _time.currentTime().toString("HH:mm");
        qDebug() << "Last index readed: " << indice;
        qDebug() << "Last index counted: " << an_index;
        fecha = _date.currentDate().toString("dd/MM/yyyy");
        hora = _time.currentTime().toString("HH:mm");
        query.bindValue(":idx", indice + 1);
        query.bindValue(":usn", user);
        query.bindValue(":hra", hora);
        query.bindValue(":fecha", fecha);
        return query.exec();
    }
    return success;
}
