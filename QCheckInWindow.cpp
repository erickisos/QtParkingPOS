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

void QCheckInWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F3)
    {
        qDebug() << "Pulsaste F3!";
        qDebug() << "Generando nuevo ticket!";
    }
 }
