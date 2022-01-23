#include "QCustomSplash.h"


QCustomSplash::QCustomSplash(QApplication *_app, QWidget *parent) : QSplashScreen(parent), app(_app), m_progress(0)
{
    this->setPixmap(QPixmap(":/images/splash"));
    this->setCursor(Qt::BusyCursor);
    this->showMessage("Loading...", Qt::AlignTop | Qt::AlignLeft);
}

void QCustomSplash::drawContents(QPainter *painter)
{
    QSplashScreen::drawContents(painter);
    QStyleOptionProgressBarV2 pbstyle;
    pbstyle.initFrom(this);
    pbstyle.state = QStyle::State_Enabled;
    pbstyle.textVisible = false;
    pbstyle.minimum = 0;
    pbstyle.maximum = 100;
    pbstyle.progress = m_progress;
    pbstyle.invertedAppearance = false;
    pbstyle.rect = QRect(0, 265, 380, 19);
    style()->drawControl(QStyle::CE_ProgressBar, &pbstyle, painter, this);
}
