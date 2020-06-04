#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <QDebug>
#include "mythread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);
    void StartServer();
    
signals:
    
public slots:

protected:
    void incomingConnection(int socketDescriptor);
private:
    int port = 12345;
    
};

#endif // MYSERVER_H
