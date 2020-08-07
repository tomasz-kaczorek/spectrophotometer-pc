#ifndef SPECTRUMGRAPHICSVIEW_H
#define SPECTRUMGRAPHICSVIEW_H

#include "spectrum.h"

#include <QGraphicsView>

class SpectrumGraphicsView : public QGraphicsView
{
        Q_OBJECT

        public:
                SpectrumGraphicsView(QWidget * parent = nullptr);
                void setSpectrum(Spectrum spectrum);
                void resizeEvent(QResizeEvent * event) override;
        signals:
                void visibleRectChanged(QRect, QRectF);
        public slots:
                void visibleRectChanged();
};

#endif // SPECTRUMGRAPHICSVIEW_H
