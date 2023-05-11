/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-08 20:55:48
 * @LastEditTime: 2023-05-11 09:58:02
 * @Description: 
 */

#include "mainwindow.h"

#include <QApplication>
#include "dbutil.h"

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
