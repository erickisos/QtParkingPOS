#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H

#include <QMainWindow>
#include <QDatabaseManager.h>

namespace Ui {
class CheckinWindow;
}

class CheckinWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckinWindow(QWidget *parent = 0);
    void setDatabaseManager(QDatabaseManager& db);
    ~CheckinWindow();

private:
    Ui::CheckinWindow *ui;
    QDatabaseManager* _db;
};

#endif // CHECKINWINDOW_H
