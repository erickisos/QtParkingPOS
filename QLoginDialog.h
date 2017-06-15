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
    QString& getSession(void);
    void setSessionString(QString& s);
    ~QLoginDialog();

private slots:
    void on_aceptarPButton_clicked();

    void on_aceptarPButton_released();

private:
    Ui::QLoginDialog *ui;
    QDatabaseManager* _db;
    QString* _s;
    QString session;
};

#endif // QLOGINDIALOG
