#include "setnamedialog.h"

SetNameDialog::SetNameDialog(QWidget *parent, AlertUnit *alertunit) :
    QDialog(parent)
{
    mvbox = new QVBoxLayout;
    mLineEdit = new QLineEdit;
    mLineEdit->setText(alertunit->name);
    mvbox->addWidget(mLineEdit);

    mPushButton = new QPushButton;
    mPushButton->setText("确定");

    mvbox->addWidget(mPushButton);

    unit = alertunit;

    setLayout(mvbox);

    connect(mPushButton, &QPushButton::clicked, this, &SetNameDialog::accept);
}

void SetNameDialog::accept()
{
    unit->name = mLineEdit->text();
    QDialog::accept();
}
