/**
  * @file server.h
  * @version 1.0
  * @date 02/03/2020
  * @brief Server Class: Socket to connect to clients.
  */


#ifndef SERVER_H
#define SERVER_H

//Other
#include <QDebug>
#include <QObject>
//Json
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
//Sockets
#include <QTcpServer>
#include <QTcpSocket>

#include "txtmanager.h"
#include "graph.h"

class txtManager;

class Server : public QTcpServer
{
    Q_OBJECT

public:
//constructor
    explicit Server(QObject *parent = nullptr);

//methods


    /**
     * @brief send Encapsula datos en un JsonDocument y los escribe al socket.
     * @param data JsonObject que encapsula los datos a enviar.
     */
    void send(const QJsonObject data);

    /**
     * @brief createFile Crea un archivo txt si no existe uno.
     */
    void createFile();

    /**
     * @brief setTxtFile Setter de la variable *txtFile
     * @param value Valor a otorgar a la variable.
     */
    void setTxtFile(txtManager *value);

private:
    //server atributes
    QTcpSocket *sSocket;

    //txt atributes
    txtManager *txtFile;

    //graph atributes
    QStringList strList, nodesList;
    QString strLinks, titles, V_str;
    Graph *g;

    /**
     * @brief setGraph Carga toda la información del grafo
     * y agrega las rutas y pesos entre ellos.
     */
    void setGraph();

    //methods

    /**
     * @brief readyRead Espera una lectura en el socket
     */
    void readyRead();
    /**
     * @brief alternative Función condicional que decide qué hacer
     * dependiendo de la información obtenida por el cliente.
     * @param jsObj
     */
    void alternative(QJsonObject jsObj);
    /**
     * @brief uploadFile Lee el archivo txt y carga el
     * algorithmo dijsktra a una variable global.
     */
    void uploadFile();
    /**
     * @brief nodesNames Función para obtener el nombre de todos los
     * vertices, analizando los vertices presentes en cada ruta.
     * @param start vertice inicial.
     * @param end vertice final.
     */
    void nodesNames(QString start, QString end);
    /**
     * @brief getRoutes Concatena las rutas de forma tal
     * para enviarlas por el socket server y las escribe en
     * una variable global.
     */
    void getRoutes();
    /**
     * @brief getJsonData A partir de lo escrito en la función
     * getRoutes, se contruye un JsonObject.
     * @return
     */
    QJsonObject getJsonData();

};

#endif // SERVER_H
