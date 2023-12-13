#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qcustomplot.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QProgressBar>
#include <QLabel>
#include <QSlider>
#include <QMenu>
#include <QString>
#include <QWidget>
#include <QLCDNumber>
#include <QPushButton>
#include <QGroupBox>
#include <QTimer>
#include <QFlag>
#include <QLCDNumber>
#include <QFrame>
#include <QtMath>
QT_BEGIN_NAMESPACE
namespace Ui { class Group; }
QT_END_NAMESPACE
class Group : public QGroupBox
{
    Q_OBJECT
public:
    explicit Group(QGroupBox *parent = nullptr);
    ~Group()
    {
        if (tmr)
            delete tmr;
        if (grid)
            delete grid;
        if (vbox)
            delete vbox;
        if (groupBox)
            delete groupBox;
        if (plot)
            delete plot;
        if (NUM)
            delete NUM;
        if (label)
            delete label;
    }
private:
    QCustomPlot *plot;
    QGroupBox *groupBox;
    QProgressBar *prog;
    QGridLayout *vbox;
    QGridLayout *grid;
    QGridLayout *grid1;
    QTimer* tmr;
    QTimer* tmr1;
    QLCDNumber *NUM;
    QLabel *label;
    QPen *pen;
    QCPGraph *graph1;
    QDialog *setting=new QDialog;
    QVector <double> key, value,value1,value2;
    double i = 0;
    int l = 0;
    int num = 0;
    double k = 0;
    int g = 100;
    Group(int name,QString text,int num)
    {
        QString colour[4] = {"blue","red","green"};
        int size[4] = {2,4,6};
        QString text1[4] = {"ЧСС","АДдиа","ЧП по ИАД"};
        groupBox = new QGroupBox;
        prog = new QProgressBar;
        vbox = new QGridLayout;
        plot = new QCustomPlot;
        NUM = new QLCDNumber;
        label = new QLabel;
        pen = new QPen;
        NUM->setSegmentStyle(QLCDNumber::Flat);
        QPalette palette = NUM->palette();
        this->setLayout(vbox);
        if (num == 3)
        {
            pen->setWidth(size[0]);
            pen->setColor(colour[0]);
        }
        if (num == 6)
        {
            pen->setWidth(size[1]);
            pen->setColor(colour[1]);
        }
        if (num == 9)
        {
            pen->setWidth(size[2]);
            pen->setColor(colour[2]);
        }
        NUM->setFrameStyle(QFrame::NoFrame);
        bool flag = false;
        if (name != 0)
        {
            vbox->addWidget(label,0,0);
            vbox->addWidget(NUM,1,0,5,1);
            label->setText(text);
            if (name == 1)
            {
                palette.setColor(QPalette::Normal,QPalette::WindowText,Qt::blue);
                NUM->setPalette(palette);
            }
            if (name == 4)
            {
                palette.setColor(QPalette::Normal,QPalette::WindowText,Qt::red);
                NUM->setPalette(palette);
            }
            if (name == 21)
            {
                palette.setColor(QPalette::Normal,QPalette::WindowText,Qt::green);
                NUM->setPalette(palette);
            }
        }
        else
        {
            vbox->addWidget(plot);
            plot->addGraph();
            plot->addGraph();
            tmr = new QTimer(this);
            connect(tmr, &QTimer::timeout, this, [text1, text, this, num, &flag]
                    {
                        i++;
                        graph1 = plot->graph(0);
                        graph1->setPen(*pen);
                        if (num == 3)
                        {
                            graph1->setName(text1[0]);
                        }
                        if (num == 6)
                        {
                            graph1->setName(text1[1]);
                        }
                        if (num == 9)
                        {
                            graph1->setName(text1[2]);
                        }
                        if (int(i) % 100 == 0)
                        {
                            if(flag)
                                flag= false;
                            else
                                flag = true;
                        }
                        if (!flag){
                            plot->graph(1)->data()->remove(int(i) % 100,(int(i) % 100)+2);
                            graph1->addData(int(i) % 100, qSin(i));
                            if (graph1->visible() == true)
                                plot->graph(1)->setPen(*pen);
                        }else{
                            qInfo()<<int(i) % 100;
                            qInfo()<<graph1->data()->at(int(i) % 100)->value;
                            qInfo()<<graph1->data()->at((int(i) % 100)+1)->value;
                            qInfo()<<graph1->data()->at((int(i) % 100)+2)->value;
                            qInfo()<<graph1->data()->size();
                            graph1->data()->remove(int(i) % 100,(int(i) % 100)+2);
                            if (graph1->visible() == true)
                                plot->graph(1)->setPen(*pen);
                            plot->graph(1)->addData(int(i) % 100, qSin(i));
                        }
                        plot->replot();
                    });
            tmr->start(1);
            plot->setBackground(QBrush(QColor(0,0,0,255)));
            plot->xAxis->setRange(0, g);
            plot->yAxis->setRange(-2, 2);
            plot->xAxis->grid()->setVisible(false);
            plot->yAxis->grid()->setVisible(false);
            plot->legend->setVisible(true);
            //plot->legend->addItem()
            plot->legend->removeItem(1);
            QFont legendFont = font();
            legendFont.setPointSize(9);
            plot->legend->setFont(legendFont);
            plot->legend->setBrush(QColor(255,255,255,0));
            plot->legend->setTextColor(QColor(0,128,0));
            plot->setInteraction(QCP::iRangeZoom, true);
            plot->setInteraction(QCP::iRangeDrag, true);
            plot->axisRect()->setRangeZoom(Qt::Horizontal);
            plot->axisRect()->setRangeDrag(Qt::Horizontal);
        }
        tmr1 = new QTimer(this);
        connect(tmr1, &QTimer::timeout, this, [this]
                {
                    if(prog->value() >= prog->maximum() ) prog->reset();
                    prog->setValue(prog->value()+1);
                    NUM->display(prog->value());
                });
        tmr1->start(1000);
    }
};


#endif // MAINWINDOW_H
