#ifndef CHECKOUTWINDOW_H
#define CHECKOUTWINDOW_H

#include <QMainWindow>
#include <dbmanager.h>

namespace Ui {
class CheckoutWindow;
}

class CheckoutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckoutWindow(QWidget *parent = 0);
    void setDatabase(QString& path);
    ~CheckoutWindow();

private:
    Ui::CheckoutWindow *ui;
    DBManager* _db;
};

#endif // CHECKOUTWINDOW_H
