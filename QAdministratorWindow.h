#ifndef QADMINISTRATORWINDOW_H
#define QADMINISTRATORWINDOW_H

#include <QMainWindow>
#include <QDatabaseManager.h>

namespace Ui {
class QAdministratorWindow;
}

class QAdministratorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QAdministratorWindow(QWidget *parent = 0);
    ~QAdministratorWindow();
    void setDatabaseManager(QDatabaseManager& db);

private slots:
    void on_addPButton_released();

private:
    QDatabaseManager* _db;
    Ui::QAdministratorWindow *ui;
};

#endif // QADMINISTRATORWINDOW_H
