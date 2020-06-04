#include "myserver.h"

MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

void MyServer::StartServer()
{
    if(!this->listen(QHostAddress::LocalHost, this->port)) //
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening... \n Adress: "
                 << QHostAddress::LocalHost << "  -  Port: " << this->port;
    }
}

void MyServer::incomingConnection(int socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    //Thread is created when any client is connected to the server.
    MyThread *thread = new MyThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
