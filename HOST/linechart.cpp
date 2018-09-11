#include "linechart.h"


using namespace std;

LineChart::LineChart(QColor LineColor,int most,QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(),
    m_axis(new QValueAxis),
    m_step(0),
    m_x(10),
    m_y(1),
    most(most)
{
    //QObject::connect(&m_timer, &QTimer::timeout, this, &LineChart::handleTimeout);
    //m_timer.setInterval(1000);

    m_series = new QSplineSeries(this);
    QPen green(LineColor);
    green.setWidth(3);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

    addSeries(m_series);
    createDefaultAxes();
    setAxisX(m_axis, m_series);
    m_axis->setTickCount(25);
    axisX()->setRange(0, 10);
    axisY()->setRange(0, most);


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

void LineChart::DataUpdate(int num)
{
    if(num>most)
    {
        most = int(num*1.2);
        axisY()->setMax(most);
    }

    int count = m_series->count();
    if((count-26)>=0) m_series->remove(count-26);


    qreal cellWidth = plotArea().width() / m_axis->tickCount();
    qreal cellHeight = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += cellHeight;
    m_y = num;
    m_series->append(m_x, m_y);
    scroll(cellWidth, 0);
}
