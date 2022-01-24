#include "QCheckOutWindow.h"
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

void QCheckOutWindow::setDatabaseManager(QDatabaseManager &db)
{
    _db = &db;
}

void QCheckOutWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F3)
    {
        qDebug() << "Generando nuevo ticket!";
    }
    else if(event->key() == Qt::Key_F12)
    {
        qDebug() << "Generando Corte!";
    }
}
