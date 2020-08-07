#ifndef SPECTROPHOTOMETER_H
#define SPECTROPHOTOMETER_H

#include "spectrum.h"

#include <QWidget>

class QPushButton;
class QSpinBox;
class SpectrumGraphicsView;

class Spectrophotometer : public QWidget
{
    Q_OBJECT
public:
    explicit Spectrophotometer(QWidget *parent = nullptr);
        private:
                SpectrumGraphicsView * mSpectrumGraphicsView;
                QPushButton * newButton;
                QPushButton * prependButton;
                QPushButton * appendButton;
                QPushButton * forwardButton;
                QPushButton * backwardButton;
                QPushButton * gainButton;
                QSpinBox * newSpinBox;
                QSpinBox * prependSpinBox;
                QSpinBox * appendSpinBox;
                QSpinBox * forwardSpinBox;
                QSpinBox * backwardSpinBox;
                QSpinBox * gainSpinBox;
signals:
                void forwardRequest(int);
                void backwardRequest(int);
                void gainRequest(int);
public slots:
    void fileNew();
    void fileOpen();
    void fileSave();
    void forward();
    void backward();
    void gain();
    void textSample(QVector<unsigned> samples);
};

#endif // SPECTROPHOTOMETER_H
