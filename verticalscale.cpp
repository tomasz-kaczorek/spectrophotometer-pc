#include "verticalscale.h"

#include <qmath.h>
#include <QPainter>

VerticalScale::VerticalScale(qreal scaleBegin, qreal scaleEnd, qreal step, int stepsPerLabel, QWidget * parent) :
    QWidget(parent),
    m_scaleBegin(scaleBegin),
    m_scaleEnd(scaleEnd),
    m_step(step),
    m_stepsPerLabel(stepsPerLabel)
{
    setFixedWidth(60.0);
}

void VerticalScale::visibleRectChanged(QPoint viewportTopLeft, QPoint viewportBottomRight, QPointF sceneTopLeft, QPointF sceneBottomRight)
{
    m_viewportBegin = mapFromGlobal(viewportTopLeft).y();
    m_viewportEnd = mapFromGlobal(viewportBottomRight).y();
    m_sceneBegin = sceneTopLeft.y();
    m_sceneEnd = sceneBottomRight.y();
    update();
}

void VerticalScale::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black));
    qreal factor = (m_viewportEnd - m_viewportBegin) / (m_sceneEnd - m_sceneBegin);
    qreal begin = m_viewportBegin + factor * (0.0 - m_sceneBegin);
    qreal end = m_viewportBegin + factor * (470 - 1.0 - m_sceneBegin);
    qreal drawBegin = qMax(static_cast<qreal>(m_viewportBegin), begin);
    qreal drawEnd = qMin(static_cast<qreal>(m_viewportEnd), end);
    qreal steps = (m_scaleEnd - m_scaleBegin) / m_step;
    const int firstStep = qCeil(steps * (drawBegin - begin) / (end - begin));
    const int lastStep = qFloor(steps * (drawEnd - begin) / (end - begin - 1));
    painter.drawLine(50.0, drawBegin, 50.0, drawEnd);
    int y;
    for(int i = firstStep; i <= lastStep; ++i)
    {
        y = begin + (end - begin) * i / steps;
        if(i % m_stepsPerLabel == 0)
        {
            painter.drawLine(50, y, 60, y);
            painter.drawText(20, y - 5, 25, 10, Qt::AlignRight | Qt::AlignVCenter, QString::number(m_scaleEnd - i * m_step));
        }
        else
        {
            painter.drawLine(50, y, 55, y);
        }
    }
    painter.rotate(-90);
    painter.drawText(-drawBegin, 0.0, -drawEnd, 20, Qt::AlignTop | Qt::AlignHCenter, "Relative Energy [%]");
}


