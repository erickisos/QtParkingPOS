#include "checkoutwindow.h"
#include "ui_checkoutwindow.h"

CheckoutWindow::CheckoutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckoutWindow)
{
    ui->setupUi(this);
}

CheckoutWindow::~CheckoutWindow()
{
    delete ui;
}

void CheckoutWindow::setDatabase(QString &path)
{
    _db = new DBManager(path);
}
