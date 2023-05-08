
#include "mainwindow.h"

#include <QApplication>

QList<MySocket *> mysocketlist;
QList<QString> gamelist;
QList<qintptr> labellist;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
