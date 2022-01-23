#ifndef QCUSTOMSPLASH_H
#define QCUSTOMSPLASH_H

#include <QSplashScreen>
#include <QApplication>
#include <QStyleOptionProgressBarV2>

class QCustomSplash : public QSplashScreen
{
    Q_OBJECT
public:
    explicit QCustomSplash(QApplication* _app, QWidget* parent=0);
    int m_progress;
    QApplication* app;
public slots:
    void setProgress(int value);
protected:
    void drawContents(QPainter* painter);
};

#endif // QCUSTOMSPLASH_H
