#ifndef CIECOLOR_H
#define CIECOLOR_H

#include <QColor>

class CieColor: public QColor
{
        public:
                CieColor(qreal x, qreal y, qreal z);
        private:
                qreal mX;
                qreal mY;
                qreal mZ;
};

#endif // CIECOLOR_H
