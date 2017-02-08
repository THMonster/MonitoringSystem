#ifndef SETNAMEDIALOG_H
#define SETNAMEDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include "statuspanel.h"

class AlertUnit;
class SetNameDialog : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *mvbox;
    AlertUnit *unit;
    QLineEdit *mLineEdit;
    QPushButton *mPushButton;
public:
    explicit SetNameDialog(QWidget *parent = 0, AlertUnit *alertunit = 0);
    void accept();
};

#endif // SETNAMEDIALOG_H
