#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QLabel>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font;
    font.setPixelSize(20);
    a.setFont(font);
    MainWindow w;
    w.show();

    return a.exec();
}
