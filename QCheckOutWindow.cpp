#include "QCheckOutWindow"
#include "ui_QCheckOutWindow.h"

QCheckOutWindow::QCheckOutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QCheckOutWindow)
{
    ui->setupUi(this);
}

QCheckOutWindow::~QCheckOutWindow()
{
    delete ui;
}
