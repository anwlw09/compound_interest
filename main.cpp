#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;    
    QTranslator qtTranslator;
    qtTranslator.load("compound_interest.qm");
    a.installTranslator(&qtTranslator);
    w.show();

    return a.exec();
}
