#include "logpage.h"
#include "QFramer/futil.h"

LogPage* LogPage::instance = 0;

LogPage::LogPage(QWidget *parent) :
    QFrame(parent)
{
    initData();
    initUI();
}

LogPage *LogPage::getInstance()
{
    if(!instance)
    {
        instance = new LogPage();
    }
    return instance;
}

void LogPage::initUI()
{
    mScrollArea = new QScrollArea;
    mScrollArea->setFrameShape(QFrame::NoFrame);
    mScrollArea->setWidget(&logText);

    mVBox = new QVBoxLayout;
    mVBox->addWidget(&title);
    mVBox->addWidget(mScrollArea);
    mVBox->addWidget(new QSizeGrip(this), 0, Qt::AlignBottom | Qt::AlignRight);

    setLayout(mVBox);
}

void LogPage::initData()
{
    QString testlog;
    title.setText(tr("系统日志"));
    title.setObjectName("logtitle");
    testlog = readFile(QApplication::applicationDirPath()+"\/log.txt");
    logText.setText(testlog);
    logText.setObjectName("log");
}

void LogPage::appendNewLog(QString unit)
{
    QString temp;
    QFile data(QApplication::applicationDirPath()+"\/log.txt");

    temp = logText.text();
    temp = temp + QDate::currentDate().toString("yyyy.MM.dd") + " " + QTime::currentTime().toString("hh:mm") + " " + "从" + " " + unit + " " + "发出警报" + "\n";
    logText.setText(temp);
    logText.adjustSize();

    if (data.open(QFile::ReadWrite | QIODevice::Append)) {
            QTextStream out(&data);
            out << QDate::currentDate().toString("yyyy.MM.dd") + " " + QTime::currentTime().toString("hh:mm") + " " + "从" + " " + unit + " " + "发出警报" + "\n";
            qDebug()<<"write success";
        }
    data.close();

}
