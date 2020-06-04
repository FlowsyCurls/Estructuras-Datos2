#ifndef UTIL_H
#define UTIL_H

#include <QObject>
#include <QTableWidget>

#include "client.h"


//util classes.
class Client;

class Util : public QObject
{
    Q_OBJECT
public:
    //constructor
    explicit Util(QObject *parent = nullptr);
    //methods
    void runClient();
    void start(QTableWidget *tableWidget);

private:
    //atributes
    Client *client;



};

#endif // UTIL_H
