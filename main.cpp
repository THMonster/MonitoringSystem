#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{    
    QApplication app(argc, argv);
    QApplication::setOrganizationName("IsoaSFlus");
    QApplication::setOrganizationDomain("http://isoasflus.me");
    QApplication::setApplicationName("MonitoringSystem");

    MainWindow *main = MainWindow::getInstance();
    main->setAttribute(Qt::WA_DeleteOnClose);
    main->show();
    return app.exec();
}
