#include "util.h"


Util::Util(QObject *parent) : QObject(parent)
{

}

void Util::runClient()
{
    client = new Client(this);
}

void Util::start(QTableWidget *tableWidget) {
    client->start(tableWidget);


}


