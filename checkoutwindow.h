#ifndef CHECKOUTWINDOW_H
#define CHECKOUTWINDOW_H

#include <QMainWindow>
#include <QDatabaseManager.h>

namespace Ui {
class CheckoutWindow;
}

class CheckoutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckoutWindow(QWidget *parent = 0);
    void setDatabaseManager(QDatabaseManager& db);
    ~CheckoutWindow();

private:
    Ui::CheckoutWindow *ui;
    QDatabaseManager* _db;
};

#endif // CHECKOUTWINDOW_H
