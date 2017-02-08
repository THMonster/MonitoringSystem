#ifndef LOGPAGE_H
#define LOGPAGE_H

#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QTime>
#include <QFile>
#include <QApplication>
#include <QDate>
#include <QSizeGrip>

class LogPage : public QFrame
{
    Q_OBJECT

private:
    static LogPage* instance;
    explicit LogPage(QWidget* parent = 0);
    QLabel logText;
    QLabel title;
    QVBoxLayout* mVBox;
    QScrollArea* mScrollArea;

public:
    static LogPage* getInstance();
    void initUI();
    void initData();
    void appendNewLog(QString unit);


};

#endif // LOGPAGE_H
