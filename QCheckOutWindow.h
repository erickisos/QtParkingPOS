#ifndef QCHECKOUTWINDOW
#define QCHECKOUTWINDOW

#include <QMainWindow>

namespace Ui {
class QCheckOutWindow;
}

class QCheckOutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QCheckOutWindow(QWidget *parent = 0);
    ~QCheckOutWindow();

private:
    Ui::QCheckOutWindow *ui;
};

#endif // QCHECKOUTWINDOW
