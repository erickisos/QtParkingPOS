#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setDatabase(QSqlDatabase& db)
{
    _db = db;
    _db.addDatabase("QSQLITE");
    _db.setDatabaseName(qApp->applicationDirPath()
                        + QDir::separator()
                        + "pos.db");
}

void LoginDialog::on_okButton_clicked()
{
    if(!_db.isOpen())
    {
        qWarning() << "Database is not opened on acceptClicked";
        if(!_db.open())
        {
            qWarning() << "Database couldn't be opened! " << _db.lastError();
            return;
        }
    }
    if(ui->usernameLEdit->text().length() < 1)
    {
        qDebug() << "Porfavor ingrese un nombre de usuario!";
        QMessageBox ms;
        ms.setIcon(QMessageBox::Warning);
        ms.setText("Ingrese un nombre de usuario!");
        ms.setStandardButtons(QMessageBox::Ok);
        ms.exec();
    }
    else if(ui->passwordLEdit->text().length() < 4)
    {
        qDebug() << "Porfavor ingrese su contraseña, esta debe poseer al menos 4 digitos y se generó cuando fue registrado en el sistema!";
        QMessageBox ms;
        ms.setIcon(QMessageBox::Warning);
        ms.setText("Porfavor ingrese su contraseña, esta debe poseer al menos 4 digitos y se generó cuando fue registrado en el sistema!");
        ms.setStandardButtons(QMessageBox::Ok);
        ms.exec();
    }
    else
    {
        QString user, password;
        user = ui->usernameLEdit->text();
        password = ui->passwordLEdit->text();
        QSqlQuery _query;
        _query.prepare("SELECT PASSWORD FROM LOGIN WHERE USERNAME = (:usn)");
        _query.bindValue(":usn", user);
        bool result = _query.exec();
        int row_count = 0;
        if(!result)
        {
            qWarning() << "Error with Database!" << _query.lastError().text();
            return;
        }
        else
        {
            _query.last();
            row_count = _query.at() + 1;
            qDebug() << "Query Count = " << row_count;
        }
        if(row_count < 1)
        {
            QMessageBox ms;
            ms.setIcon(QMessageBox::Warning);
            ms.setText("No se ha encontrado dicho nombre de usuario en los registros, contacte a su administrador de sistemas o inténtelo nuevamente!");
            ms.setWindowTitle("ParkingPOS - Error al iniciar sesión");
            ms.setStandardButtons(QMessageBox::Ok);
            ms.exec();
            return;
        }
        else
        {
            QString result_password;
            result_password = _query.value(0).toString();
            if(result_password == password)
            {
                qDebug() << "Anuma, así era la passwad";
                return;
            }
            else
            {
                qDebug() << "Te equivocaste en la contraseña mai";
                QMessageBox ms;
                ms.setIcon(QMessageBox::Warning);
                ms.setText("Contraseña ingresada es erronea!");
                ms.setStandardButtons(QMessageBox::Ok);
                ms.exec();
                return;
            }
        }
    }
}
