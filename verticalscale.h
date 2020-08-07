#ifndef VERTICALSCALE_H
#define VERTICALSCALE_H

#include <QWidget>

class VerticalScale : public QWidget
{
    Q_OBJECT
public:
    VerticalScale(qreal scaleBegin, qreal scaleEnd, qreal step, int stepsPerLabel, QWidget * parent = nullptr);
private:
    qreal m_scaleBegin;
    qreal m_scaleEnd;
    qreal m_step;
    int m_stepsPerLabel;
    int m_viewportBegin;
    int m_viewportEnd;
    qreal m_sceneBegin;
    qreal m_sceneEnd;
public slots:
    void visibleRectChanged(QPoint viewportTopLeft, QPoint viewportBottomRight, QPointF sceneTopLeft, QPointF sceneBottomRight);
protected: //QWidget
    virtual void paintEvent(QPaintEvent * event) override;
};

#endif // VERTICALSCALE_H
