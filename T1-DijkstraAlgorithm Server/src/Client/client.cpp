#include "client.h"

Client::Client(QObject *parent) : QTcpSocket(parent) {
    cSocket=new QTcpSocket(this);
    cSocket->connectToHost(this->serverName,this->serverPort);
    qDebug() << "-> Joined!";
    connect(cSocket,&QTcpSocket::readyRead,[&](){ //read current socket
        readyRead();
    });
}

void Client::readyRead() {
    connect(cSocket, &QTcpSocket::readyRead, [&] (){ //start reading
        QString data = cSocket->readAll();
        QJsonDocument jsDoc = QJsonDocument::fromJson(data.toLatin1()); //provides a way to read and write JSON documents
        QJsonArray jsArray = jsDoc.array(); //encapsulates a JSON array.
        QJsonObject jsObject = jsArray.first().toObject(); //encapsulates a JSON object.
        qDebug() << "\n~R  >> " << jsObject;
        alternative(jsObject);
    });
}

void Client::start(QTableWidget *tableWidget) {
    QJsonObject specs{
        {ready_Msg, "true"}
    }; //start message.
    QJsonArray jsArray {specs};
    QJsonDocument jsDoc(jsArray);
    QString jsString = QString::fromLatin1(jsDoc.toJson());
    qDebug()<< "\n~S  >> " << jsDoc;
    cSocket->write(jsString.toLatin1());
    cSocket->flush();
    this->cSocket->waitForBytesWritten(3000);
    this->tableWidget = tableWidget;
    readyRead();
}

void Client::alternative(QJsonObject jsObj){
    if (jsObj.contains("links")){
        links = jsObj.value("links").toString().split("|",QString::SkipEmptyParts);
        showLinks();
    }
}

void Client::showLinks() {
    QStringList titles,routesList, weightList;
    titles = links.first().split(",",QString::SkipEmptyParts); // titles ("Route", "Weight")
    qDebug() << "Titles >"<< titles;
    QStringList pages = links.last().split(" ",QString::SkipEmptyParts); // pages ("0:0,0;1,1;2,4", "1:0,4;1,3;2,0", "2:0,1;1,0;2,3")
//    qDebug() << "\nPages >"<< pages;
    for (int i=0; i<links.length(); i++){
        QString origin;
        QStringList pair, groupRoutes;
        pair = pages.at(i).split(":",QString::SkipEmptyParts); //
        origin = pair.first(); // pages = { "titles" , "0" , "1,3;4,1" }
        groupRoutes = pair.last().split(";",QString::SkipEmptyParts); // groupRoutes ("0,0", "1,1", "2,4")
        qDebug() << "\nOrigin >"<< origin;
        qDebug() << "GroupRoutes >"<< groupRoutes;

        for (int e =0; e<groupRoutes.length(); e++) {
            QStringList data = groupRoutes.at(e).split(","); // split2 = { ("1","3) , ("4","1") }
            routesList.append(origin + "  ⮕  " + data.at(0));
            weightList.append(" ► "+data.at(1));
        }
        qDebug() << "\n< RoutesList  " << routesList;
        qDebug() << "\n< WeightList  " << weightList;
    } setTable(titles, routesList, weightList);
}

void Client::setTable(QStringList titles, QStringList routesList, QStringList weigthList) {
    tableWidget->clear();
    tableWidget->setColumnCount(titles.length());
    tableWidget->setHorizontalHeaderLabels(titles);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //no editable
    double  ii = tableWidget->width(); //column sizes
    tableWidget->setColumnWidth(0,0.7*ii);
    tableWidget->setColumnWidth(1,0.3*ii);

    for (int z=0; z < routesList.length(); z++) {
        tableWidget->insertRow(tableWidget->rowCount());
        int row =tableWidget->rowCount()-1;
        for (int i=0; i<=titles.length(); i+=2){
            tableWidget->setItem(row, i, new QTableWidgetItem(routesList.at(z)));
//            qDebug() << "\n< RoutesList  " << routesList.at(z);
            tableWidget->setItem(row, i+1, new QTableWidgetItem(weigthList.at(z)));
//            qDebug() << "\n< WeightList  " << weigthList.at(z);
        }
    }
}

