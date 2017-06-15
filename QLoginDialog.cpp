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
    QString name, pass, mode;
    name = ui->userLEdit->text();
    pass = ui->passLEdit->text();
    mode = ui->comboBox->currentText();
    if(_db->userExist(name))
    {
        _s->clear();
        qDebug() << "User exist: " << mode;
        _s->append(mode);
        this->close();
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

QString& QLoginDialog::getSession(void)
{
    return this->session;
}

void QLoginDialog::setSessionString(QString &s)
{
    this->_s = &s;
}
