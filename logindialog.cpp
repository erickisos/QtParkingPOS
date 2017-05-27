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
    delete _db;
    delete ui;
}

void LoginDialog::setDatabase(QString &path)
{
    _db = new DBManager(path);
}

void LoginDialog::on_okButton_clicked()
{
    if(!_db->isOpen())
    {
        qWarning() << "Database is not opened on acceptClicked";
        if(!_db->open())
        {
            qWarning() << "Database couldn't be opened! " << _db->lastError();
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
        if(_db->userExists(user))
        {
            QUserData data;
            data = _db->getUserData(user);
            if(data.password == password)
            {
                qDebug() << "Password is same, good job!";
            }
            else
            {
                qDebug() << "That's a wrong pssword!";
            }
        }
    }
}
