#ifndef LINECHART_H
#define LINECHART_H


#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

//![1]
class LineChart: public QChart
{
    Q_OBJECT
public:
    LineChart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~LineChart();

public slots:
    void handleTimeout();

private:
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axis;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};

#endif // LINECHART_H
