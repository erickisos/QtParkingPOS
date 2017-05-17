#ifndef CHECKOUTWINDOW_H
#define CHECKOUTWINDOW_H

#include <QMainWindow>

namespace Ui {
class CheckoutWindow;
}

class CheckoutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckoutWindow(QWidget *parent = 0);
    ~CheckoutWindow();

private:
    Ui::CheckoutWindow *ui;
};

#endif // CHECKOUTWINDOW_H
