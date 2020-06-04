#include "server.h"


Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    this->sSocket=nullptr; //init socket as null
    //waittoconnect and start reading.
    connect(this, &Server::newConnection,[&](){
        sSocket = nextPendingConnection(); //next client
        qDebug() << "->" << sSocket->socketDescriptor() << "joined!";
        readyRead();
    });
}

//READ SOCKET
void Server::readyRead(){
    connect(sSocket, &QTcpSocket::readyRead, [&] (){ //start reading
        QString data = sSocket->readAll();
        QJsonDocument jsDoc = QJsonDocument::fromJson(data.toLatin1()); //provides a way to read and write JSON documents
        QJsonArray jsArray = jsDoc.array(); //encapsulates a JSON array.
        QJsonObject jsObject = jsArray.first().toObject(); //encapsulates a JSON object.
        qDebug() << "\n~R  >> " << jsObject;
        alternative(jsObject);
    });
}

//Options according to the entry.
void Server::alternative(QJsonObject jsObj){
    QString value = jsObj.value("Ready").toString();
    if (value != "true") {
        return;
    }
    qDebug() << "";
    uploadFile(); //upload graph form txtfile
    setGraph(); //create graph and apply dijkstra algorithm, set the string to parse to json
    send(getJsonData());

}

void Server::setGraph() {
    titles = this->strList.at(0); //titles at index 0/
    V_str = this->strList.at(1); //vertex at index 1/
    this->g = new Graph(V_str.toInt()); //create Graph
    qDebug() << "< Graph created >>  nºV =" << V_str.toInt() <<"\n";
    QStringList nodes = this->strList.at(2).split(","); //nodes at index 2/
    for (int i=0; i<nodes.length(); i++) {
        QStringList routes = nodes.at(i).split(" ");
        int start = routes.at(0).toInt(); //start position
        int end = routes.at(1).toInt(); //end position
        int weight = routes.at(2).toInt(); //weight between start and end
//        qDebug() << "<ROUTES" << "> i:" <<i <<"| " << routes;
        g->addEdge(start, end, weight);
        nodesNames(routes.at(0),routes.at(1));
    }
    qDebug() << "<   nodesNames" <<nodesList;
    this->getRoutes();
}

void Server::nodesNames(QString start, QString end){
    if (!nodesList.contains(start)){
        nodesList.append(start);
    } else if (!nodesList.contains(end)){
        nodesList.append(end);
    }
}

void Server::getRoutes(){
    QString links, begin; // V1:S1,W1;S2,W2;S3,W3 V2:S1,W1;S2,W2;S3,W3
    links.append(titles + "|");
    for (int i=0; i<nodesList.length();i++){
        begin.setNum(i);
        links.append(begin+":");
        QString path = g->shortestPath(nodesList.at(i).toInt());
        links.append(path);
        links.append(" ");
    }
    qDebug() <<"\n< links > " << links;
    this->strLinks = links;
}


//AuxMethod -> Json for graph info.
QJsonObject Server::getJsonData(){
    //crear objeto Json.
    QJsonObject jsData{
        {"links",strLinks}
    };
//    qDebug() <<"\nJsData >> " << jsData;
    return jsData;
}

//WRITE SOCKET
void Server::send(const QJsonObject data){
    QJsonArray jsArray {data};
    QJsonDocument jsDoc(jsArray);
    QString jsString = QString::fromLatin1(jsDoc.toJson()); //parsing.
    qDebug()<< "\n~S  >> " << jsDoc;
    sSocket->write(jsString.toLatin1());
    sSocket->flush();
    this->sSocket->waitForBytesWritten(3000);
//    readyRead();
}



//txt setter
void Server::setTxtFile(txtManager *value){
    txtFile = value;
}

//Create Blank txtFile
void Server::createFile() {
    txtFile->create();
}

//Upload txt File
void Server::uploadFile() {
    QString str = txtFile->read();
    this->strList = txtFile->toQStringList(str);
    qDebug() << "\n --- File Uploaded ---\n<" << strList;
}

