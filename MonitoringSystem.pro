#-------------------------------------------------
#
# Project created by QtCreator 2017-01-23T11:43:39
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MonitoringSystem
TEMPLATE = app


include(./QFramer/QFramer.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    centerwindow.cpp \
    statuspanel.cpp \
    logpage.cpp \
    setnamedialog.cpp

HEADERS  += mainwindow.h \
    centerwindow.h \
    statuspanel.h \
    logpage.h \
    setnamedialog.h

RESOURCES += \
    res.qrc
