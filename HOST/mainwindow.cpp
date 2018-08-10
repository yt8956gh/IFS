#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <stdlib.h>
#include <time.h>
#include <linechart.h>
#include <QElapsedTimer>
#include <iostream>
#include <QDebug>
#include <QString>
#include <string>
#include <stdlib.h>
#include <sstream>

QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("IFS 智慧工廠系統"));

    QLabel *label1  =new QLabel("內容1");
    QLabel *label2  =new QLabel("內容2");
    QLabel *label3  =new QLabel("內容3");


    LineChart *chart = new LineChart(qRgb(255, 51, 0));
    chart->setTitle("溫度");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView = new QChartView(chart);


    LineChart *chart2 = new LineChart(qRgb(0, 102, 128));
    chart2->setTitle("溼度");
    chart2->legend()->hide();
    chart2->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView2 = new QChartView(chart2);

    LineChart *chart3 = new LineChart(qRgb(0, 128, 43));
    chart3->setTitle(tr("耗電量"));
    chart3->legend()->hide();
    chart3->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView3 = new QChartView(chart3);

    ui->verticalLayout->addWidget(chartView);
    ui->verticalLayout->addSpacing(1);
    ui->verticalLayout->addWidget(chartView2);
    ui->verticalLayout->addSpacing(1);
    ui->verticalLayout->addWidget(chartView3);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(label1,"警示系統");
    ui->tabWidget->addTab(label2,"主機狀態");
    ui->tabWidget->addTab(label3,"連線設備");

    timer = new QTimer(this);
    time = new QTime();

    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    timer->start(1000);
    time->start();
}


void MainWindow::timerUpDate()
{
    QTime time2=QTime::currentTime();
    QString tmp;
    tmp=QString::number(time->elapsed()/1000/60/60)+":";
    tmp+=QString::number(time->elapsed()/1000/60%60)+":";
    tmp+=QString::number(time->elapsed()/1000%60);


    ui->TimeLable->setText("現在時間："+time2.toString("HH:mm:ss"));
    ui->TimeLable_2->setText("已運作："+tmp);
    //qDebug()<<time->elapsed()/1000<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}
