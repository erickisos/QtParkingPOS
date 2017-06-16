#include "QLoginDialog.h"
#include "ui_QLoginDialog.h"

QLoginDialog::QLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QLoginDialog)
{
    ui->setupUi(this);
}

QLoginDialog::~QLoginDialog()
{
    delete ui;
}

void QLoginDialog::setDatabaseManager(QDatabaseManager &db)
{
    _db = &db;
}

void QLoginDialog::on_aceptarPButton_clicked()
{
    QString registered_password;
    this->name = ui->userLEdit->text();
    this->pass = ui->passLEdit->text();
    this->mode = ui->comboBox->currentText();
    if(_db->userExist(name))
    {
        _s->clear();
        _n->clear();
        registered_password = _db->getUserData(this->name).password;
        if(registered_password == this->pass)
        {
            qDebug() << "Modo seleccionado: " << mode;
            _s->append(mode);
            _n->append(name);
            if(this->name != "ROOT" && this->mode == "Administrador")
            {
                qDebug() << "No puede entrar en modo administrador sin ser ROOT";
            }
            else
            {
                _db->registerLogin(name);
                this->close();
            }
        }
        else
        {
            qDebug() << "La contraseña es incorrecta!";
        }
    }
    else
    {
        qDebug() << "User doesn't exist";
    }
}

void QLoginDialog::on_aceptarPButton_released()
{
    qDebug() << "Released!";
}

void QLoginDialog::setSessionString(QString &s)
{
    this->_s = &s;
}

void QLoginDialog::setLoginName(QString &n)
{
    this->_n = &n;
}
