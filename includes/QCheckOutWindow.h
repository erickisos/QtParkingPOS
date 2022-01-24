#ifndef QCHECKOUTWINDOW
#define QCHECKOUTWINDOW

#include <QMainWindow>
#include <QDatabaseManager.h>
#include <QKeyEvent>

namespace Ui {
class QCheckOutWindow;
}

class QCheckOutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QCheckOutWindow(QWidget *parent = 0);
    void setDatabaseManager(QDatabaseManager& db);
    ~QCheckOutWindow();
protected:
    void keyReleaseEvent(QKeyEvent *event);
private:
    Ui::QCheckOutWindow *ui;
    QDatabaseManager* _db;
};

#endif // QCHECKOUTWINDOW
