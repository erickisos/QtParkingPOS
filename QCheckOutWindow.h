#ifndef QCHECKOUTWINDOW
#define QCHECKOUTWINDOW

#include <QMainWindow>
#include <QDatabaseManager.h>

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

private:
    Ui::QCheckOutWindow *ui;
    QDatabaseManager* _db;
};

#endif // QCHECKOUTWINDOW
