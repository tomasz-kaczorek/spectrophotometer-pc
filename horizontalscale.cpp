#include "horizontalscale.h"

#include <qmath.h>
#include <QPainter>

HorizontalScale::HorizontalScale(qreal scaleBegin, qreal scaleEnd, qreal step, int stepsPerLabel, QWidget * parent) :
    QWidget(parent),
    m_scaleBegin(scaleBegin),
    m_scaleEnd(scaleEnd),
    m_step(step),
    m_stepsPerLabel(stepsPerLabel)
{
    setFixedHeight(55.0);
}

void HorizontalScale::visibleRectChanged(QPoint viewportTopLeft, QPoint viewportBottomRight, QPointF sceneTopLeft, QPointF sceneBottomRight)
{
    m_viewportBegin = mapFromGlobal(viewportTopLeft).x();
    m_viewportEnd = mapFromGlobal(viewportBottomRight).x();
    m_sceneBegin = sceneTopLeft.x();
    m_sceneEnd = sceneBottomRight.x();
    update();
}

void HorizontalScale::paintEvent(QPaintEvent *)
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
    painter.drawLine(static_cast<int>(drawBegin), 10.0, static_cast<int>(drawEnd), 10.0);
    int x;
    for(int i = firstStep; i <= lastStep; ++i)
    {
        x = static_cast<int>(begin + (end - begin) * i / steps);
        if(i % m_stepsPerLabel == 0 || i == firstStep || i == lastStep)
        {
            painter.drawLine(x, 0, x, 10);
            painter.drawText(x - 30, 15, 60, 25, Qt::AlignTop | Qt::AlignHCenter, QString::number(m_scaleBegin + i * m_step));
        }
        else
        {
            painter.drawLine(x, 5, x, 10);
        }
    }
    painter.drawText(static_cast<int>(drawBegin), 35, static_cast<int>(drawEnd) - static_cast<int>(drawBegin), 45, Qt::AlignTop | Qt::AlignHCenter, "Wavelength [nm]");
}


