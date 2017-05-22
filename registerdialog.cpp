#include "registerdialog.h"
#include "ui_registerdialog.h"

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::lockUsername()
{
    ui->usernameLEdit->setEnabled(false);
}

void registerDialog::unlockUsername()
{
    ui->usernameLEdit->setEnabled(true);
}

void registerDialog::setMessage(QString message)
{
    ui->messageLabel->setText(message);
}

void registerDialog::setDefaultUsername(QString username)
{
    ui->usernameLEdit->setText(username);
}

void registerDialog::setDefaultPassword(QString psswd)
{
    ui->passwordLEdit->setText(psswd);
}

void registerDialog::setDatabase(QSqlDatabase &db)
{
    _db = db;
}

void registerDialog::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->passwordLEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->passwordLEdit->setEchoMode(QLineEdit::Password);
    }
}

void registerDialog::on_acceptButton_clicked()
{
    if(ui->usernameLEdit->text().length() < 4)
    {
        QMessageBox msb;
        msb.setIcon(QMessageBox::Warning);
        msb.setText("Por favor, ingrese una contraseña con 4 o más dígitos.");
        msb.setStandardButtons(QMessageBox::Ok);
        msb.exec();
    }
    else
    {
        QString user, password;
        user = ui->usernameLEdit->text();
        password = ui->passwordLEdit->text();
        try
        {
            if(!_query.exec("IF(EXISTS(SELECT * FROM LOGIN WHERE USERNAME = '" + user + "'))"))
            {
                _query.exec("INSERT INTO LOGIN(USERNAME, PASSWORD) VALUES('" + user + "', '" + password + "'");
            }
            else
            {
                //qDebug() << _db.lastError().text();
                QMessageBox msb;
                msb.setIcon(QMessageBox::Critical);
                msb.setText("El nombre de usuario ya ha sido elegido con anterioridad, reemplazelo e intentelo nuevamente!");
                msb.setStandardButtons(QMessageBox::Ok);
                msb.exec();
            }
        }
        catch(std::exception& ex)
        {
            //qDebug() << _db.lastError().text();
            QMessageBox msb;
            msb.setIcon(QMessageBox::Critical);
            msb.setText(ex.what());
            msb.setStandardButtons(QMessageBox::Ok);
            msb.exec();
        }
    }
}
