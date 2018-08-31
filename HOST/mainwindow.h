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
#include "server.h"

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

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QElapsedTimer myElapsedTimer;
    QTableWidget *link_device_table;
    QTableWidget *Part_number_table;
    server *serverPtr;
};

#endif // MAINWINDOW_H
