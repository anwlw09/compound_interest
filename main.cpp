#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("compound_interest");
    a.installTranslator(&qtTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
