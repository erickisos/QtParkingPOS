#ifndef QLOGINDIALOG
#define QLOGINDIALOG

#include <QDialog>
#include <QDebug>
#include <QDatabaseManager.h>

namespace Ui {
class QLoginDialog;
}

class QLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QLoginDialog(QWidget *parent = 0);
    void setDatabaseManager(QDatabaseManager& db);
    void setSessionString(QString& s);
    void setLoginName(QString& n);
    ~QLoginDialog();

    QString name;
    QString pass;
    QString mode;

private slots:
    void on_aceptarPButton_clicked();

    void on_aceptarPButton_released();

private:
    Ui::QLoginDialog *ui;
    QDatabaseManager* _db;
    QString* _s;
    QString* _n;
};

#endif // QLOGINDIALOG
