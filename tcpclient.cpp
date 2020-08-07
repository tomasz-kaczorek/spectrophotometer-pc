#include "tcpclient.h"

#include <QTcpSocket>

#include <QDebug>

TcpClient::TcpClient() :
        mSocket(new QTcpSocket(this))
{
        connect(mSocket, SIGNAL(readyRead()), this, SLOT(processResponse()));
        //mSocket->connectToHost("10.3.14.15", 31415);
        mSocket->connectToHost("0.0.0.0", 31415);
}

void TcpClient::processResponse()
{
        QByteArray response = mSocket->peek(100000);
        for(int i = 1; i < response.size(); ++i)
        {
                if(response[i] == '\n' && response[i - 1] == '\n')
                {
                        response = mSocket->read(i + 1);
                        if(response.startsWith("SAMPLE-RESPONSE"))
                        {
                                qDebug()<<response;
                                response = response.trimmed();
                                response = response.mid(response.indexOf(':') + 1);
                                QList<QByteArray> samples = response.split(',');
                                QVector<unsigned> ret;
                                for(int i = 0; i < samples.size(); ++i)
                                {
                                        ret.append(samples[i].toUInt());
                                }
                                emit responseSample(ret);
                        }
                }
        }
}

void TcpClient::requestSample()
{
        mSocket->write("SAMPLE-REQUEST\ncount:2200\n\n");
}

void TcpClient::requestForward(int steps)
{
        QByteArray message("MOTOR-REQUEST\ndirection:red-blue\nactive:high\nsteps:");
        message.append(QByteArray::number(steps));
        message.append("\nactive:low\n\n");
        qDebug()<<message;
        mSocket->write(message);
}

void TcpClient::requestBackward(int steps)
{
        QByteArray message("MOTOR-REQUEST\ndirection:blue-red\nactive:high\nsteps:");
        message.append(QByteArray::number(steps + 400));
        message.append("\ndirection:red-blue\nsteps:400\nactive:low\n\n");
        qDebug()<<message;
        mSocket->write(message);
}

void TcpClient::requestGain(int gain)
{
        QByteArray message("AMP-REQUEST\ngain:");
        message.append(QByteArray::number(gain));
        message.append("\n\n");
        qDebug()<<message;
        mSocket->write(message);
}

