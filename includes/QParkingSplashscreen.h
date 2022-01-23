#ifndef QPARKINGSPLASHSCREEN_H
#define QPARKINGSPLASHSCREEN_H

#include <QDialog>

namespace Ui {
class QParkingSplashscreen;
}

class QParkingSplashscreen : public QDialog
{
    Q_OBJECT

public:
    explicit QParkingSplashscreen(QWidget *parent = 0);
    void showMessage(const QString& message);
    void setPercentage(const unsigned int& value);
    ~QParkingSplashscreen();

private:
    Ui::QParkingSplashscreen *ui;
};

#endif // QPARKINGSPLASHSCREEN_H
