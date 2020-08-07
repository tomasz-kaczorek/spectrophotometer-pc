#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T15:04:24
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Spectrophotometer
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
    ciecolor.cpp \
        mainwindow.cpp \
    servicepanel.cpp \
    spectrophotometer.cpp \
    spectrum.cpp \
    spectrumgraphicsview.cpp \
    tcpclient.cpp \
    verticalscale.cpp \
    horizontalscale.cpp \
    wavelengthscale.cpp

HEADERS  += mainwindow.h \
    ciecolor.h \
    servicepanel.h \
    spectrophotometer.h \
    spectrum.h \
    spectrumgraphicsview.h \
    tcpclient.h \
    verticalscale.h \
    horizontalscale.h \
    wavelengthscale.h
