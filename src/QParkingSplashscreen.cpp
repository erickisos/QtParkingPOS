#include "QParkingSplashscreen.h"
#include "ui_QParkingSplashscreen.h"

QParkingSplashscreen::QParkingSplashscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QParkingSplashscreen)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->ui->label->setText("Loading...");
}

QParkingSplashscreen::~QParkingSplashscreen()
{
    delete ui;
}

void QParkingSplashscreen::showMessage(const QString &message)
{
    this->ui->label->setText(message);
}

void QParkingSplashscreen::setPercentage(const unsigned int &value)
{
    this->ui->progressBar->setValue(value);
}
