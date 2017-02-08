#include "statuspanel.h"


StatusPanel* StatusPanel::instance = 0;

StatusPanel::StatusPanel(QWidget *parent) :
    QFrame(parent)
{
    initData();
    initUI();
    setObjectName("statuspanel");

}

StatusPanel *StatusPanel::getInstance()
{
    if(!instance)
    {
        instance = new StatusPanel();
    }
    return instance;
}

void StatusPanel::initUI()
{
    int i = 0;

    hboxa = new QHBoxLayout;
    while (i < 5) {
        hboxa->addWidget(units.at(i));
        if(i != 5-1)
            hboxa->addStretch(1);
        i++;
    }

    hboxb = new QHBoxLayout;
    while (i < 10) {
        hboxb->addWidget(units.at(i));
        if(i != 10-1)
            hboxb->addStretch(1);
        i++;
    }

    hboxc = new QHBoxLayout;
    while (i < 15) {
        hboxc->addWidget(units.at(i));
        if(i != 15-1)
            hboxc->addStretch(1);
        i++;
    }

    hboxd = new QHBoxLayout;
    while (i < 20) {
        hboxd->addWidget(units.at(i));
        if(i != 20-1)
            hboxd->addStretch(1);
        i++;
    }

    vbox = new QVBoxLayout;
    vbox->addWidget(&titlea);
    vbox->addLayout(hboxa);
    vbox->addWidget(&titleb);
    vbox->addLayout(hboxb);
    vbox->addWidget(&titlec);
    vbox->addLayout(hboxc);
    vbox->addWidget(&titled);
    vbox->addLayout(hboxd);
    vbox->addStretch();
    vbox->addWidget(new QSizeGrip(this), 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(vbox);
}

void StatusPanel::initData()
{
    for(int i = 0; i < 20; i++)
    {
        initAlertUnit();
    }
    titlea.setText(tr("东部方向"));
    titleb.setText(tr("西部方向"));
    titlec.setText(tr("南部方向"));
    titled.setText(tr("北部方向"));

    titlea.setObjectName("statustitle");
    titleb.setObjectName("statustitle");
    titlec.setObjectName("statustitle");
    titled.setObjectName("statustitle");
}

void StatusPanel::initAlertUnit()
{
    AlertUnit *unit = new AlertUnit;
    unit->setFocusPolicy(Qt::NoFocus);
    units.append(unit);
}

void AlertUnit::mouseDoubleClickEvent(QMouseEvent *e)
{
    setName();
}

AlertUnit::AlertUnit(QWidget *parent) :
    QPushButton(parent)
{
    name = "test";
    setText(name);
    setObjectName("alertunit");

    connect(this, &QPushButton::clicked, this, &AlertUnit::removeAlert);
}

void AlertUnit::alert()
{
    setStyleSheet("border-bottom: 3px;\
                               border-style: solid;\
                               border-color: red;");
    QSound::play(":/sound/skin/alert.wav");
    LogPage::getInstance()->appendNewLog(name);
}

void AlertUnit::removeAlert()
{
    setStyleSheet("border-bottom: 3px;\
                               border-style: solid;\
            border-color: rgb(83, 178, 250);");
}

void AlertUnit::setName()
{
    SetNameDialog *dialog = new SetNameDialog(0,this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle(tr("修改设备名称"));
    dialog->exec();
    setText(name);
}

void AlertUnit::setNameFromSettings(QString n)
{
    name = n;
    setText(name);
}
