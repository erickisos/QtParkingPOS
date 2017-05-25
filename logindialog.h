#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <dbmanager.h>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    void setDatabase(QString& path);
    ~LoginDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::LoginDialog *ui;
    DBManager* _db;
};

#endif // LOGINDIALOG_H
