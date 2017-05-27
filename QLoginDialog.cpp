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
        qDebug() << "User exist: " << mode;
    }
    else
    {
        qDebug() << "User doesn't exist";
    }
}
