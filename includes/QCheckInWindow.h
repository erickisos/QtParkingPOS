#ifndef QCHECKINWINDOW
#define QCHECKINWINDOW

#include <QMainWindow>
#include <QDatabaseManager.h>
#include <QKeyEvent>

namespace Ui {
class QCheckInWindow;
}

class QCheckInWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QCheckInWindow(QWidget *parent = 0);
    void setDatabaseManager(QDatabaseManager& db);
    ~QCheckInWindow();
protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::QCheckInWindow *ui;
    QDatabaseManager* _db;
};

#endif // QCHECKINWINDOW
