#include "linechart.h"


using namespace std;

LineChart::LineChart(QColor LineColor,int mid,int interval,QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(),
    m_axis(new QValueAxis),
    m_step(0),
    m_x(5),
    m_y(1),
    mid(mid),
    interval(interval)
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &LineChart::handleTimeout);
    m_timer.setInterval(1000);

    m_series = new QSplineSeries(this);
    QPen green(LineColor);
    green.setWidth(3);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

    addSeries(m_series);
    createDefaultAxes();
    setAxisX(m_axis, m_series);
    m_axis->setTickCount(5);
    axisX()->setRange(0, 10);
    axisY()->setRange(0, mid+interval+5);

    QFont font;
    font.setPixelSize(12);

    axisX()->setLabelsVisible(false);
    axisY()->setLabelsFont(font);

    m_timer.start();
    myElapsedTimer.start();

    setMargins(QMargins(10,0,0,0));
}

LineChart::~LineChart()
{

}

void LineChart::handleTimeout()
{
    //printf("",myElapsedTimer.elapsed());
    int posneg = (rand()%2)?1:-1;
    qreal x = plotArea().width() / m_axis->tickCount();
    qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += y;
    m_y = rand()%interval*posneg + mid;
    m_series->append(m_x, m_y);
    scroll(x, 0);
}
