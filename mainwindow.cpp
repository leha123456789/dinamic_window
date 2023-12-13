#include "mainwindow.h"
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
#include <QDialog>
using namespace std;
Group::Group(QGroupBox *parent)
    : QGroupBox(parent)
{
    grid = new QGridLayout;
    QPushButton *settings = new QPushButton(tr("Настройки"));
    grid->addWidget(settings,9,10);
    int name= 1;
    QString text = "ЧСС";
    Group* gr[31];
    gr[0] = new Group(name,text,num);
    grid->addWidget(gr[0],0,8);
    name= 2;
    text = "АДсис";
    gr[1] = new Group(name,text,num);
    grid->addWidget(gr[1],0,9);
    text = "ЧСС";
    name= 3;
    gr[2] = new Group(name,text,num);
    grid->addWidget(gr[2],0,10);
    text = "ЧД по ЭКГ";
    name= 4;
    gr[3] = new Group(name,text,num);
    grid->addWidget(gr[3],1,8);
    text = "АДдиа";
    name= 5;
    gr[4] = new Group(name,text,num);
    grid->addWidget(gr[4],1,9);
    text = "ИАД1диа";
    name= 6;
    gr[5] = new Group(name,text,num);
    grid->addWidget(gr[5],1,10);
    text = "ST";
    name= 7;
    gr[6] = new Group(name,text,num);
    grid->addWidget(gr[6],2,8);
    text = "АДср";
    name= 8;
    gr[7] = new Group(name,text,num);
    grid->addWidget(gr[7],2,9);
    text = "ИАД1ср";
    name= 9;
    gr[8] = new Group(name,text,num);
    grid->addWidget(gr[8],2,10);
    text = "ЧП";
    name= 10;
    gr[9] = new Group(name,text,num);
    grid->addWidget(gr[9],3,8);
    text = "ЧД по СО2";
    name= 11;
    gr[10] = new Group(name,text,num);
    grid->addWidget(gr[10],3,9);
    text = "ИАД2сис ";
    name= 12;
    gr[11] = new Group(name,text,num);
    grid->addWidget(gr[11],3,10);
    text = "SpO2";
    name= 13;
    gr[12] = new Group(name,text,num);
    grid->addWidget(gr[12],4,8);
    text = "EtCO2";
    name= 14;
    gr[13] = new Group(name,text,num);
    grid->addWidget(gr[13],4,9);
    text = "ИАД2диа";
    name= 15;
    gr[14] = new Group(name,text,num);
    grid->addWidget(gr[14],4,10);
    text = "T1";
    name= 16;
    gr[15] = new Group(name,text,num);
    grid->addWidget(gr[15],5,8);
    text = "ПСО2";
    name= 17;
    gr[16] = new Group(name,text,num);
    grid->addWidget(gr[16],5,9);
    text = "ИАД2ср";
    name= 18;
    gr[17] = new Group(name,text,num);
    grid->addWidget(gr[17],5,10);
    text = "T2";
    name= 19;
    gr[18] = new Group(name,text,num);
    grid->addWidget(gr[18],6,8);
    text = "O2";
    name= 20;
    gr[19] = new Group(name,text,num);
    grid->addWidget(gr[19],6,9);
    text = "VD";
    name= 21;
    gr[20] = new Group(name,text,num);
    grid->addWidget(gr[20],6,10);
    text = "ЧП по ИАД";
    name= 22;
    gr[21] = new Group(name,text,num);
    grid->addWidget(gr[21],7,8);
    text = "BiS";
    name= 23;
    gr[22] = new Group(name,text,num);
    grid->addWidget(gr[22],7,9);
    text = "СВ";
    name= 24;
    gr[23] = new Group(name,text,num);
    grid->addWidget(gr[23],7,10);
    name= 0;
    num = 3;
    gr[24] = new Group(name,text,num);
    grid->addWidget(gr[24],0,0,3,6);
    name= 0;
    num = 6;
    gr[25] = new Group(name,text,num);
    grid->addWidget(gr[25],3,0,3,6);
    name= 0;
    num = 9;
    gr[26] = new Group(name,text,num);
    grid->addWidget(gr[26],6,0,3,6);
    setLayout(grid);
    setWindowTitle(tr("Установка тревог"));
    resize(1920, 1080);
    connect(settings,&QPushButton::clicked,this,[this, gr]{
        QPushButton *enter = new QPushButton(tr("Принять"));
        QGridLayout* layout = new QGridLayout;
        layout->addWidget(enter,15,2);
        setting->show();
        int k=0;
        QCheckBox* q[28];
        QString text[28] = {"ЧСС","АДсис","ЧСС","ЧД по ЭКГ","АДдиа","ИАД1диа","ST","АДср","ИАД1ср","ЧП","ЧД по СО2","ИАД2сис","SpO2","EtCO2","ИАД2диа","T1","ПСО2","ИАД2ср","T2","O2","VD","ЧП по ИАД","BiS","СВ","График ЧСС", "График АДдиа","График ЧД по ЭКГ"};
        for (int i=0;i<=26;i++)
        {
            q[i] = new QCheckBox;
            q[i]->setText(text[i]);
            if (k < 14)
            {
                layout->addWidget(q[i],k,0);
            }
            else
            {
                layout->addWidget(q[i],k-14,1);
            }
            k = k + 1;
        }
        q[24]->setChecked(true);
        q[25]->setChecked(true);
        q[26]->setChecked(true);

        connect(enter,&QPushButton::clicked,this,[gr, q, this]
        {
            int pos[24][2];
            for (int i = 0; i < 24; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    pos[i][j] = 1;
                }
            }
            for (int i=0;i<=23;i++)
            {
                if (q[i]->isChecked()==true)
                    gr[i] -> hide();
                if (q[i]->isChecked()==false)
                    gr[i] -> show();
            }
            for (int i = 0; i < 8; i++)
            {
                if (q[i*3]->isChecked()==false && q[1+i*3]->isChecked()==true)
                {
                    if (q[2+i*3]->isChecked()==true)
                    {
                        pos[i*3][1] = pos[i*3][1] + 2;
                        grid->addWidget(gr[i*3],i,8,pos[i*3][0],pos[i*3][1]);
                    }
                    else {
                        pos[i*3][1] = pos[i*3][1] + 1;
                        grid->addWidget(gr[i*3],i,8,pos[i*3][0],pos[i*3][1]);
                    }
                }
                if (q[2+i*3]->isChecked()==false && q[1+i*3]->isChecked()==true)
                {
                    if (q[i*3]->isChecked()==true)
                    {
                        pos[2+i*3][1] = pos[2+i*3][1] + 2;
                        grid->addWidget(gr[2+i*3],i,8,pos[2+i*3][0],pos[2+i*3][1]);
                    }
                }
                if (q[1+i*3]->isChecked()==false && (q[i*3]->isChecked()==true || q[2+i*3]->isChecked()==true))
                {
                    if (q[i*3]->isChecked()==true && q[2+i*3]->isChecked()==true)
                    {
                        pos[1+i*3][1] = pos[1+i*3][1] + 2;
                        grid->addWidget(gr[1+i*3],i,8,pos[1+i*3][0],pos[1+i*3][1]);
                    }
                    else if (q[i*3]->isChecked()==true){
                        pos[1+i*3][1] = pos[1+i*3][1] + 1;
                        grid->addWidget(gr[1+i*3],i,8,pos[1+i*3][0],pos[1+i*3][1]);
                    }
                    else{
                        pos[1+i*3][1] = pos[1+i*3][1] + 1;
                        grid->addWidget(gr[1+i*3],i,9,pos[1+i*3][0],pos[1+i*3][1]);
                    }
                }
                if (q[1+i*3]->isChecked()==false && q[i*3]->isChecked()==false && q[2+i*3]->isChecked()==false)
                {
                    pos[i*3][1] = 1;
                    grid->addWidget(gr[i*3],i,8);
                    pos[1+i*3][1] = 1;
                    grid->addWidget(gr[1+i*3],i,9);
                    pos[2+i*3][1] = 1;
                    grid->addWidget(gr[2+i*3],i,10);
                }
            }
            int k = 1;
            for (int i = 1; i < 8; i++)
            {
                while (q[i*3]->isChecked()==false && q[(i - k)*3]->isChecked()==true && q[1+i*3]->isChecked()==false && q[1 + (i - k)*3]->isChecked()==true && q[2+i*3]->isChecked()==false && q[2 +(i - k)*3]->isChecked()==true)
                {
                    pos[i*3][0]++;
                    pos[1+i*3][0]++;
                    pos[2+i*3][0]++;
                    grid->addWidget(gr[i*3],i - k,8,pos[i*3][0],pos[i*3][1]);
                    grid->addWidget(gr[1+i*3],i - k,9,pos[1+i*3][0],pos[1+i*3][1]);
                    grid->addWidget(gr[2+i*3],i - k,10,pos[2+i*3][0],pos[2+i*3][1]);
                    if (i - k == 0 )
                        break;
                    k++;
                }
                k = 1;
            }
                if (q[24]->isChecked()==false)
                {
                    gr[24]->hide();
                    grid->addWidget(gr[25],0,0,6,6);
                }
                else
                {
                    grid->addWidget(gr[25],3,0,3,6);
                    gr[24]->show();
                }
                if (q[25]->isChecked()==false)
                {
                    gr[25]->hide();
                    grid->addWidget(gr[26],3,0,6,6);
                    if (q[25]->isChecked()==false and q[24]->isChecked()==false)
                    {
                        grid->addWidget(gr[26],0,0,9,6);
                    }
                }
                else
                {
                    gr[25]->show();
                    grid->addWidget(gr[26],6,0,3,6);
                }
                if (q[26]->isChecked()==false)
                {
                    gr[26]->hide();
                }
                else
                {
                    gr[26]->show();
                }
        });
        setting->setLayout(layout);
        setting->setWindowTitle(tr("Настройки"));
        setting->resize(700, 700);
    });
}







































