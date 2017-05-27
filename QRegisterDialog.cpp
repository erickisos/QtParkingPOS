#include "QRegisterDialog"
#include "ui_QRegisterDialog.h"

QRegisterDialog::QRegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRegisterDialog)
{
    ui->setupUi(this);
}

QRegisterDialog::~QRegisterDialog()
{
    delete ui;
}

void QRegisterDialog::setDatabaseManager(QDatabaseManager &db)
{
    _db = &db;
}

void QRegisterDialog::on_aceptarPButton_clicked()
{
    QString user, pass, pass_con;
    user = ui->userLEdit->text();
    pass = ui->passLEdit->text();
    pass_con = ui->passConLEdit->text();
    if(pass == pass_con)
    {
        qDebug() << "Passwords are  equals";
        if(_db->userExist(user))
        {
            qDebug() << "userExist error: el usuario ya existe!";
        }
        else
        {
            qDebug() << "addUser: "
                     << _db->addUser(user, pass);
            this->close();
        }
    }
    else
    {
        qDebug() << "passwords are differents, try again";
    }
}
