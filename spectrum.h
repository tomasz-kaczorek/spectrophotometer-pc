#ifndef SPECTRUM_H
#define SPECTRUM_H

#include "ciecolor.h"

#include <QByteArray>
#include <QPair>
#include <QVector>

class Spectrum : public QVector<QPair<qreal, qreal>>
{
        public:
                Spectrum();
                Spectrum(QVector<QPair<qreal, qreal>> samples);
                CieColor color();
};

#endif // SPECTRUM_H
