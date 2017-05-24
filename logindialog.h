#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    void setDatabase(QSqlDatabase& db);
    ~LoginDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::LoginDialog *ui;
    QSqlDatabase _db;
};

#endif // LOGINDIALOG_H
