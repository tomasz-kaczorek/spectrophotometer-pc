#ifndef WAVELENGTHSCALE_H
#define WAVELENGTHSCALE_H

#include <QWidget>

class WavelengthScale : public QWidget
{
        Q_OBJECT
        public:
                WavelengthScale(QWidget * parent = nullptr);
        protected:
                virtual void paintEvent(QPaintEvent * event) override;
        private:
                QRect mViewRect;
                QRectF mSceneRect;
        public slots:
                void visibleRectChanged(QRect viewRect, QRectF sceneRect);
};

#endif // WAVELENGTHSCALE_H
