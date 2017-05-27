#ifndef QABOUTDIALOG
#define QABOUTDIALOG

#include <QDialog>

namespace Ui {
class QAboutDialog;
}

class QAboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QAboutDialog(QWidget *parent = 0);
    ~QAboutDialog();

private:
    Ui::QAboutDialog *ui;
};

#endif // QABOUTDIALOG
