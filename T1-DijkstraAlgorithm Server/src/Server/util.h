#ifndef UTIL_H
#define UTIL_H

#include <QObject>
//#include <QTcpSocket>

#include "server.h"


//util classes
//class QTcpSocket;
class Server;

class Util : public QObject
{
    Q_OBJECT

public:
    //constructor
    explicit Util(QObject *parent = nullptr);

    //methods
    void runServer();
    void createFile();

private:
    //server atributes
    Server *server;
    //txt atributes
    txtManager *txtFile;
    QString fileName = "graph.txt";

};

#endif // UTIL_H
