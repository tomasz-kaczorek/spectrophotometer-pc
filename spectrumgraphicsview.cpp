#include "spectrumgraphicsview.h"

#include <QAbstractSlider>

#include <QScrollBar>

#include <QGraphicsLineItem>

SpectrumGraphicsView::SpectrumGraphicsView(QWidget * parent) :
        QGraphicsView(parent)
{
        setScene(new QGraphicsScene(0., 0., 2200., 1., this));

//        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        connect(verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(visibleRectChanged()));
        connect(verticalScrollBar(), SIGNAL(rangeChanged(int, int)), this, SLOT(visibleRectChanged()));
        connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(visibleRectChanged()));
        connect(horizontalScrollBar(), SIGNAL(rangeChanged(int, int)), this, SLOT(visibleRectChanged()));
}

void SpectrumGraphicsView::setSpectrum(Spectrum spectrum)
{
        QGraphicsScene * s = scene();
        s->clear();
        for(int i = 1; i < spectrum.size(); ++i)
        {
                QGraphicsLineItem * item = new QGraphicsLineItem(spectrum[i - 1].first, 1. - spectrum[i - 1].second, spectrum[i].first, 1. - spectrum[i].second);
                QPen pen(QBrush(Qt::black), 0.0);
                item->setPen(pen);
                s->addItem(item);
        }
}

void SpectrumGraphicsView::resizeEvent(QResizeEvent * event)
{
        QGraphicsView::resizeEvent(event);
        int size = scene()->items().size();
        fitInView(0., 0., size, 1.);
        visibleRectChanged();
}

void SpectrumGraphicsView::visibleRectChanged()
{
        QRect rect = viewport()->rect();
        QRect viewRect(mapToGlobal(rect.topLeft()), mapToGlobal(rect.bottomRight()));
        QRectF sceneRect(mapToScene(rect.topLeft()), mapToScene(rect.bottomRight()));
        emit visibleRectChanged(viewRect, sceneRect);
}

