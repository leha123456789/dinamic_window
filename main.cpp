#include "mainwindow.h"
#include <QGridLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Group w;
    w.show();
    return a.exec();
}
