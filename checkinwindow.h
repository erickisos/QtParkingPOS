#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CheckinWindow;
}

class CheckinWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckinWindow(QWidget *parent = 0);
    ~CheckinWindow();

private:
    Ui::CheckinWindow *ui;
};

#endif // CHECKINWINDOW_H
