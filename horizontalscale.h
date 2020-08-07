#ifndef HORIZONTALSCALE_H
#define HORIZONTALSCALE_H

#include <QWidget>

class HorizontalScale : public QWidget
{
    Q_OBJECT
public:
    HorizontalScale(qreal scaleBegin, qreal scaleEnd, qreal step, int stepsPerLabel, QWidget * parent = nullptr);
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

#endif // HORIZONTALSCALE_H
