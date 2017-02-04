#include "centerwindow.h"
//#include "QFramer/fwigglywidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QFramer/futil.h"


CenterWindow::CenterWindow(QWidget *parent) :
      FTabWidget(parent)
{
    initUI();
}

void CenterWindow::initUI()
{
    initStatus();
    initLog();

    getButtons().at(0)->click();
}


/*void CenterWindow::addWiggleWiget()
{
    FWigglyWidget* wiggleWidget = new FWigglyWidget("Faster Easier Stronger Prettier", getNavgationBar());
    wiggleWidget->move(40, 5);
    wiggleWidget->setFixedSize(400, 60);
    wiggleWidget->setStyleSheet("background-color: transparent;\
                                 font-size: 20px;");
}*/

void CenterWindow::initStatus()
{
    statusPanel = StatusPanel::getInstance();

    addWidget(tr("实时信息"), QString(""), statusPanel);
}

void CenterWindow::initLog()
{
    logPage = LogPage::getInstance();

    addWidget(tr("系统日志"), QString(""), logPage);
}
