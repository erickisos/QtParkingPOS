#ifndef PAYDIALOG_H
#define PAYDIALOG_H

#include <QDialog>

namespace Ui {
class PayDialog;
}

class PayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PayDialog(QWidget *parent = 0);
    ~PayDialog();

private:
    Ui::PayDialog *ui;
};

#endif // PAYDIALOG_H
