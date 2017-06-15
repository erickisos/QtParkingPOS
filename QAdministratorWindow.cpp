#include "QAdministratorWindow.h"
#include "ui_QAdministratorWindow.h"

QAdministratorWindow::QAdministratorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QAdministratorWindow)
{
    ui->setupUi(this);
}

QAdministratorWindow::~QAdministratorWindow()
{
    delete ui;
}

void QAdministratorWindow::on_addPButton_released()
{
    QString user, pass, pass_con;
    user = ui->userLEdit->text();
    pass = ui->passLEdit->text();
    pass_con = ui->conpassLEdit->text();
    if(pass == pass_con)
    {
        qDebug() << "Passwords are equals";
        if(_db->userExist(user))
        {
            qDebug() << "userExist error: el usuario ha sido registrado anteriormente";
        }
        else
        {
            qDebug() << "addUser: "
                     << _db->addUser(user, pass);
            ui->userLEdit->clear();
            ui->passLEdit->clear();
            ui->conpassLEdit->clear();
        }
    }
    else
    {
        qDebug() << "passwords are differents, try again";
    }
}

void QAdministratorWindow::setDatabaseManager(QDatabaseManager &db)
{
    _db = &db;
}


