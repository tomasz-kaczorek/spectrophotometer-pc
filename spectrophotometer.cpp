#include "spectrophotometer.h"

#include "horizontalscale.h"
#include "verticalscale.h"
#include "wavelengthscale.h"
#include "spectrumgraphicsview.h"
#include "spectrum.h"

#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QtMath>

#include <QDebug>

Spectrophotometer::Spectrophotometer(QWidget *parent) :
        QWidget(parent),
        mSpectrumGraphicsView(new SpectrumGraphicsView()),
        newButton(new QPushButton("new")),
        prependButton(new QPushButton("prepend")),
        appendButton(new QPushButton("append")),
        forwardButton(new QPushButton("forward")),
        backwardButton(new QPushButton("backward")),
        gainButton(new QPushButton("gain")),
        newSpinBox(new QSpinBox()),
        prependSpinBox(new QSpinBox()),
        appendSpinBox(new QSpinBox()),
        forwardSpinBox(new QSpinBox()),
        backwardSpinBox(new QSpinBox()),
        gainSpinBox(new QSpinBox())
{
//    VerticalScale * vertical = new VerticalScale(0., 100., 2, 5);
//   WavelengthScale * wavelenth = new WavelengthScale();

//    connect(mSpectrumGraphicsView, SIGNAL(visibleRectChanged(QRect,QRectF)), vertical, SLOT(visibleRectChanged(QPoint,QPoint,QPointF,QPointF)));
//   connect(mSpectrumGraphicsView, SIGNAL(visibleRectChanged(QRect,QRectF)), wavelenth, SLOT(visibleRectChanged(QRect,QRectF)));

        connect(forwardButton, SIGNAL(clicked()), this, SLOT(forward()));
        connect(backwardButton, SIGNAL(clicked()), this, SLOT(backward()));
        connect(gainButton, SIGNAL(clicked()), this, SLOT(gain()));

        forwardSpinBox->setRange(0, 10000);
        backwardSpinBox->setRange(0, 10000);
        gainSpinBox->setRange(0, 1000);


    QGridLayout * layout = new QGridLayout();
    layout->addWidget(mSpectrumGraphicsView, 0, 0, 1, 4);
    layout->addWidget(newSpinBox, 1, 0);
    layout->addWidget(newButton, 2, 0);
    layout->addWidget(forwardSpinBox, 1, 1);
    layout->addWidget(forwardButton, 2, 1);
    layout->addWidget(backwardSpinBox, 1, 2);
    layout->addWidget(backwardButton, 2, 2);
    layout->addWidget(gainSpinBox, 1, 3);
    layout->addWidget(gainButton, 2, 3);
//    layout->addWidget(prependButton, 1, 1);
//    layout->addWidget(prependSpinBox, 1, 2);
//    layout->addWidget(appendButton, 2, 1);
//    layout->addWidget(appendSpinBox, 2, 2);

    setLayout(layout);
}

void Spectrophotometer::fileNew()
{

}

void Spectrophotometer::fileOpen()
{

}

void Spectrophotometer::fileSave()
{

}

void Spectrophotometer::forward()
{
        emit forwardRequest(forwardSpinBox->value());
}

void Spectrophotometer::backward()
{
        emit backwardRequest(backwardSpinBox->value());
}

void Spectrophotometer::gain()
{
        emit gainRequest(gainSpinBox->value());
}

void Spectrophotometer::textSample(QVector<unsigned> samples)
{
        Spectrum spectrum;
        qreal max = 0.;
        for(int i = 0; i < samples.size(); ++i)
        {
                if(samples[i] > max) max = samples[i];
        }
        for(int i = 0; i < samples.size(); ++i)
        {
                spectrum.append(QPair<qreal, qreal>(i, samples[i] / max));
        }
        mSpectrumGraphicsView->setSpectrum(spectrum);
}

