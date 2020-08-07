#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>

class QTcpSocket;

class TcpClient : public QObject
{
        Q_OBJECT
        public:
                TcpClient();
        private:
                QTcpSocket * mSocket;
        signals:
                void responseSample(QVector<unsigned>);
        public slots:
                void processResponse();
                void requestSample();
                void requestForward(int);
                void requestBackward(int);
                void requestGain(int);
};

#endif // TCPCLIENT_H
