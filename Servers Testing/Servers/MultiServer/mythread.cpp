#include "mythread.h"

MyThread::MyThread(int ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    // thread starts here
    qDebug() << socketDescriptor << " Starting thread";
    socket = new QTcpSocket();
    //setting the socket Descriptor for the tcpSocket.
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }
    //setting the signalsocket.
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(readyRead()),Qt::DirectConnection);
    connect(this->socket, SIGNAL(disconnected()), this, SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    // make this thread a loop
    exec();
}

//read the request from the clients & server.
void MyThread::readyRead()
{
    QByteArray Data = socket->readAll();
    qDebug() << socketDescriptor << " Data in: " << Data;
    socket->write(Data);
}

void MyThread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    socket->deleteLater();
    exit(0);
}

