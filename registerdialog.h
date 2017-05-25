#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <dbmanager.h>

namespace Ui {
class registerDialog;
}

class registerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = 0);
    void setDatabase(QString& path);
    void setMessage(QString message);
    void setDefaultUsername(QString username);
    void setDefaultPassword(QString psswd);
    void lockUsername();
    void unlockUsername();
    ~registerDialog();

private slots:
    void on_checkBox_toggled(bool checked);

    void on_acceptButton_clicked();

private:
    DBManager* _db;
    Ui::registerDialog *ui;
};

#endif // REGISTERDIALOG_H
