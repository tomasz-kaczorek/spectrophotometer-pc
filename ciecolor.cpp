#include "ciecolor.h"

CieColor::CieColor(qreal x, qreal y, qreal z)
{
        mX = x;
        mY = y;
        mZ = z;
        setRgb(0, 0, 0);
}
