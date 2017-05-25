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

void CheckinWindow::setDatabase(QString &path)
{
    _db = new DBManager(path);
}
