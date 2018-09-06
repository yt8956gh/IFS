#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QElapsedTimer>
#include <QTableWidget>
#include <QDebug>
#include <QString>
#include <string>
#include <linechart.h>
#include <stdlib.h>
#include <time.h>
#include <QList>
#include "server.h"
#include "clientinfo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QTime *time;
    ~MainWindow();

public slots:
    void timerUpDate();
    void recvDataCat(QString);
    void changeClientTable(QList<clientInfo>);


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QElapsedTimer myElapsedTimer;
    QTableWidget *link_device_table;
    QTableWidget *Part_number_table;
    LineChart *chart1,*chart2,*chart3;
    myserver::server *serverPtr;
};

#endif // MAINWINDOW_H
