#include "mainwindow.h"
#include "ui_mainwindow.h"


QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("IFS 智慧工廠系統"));

    QLabel *label1  =new QLabel("內容1");

    LineChart *chart = new LineChart(qRgb(255, 51, 0),27,2);
    chart->setTitle("溫度");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView = new QChartView(chart);


    LineChart *chart2 = new LineChart(qRgb(0, 102, 128),70,2);
    chart2->setTitle("溼度");
    chart2->legend()->hide();
    chart2->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView2 = new QChartView(chart2);

    LineChart *chart3 = new LineChart(qRgb(0, 128, 43),500,250);
    chart3->setTitle(tr("耗電量"));
    chart3->legend()->hide();
    chart3->setAnimationOptions(QChart::AllAnimations);
    QChartView *chartView3 = new QChartView(chart3);

    //建立左邊摺線圖的垂直布局

    ui->verticalLayout->addWidget(chartView);
    ui->verticalLayout->addSpacing(1);
    ui->verticalLayout->addWidget(chartView2);
    ui->verticalLayout->addSpacing(1);
    ui->verticalLayout->addWidget(chartView3);

    //建立連結設備表單

    link_device_table = new QTableWidget();
    link_device_table->setColumnCount(4);
    link_device_table->setRowCount(20);
    link_device_table->setEditTriggers(QAbstractItemView::NoEditTriggers);\
    link_device_table->horizontalHeader()->setStretchLastSection(true);
    link_device_table->setHorizontalHeaderItem(0, new QTableWidgetItem("名稱"));
    link_device_table->setHorizontalHeaderItem(1, new QTableWidgetItem("感測類型"));
    link_device_table->setHorizontalHeaderItem(2, new QTableWidgetItem("目前狀態"));
    link_device_table->setHorizontalHeaderItem(3, new QTableWidgetItem("IP"));

    for(int i=0;i<8;i++)
    {
       QString name;
       name = "ESP-" + QString::number(rand()%1000);
       link_device_table->setItem(i,0,new QTableWidgetItem(name));

       QString category;
       switch(i%3)
       {
       case 0:
           category = "溫溼度";
           break;
       case 1:
           category = "耗電量";
           break;
       case 2:
           category = "流量";
           break;
       }

       link_device_table->setItem(i,1,new QTableWidgetItem(category));

       if(i<6)
       {
           link_device_table->setItem(i,2,new QTableWidgetItem("運作中"));
       }
       else
       {
           link_device_table->setItem(i,2,new QTableWidgetItem("離線"));
       }

       link_device_table->setItem(i,3,new QTableWidgetItem("192.168."+QString::number(rand()%255)+"."+QString::number(rand()%255)));
    }



    Part_number_table = new QTableWidget();
    Part_number_table->setColumnCount(3);
    Part_number_table->setRowCount(20);
    Part_number_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Part_number_table->horizontalHeader()->setStretchLastSection(true);
    Part_number_table->setHorizontalHeaderItem(0, new QTableWidgetItem("廠區"));
    Part_number_table->setHorizontalHeaderItem(1, new QTableWidgetItem("設備"));
    Part_number_table->setHorizontalHeaderItem(2, new QTableWidgetItem("用電量"));


    for(int i=0;i<5;i++)
    {
       QString name;

       Part_number_table->setItem(i,0,new QTableWidgetItem("FAB1"));

       Part_number_table->setItem(i,1,new QTableWidgetItem("ASC_"+QString::number(rand()%1000)));

       Part_number_table->setItem(i,2,new QTableWidgetItem(QString::number(rand()%100)));
    }

    for(int i=5;i<14;i++)
    {
       QString name;

       Part_number_table->setItem(i,0,new QTableWidgetItem("FAB2"));

       Part_number_table->setItem(i,1,new QTableWidgetItem("PBS_"+QString::number(rand()%1000)));

       Part_number_table->setItem(i,2,new QTableWidgetItem(QString::number(rand()%1000)));
    }

    ui->tabWidget->removeTab(0);
    ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(Part_number_table,"能耗管理");
    ui->tabWidget->addTab(link_device_table,"感應器");
    ui->tabWidget->addTab(label1,"警示系統");




    /*
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(20);

    //禁止編輯表單
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //去掉表單水平label 再設成水平延展
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    */

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
    delete link_device_table;
    delete ui;
}
