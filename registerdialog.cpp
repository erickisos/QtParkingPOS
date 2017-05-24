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
    if(!_db.isOpen())
    {
        qWarning() << "Database is not opened on acceptClicked";
        if(!_db.open())
        {
            qWarning() << "Database couldn't be opened!: " << _db.lastError().text();
            return;
        }
    }
    if(ui->passwordLEdit->text().length() < 4)
    {
        qDebug() << "La contraseña es muy corta!";
        QMessageBox msb;
        msb.setIcon(QMessageBox::Warning);
        msb.setText("Por favor, ingrese una contraseña con 4 o más dígitos.");
        msb.setStandardButtons(QMessageBox::Ok);
        msb.exec();
    }
    else if(ui->usernameLEdit->text().length() < 4)
    {
        qDebug() << "El nombre de usuario es muy corto!";
        QMessageBox msb;
        msb.setIcon(QMessageBox::Warning);
        msb.setText("Por favor ingrese un nombre de usuario con 4 o más digitos!");
        msb.setStandardButtons(QMessageBox::Ok);
        msb.exec();
    }
    else
    {
        QString user, password;
        QSqlQuery _query;
        user = ui->usernameLEdit->text();
        password = ui->passwordLEdit->text();
        try
        {
            _query.prepare("SELECT * FROM LOGIN WHERE USERNAME = (:usname)");
            _query.bindValue(":usname", user);
            if(!_query.exec())
            {
                qDebug() << "Executing Query";
                _query.prepare("INSERT INTO LOGIN(USERNAME, PASSWORD) VALUES(:username, :passwd)");
                _query.bindValue(":username", user);
                _query.bindValue(":passwd", password);
                bool resultado = _query.exec();
                qDebug() << "Result from Insert: " << resultado;
                if(!resultado)
                    qWarning() << _query.lastError().text();
            }
            else
            {
                qDebug() << _db.lastError().text();
                QMessageBox msb;
                msb.setIcon(QMessageBox::Critical);
                msb.setText("El nombre de usuario ya ha sido elegido con anterioridad, reemplazelo e intentelo nuevamente!");
                msb.setStandardButtons(QMessageBox::Ok);
                msb.exec();
            }
        }
        catch(std::exception& ex)
        {
            qDebug() << _db.lastError().text();
            QMessageBox msb;
            msb.setIcon(QMessageBox::Critical);
            msb.setText(ex.what());
            msb.setStandardButtons(QMessageBox::Ok);
            msb.exec();
        }
        this->close();
    }
}
