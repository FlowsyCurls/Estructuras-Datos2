#ifndef CLIENT_H
#define CLIENT_H

//Other
#include <QDebug>
#include <QObject>
#include <QListWidget>

//Json
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

//Sockets
#include <QTableWidget>
#include <QTcpServer>
#include <QTcpSocket>

class QTcpSocket;
class Client : public QTcpSocket
{
    Q_OBJECT
public:
    //constructor
    explicit Client(QObject *parent = nullptr);
    //graph atributes
    QStringList links;

    //methods
    QTableWidget *tableWidget;
    void start(QTableWidget *tableWidget);

private:
    //atributes
    QTcpSocket *cSocket; //variable socket
    QString serverName = "localhost";
    int serverPort = 2100;
    QString ready_Msg = "Ready";
    //methods
    void readyRead();
    void alternative(QJsonObject jsObj);
    void showLinks();
    void setTable(QStringList titles, QStringList routesList, QStringList weigthList);
};

#endif // CLIENT_H
