#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ServicePanel;
class Spectrophotometer;
class TcpClient;

class QToolBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
        Spectrophotometer * mSpectrophotometer;
        ServicePanel * mServicePanel;
        TcpClient * mTcpClient;
};

#endif // MAINWINDOW_H
