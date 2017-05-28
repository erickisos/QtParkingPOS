#include "QCheckInWindow.h"
#include "ui_QCheckInWindow.h"

QCheckInWindow::QCheckInWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QCheckInWindow)
{
    ui->setupUi(this);
}

QCheckInWindow::~QCheckInWindow()
{
    delete ui;
}

void QCheckInWindow::setDatabaseManager(QDatabaseManager &db)
{
    _db = &db;
}
