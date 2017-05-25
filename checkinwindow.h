#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H

#include <QMainWindow>
#include <dbmanager.h>

namespace Ui {
class CheckinWindow;
}

class CheckinWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckinWindow(QWidget *parent = 0);
    void setDatabase(QString& path);
    ~CheckinWindow();

private:
    Ui::CheckinWindow *ui;
    DBManager* _db;
};

#endif // CHECKINWINDOW_H
