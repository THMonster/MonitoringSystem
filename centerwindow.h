/****************************************************************************
**
** Copyright (C) 2014 dragondjf
**
** QFramer is a frame based on Qt5.3, you will be more efficient with it.
** As an Qter, Qt give us a nice coding experience. With user interactive experience(UE)
** become more and more important in modern software, deveployers should consider business and UE.
** So, QFramer is born. QFramer's goal is to be a mature solution
** which you only need to be focus on your business but UE for all Qters.
**
** Version	: 0.2.5.0
** Author	: dragondjf
** Website	: https://github.com/dragondjf
** Project	: https://github.com/dragondjf/QCFramer
** Blog		: http://my.oschina.net/dragondjf/home/?ft=atme
** Wiki		: https://github.com/dragondjf/QCFramer/wiki
** Lincence: LGPL V2
** QQ: 465398889
** Email: dragondjf@gmail.com, ding465398889@163.com, 465398889@qq.com
**
****************************************************************************/

#ifndef CENTERWINDOW_H
#define CENTERWINDOW_H

#include "QFramer/fcenterwindow.h"
//#include "functionpages/aboutpage.h"
//#include "functionpages/mathplot.h"
//#include "functionpages/uielement.h"
//#include "functionpages/qssbuilder.h"
#include <QVBoxLayout>
#include <QLabel>
#include "QFramer/ftabwidget.h"
#include "QFramer/ftitlebar.h"
#include "statuspanel.h"
#include "logpage.h"


class CenterWindow : public FTabWidget
{
    Q_OBJECT
private:
    QVBoxLayout *vLayout;
    QVBoxLayout *mVBox;

public:
//    UIElement* uiElements;
//    MathPlot* mathPlot;
//    AboutPage* aboutPage;
//    QssBuilder* qssBuilder;
    StatusPanel* statusPanel;
    LogPage* logPage;

public:
    explicit CenterWindow(QWidget *parent = 0);
    void initUI();
//    void addWiggleWiget();
    void initStatus();
    void initLog();
signals:

public slots:
//    void cloudAntimation();
};

#endif // CENTERWINDOW_H
