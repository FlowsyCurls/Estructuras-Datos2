#include "util.h"

Util::Util(QObject *parent) : QObject(parent)
{

}

void Util::runServer() {
    server = new Server(this);
    txtFile = new txtManager(fileName);
    this->server->setTxtFile(txtFile);
    if (!server->listen(QHostAddress::Any,2100)) {
        qDebug() << "-> Couldn\'t start Server.";
        return;
    };
    qDebug() << " --- Server Started ---";
    this->server->setTxtFile(this->txtFile);
    //    this->graph->serGraph(this->graph);
}

void Util::createFile() {
    server->createFile();
}








