#include "wavelengthscale.h"

#include <QtMath>
#include <QPainter>

WavelengthScale::WavelengthScale(QWidget * parent) :
        QWidget(parent)
{
       setFixedHeight(55);
}

void WavelengthScale::paintEvent(QPaintEvent *)
{
        QPainter painter(this);
        painter.setPen(QPen(Qt::black));
        qreal factor = (mViewRect.right() - mViewRect.left()) / (mSceneRect.right() - mSceneRect.left());
        qreal begin = mViewRect.left() - factor * mSceneRect.left();
        qreal end = mViewRect.left() + factor * (470 - mSceneRect.left());
        qreal drawBegin = qMax(static_cast<qreal>(mViewRect.left()), begin);
        qreal drawEnd = qMin(static_cast<qreal>(mViewRect.right()), end);
        int steps = 47;
        int firstStep = qCeil(steps * (drawBegin - begin) / (end - begin));
        int lastStep = qFloor(steps * (drawEnd - begin) / (end - begin - 1));
        painter.drawLine(static_cast<int>(drawBegin), 10, static_cast<int>(drawEnd), 10);
        int x;
        for(int i = firstStep; i <= lastStep; ++i)
        {
            x = static_cast<int>(begin + (end - begin) * i / steps);
            if((i + 6) % 10 == 0)
            {
                painter.drawLine(x, 0, x, 10);
                painter.drawText(x - 30, 15, 60, 25, Qt::AlignTop | Qt::AlignHCenter, QString::number(360 + i * 10));
            }
            else
            {
                painter.drawLine(x, 5, x, 10);
            }
        }
        painter.drawText(drawBegin, 35, drawEnd - drawBegin, 45, Qt::AlignTop | Qt::AlignHCenter, "Wavelength [nm]");
}

void WavelengthScale::visibleRectChanged(QRect viewRect, QRectF sceneRect)
{
        mViewRect = QRect(mapFromGlobal(viewRect.topLeft()), mapFromGlobal(viewRect.bottomRight()));
        mSceneRect = sceneRect;
        update();
}
