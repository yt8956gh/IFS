#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <stdlib.h>
#include <time.h>
#include <linechart.h>


QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("IFS 智慧工廠系統"));

    QLabel *label1  =new QLabel(tr("內容1"));
    QLabel *label2  =new QLabel(tr("內容2"));
    QLabel *label3  =new QLabel(tr("內容3"));


    LineChart *chart = new LineChart();
    chart->setTitle(tr("溫度"));
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView = new QChartView(chart);


    LineChart *chart2 = new LineChart();
    chart2->setTitle(tr("溼度"));
    chart2->legend()->hide();
    chart2->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView2 = new QChartView(chart2);

    ui->verticalLayout->addWidget(chartView);
    ui->verticalLayout->addSpacing(1);
    ui->verticalLayout->addWidget(chartView2);

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(label1,tr("警示系統"));
    ui->tabWidget->addTab(label2,tr("主機狀態"));
    ui->tabWidget->addTab(label3,tr("連線設備"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
