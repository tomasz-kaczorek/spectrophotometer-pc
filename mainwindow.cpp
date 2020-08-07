#include "mainwindow.h"

#include "servicepanel.h"
#include "spectrophotometer.h"
#include "tcpclient.h"

#include <QMenu>
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
        mServicePanel = new ServicePanel();
        mSpectrophotometer = new Spectrophotometer();
        mTcpClient = new TcpClient();
        setCentralWidget(mSpectrophotometer);

        QMenu * fileMenu = menuBar()->addMenu("File");
        QAction * newAction = new QAction("New", this);
        connect(newAction, SIGNAL(triggered()), mSpectrophotometer, SLOT(fileNew()));
        connect(newAction, SIGNAL(triggered()), mTcpClient, SLOT(requestSample()));
        connect(mTcpClient, SIGNAL(responseSample(QVector<unsigned>)), mSpectrophotometer, SLOT(textSample(QVector<unsigned>)));
        connect(mSpectrophotometer, SIGNAL(forwardRequest(int)), mTcpClient, SLOT(requestForward(int)));
        connect(mSpectrophotometer, SIGNAL(backwardRequest(int)), mTcpClient, SLOT(requestBackward(int)));
        connect(mSpectrophotometer, SIGNAL(gainRequest(int)), mTcpClient, SLOT(requestGain(int)));
        fileMenu->addAction(newAction);
}

MainWindow::~MainWindow()
{

}
