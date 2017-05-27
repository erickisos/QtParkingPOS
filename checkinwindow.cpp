#include "checkinwindow.h"
#include "ui_checkinwindow.h"

CheckinWindow::CheckinWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckinWindow)
{
    ui->setupUi(this);
}

CheckinWindow::~CheckinWindow()
{
    delete ui;
}

void CheckinWindow::setDatabaseManager(QDatabaseManager &db)
{
    _db = &db;
}
