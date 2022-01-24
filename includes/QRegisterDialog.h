#ifndef QREGISTERDIALOG
#define QREGISTERDIALOG

#include <QDialog>
#include <QDatabaseManager.h>

namespace Ui {
class QRegisterDialog;
}

class QRegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QRegisterDialog(QWidget *parent = 0);
    void setDatabaseManager(QDatabaseManager& db);
    ~QRegisterDialog();

private slots:
    void on_aceptarPButton_clicked();

private:
    Ui::QRegisterDialog *ui;
    QDatabaseManager* _db;
};

#endif // QREGISTERDIALOG
