#ifndef STATUSPANEL_H
#define STATUSPANEL_H
#include <QFrame>
#include <QPushButton>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <Qt>
#include <QSound>
#include "logpage.h"
#include "setnamedialog.h"

class StatusPanel;
class AlertUnit : public QPushButton
{
    Q_OBJECT
protected:
    void mouseDoubleClickEvent(QMouseEvent *e);
public:
    explicit AlertUnit(QWidget *parent = 0);
    QString name;
public slots:
    void alert();
    void removeAlert();
    void setName();
    void setNameFromSettings(QString n);

};

class StatusPanel : public QFrame
{
    Q_OBJECT
private:

    QHBoxLayout *hboxa;
    QHBoxLayout *hboxb;
    QHBoxLayout *hboxc;
    QHBoxLayout *hboxd;
    QVBoxLayout *vbox;
    QLabel titlea;
    QLabel titleb;
    QLabel titlec;
    QLabel titled;

private:
    static StatusPanel* instance;
    explicit StatusPanel(QWidget *parent = 0);
public:
    QList<AlertUnit*> units;
    static StatusPanel* getInstance();
    void initUI();
    void initData();
    void initAlertUnit();
};




#endif // STATUSPANEL_H
