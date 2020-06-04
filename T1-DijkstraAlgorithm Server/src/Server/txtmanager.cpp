#include "txtmanager.h"

txtManager::txtManager(QString fileName)
{
    //Pointer file's name.
    this->file = new QFile(path+fileName);
}

//Verify file existence.
bool txtManager::exist() {
    if(!file->exists()) {
        qDebug() <<this->file->fileName() << " file NOT FOUND";
        return false;
    } else {
        return true;
    }
}

//Create new file.
void txtManager::create() {
    if (file->exists()){
        return;
    }
    try {
        if(file->open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream txtStream(file);
            txtStream << "A,B\n"
                         "C,D\n"
                         "D,A\n"
                         "B,E\n";
        } file->close(); //close file.
        qDebug() << "\n --- File Created ---";
    } catch (int e) {
        qDebug() << "\n  Exception Nr. " << e << "'\nCould\'nt create file.";
    } return;
}

//ReadOnly.
QString txtManager::read(){
    if (!exist()){
        return NULL;
    }
    file->open(QIODevice::ReadOnly); //open file : mode ReadOnly.
    QTextStream inner(file);
    qDebug() << "\n --- Reading file ---";
    QString unsplited;
    inner.seek(0);
    while(!inner.atEnd()) { //bucle for reading
        unsplited.append(inner.readAll()); // readAll();
    } file->close(); //close file.
    qDebug() << "< Unsplited >> " << unsplited;
    return unsplited;
}

//AuxMethod -> String to StringList
QStringList txtManager::toQStringList(QString str){

    QStringList list = str.split("\n", QString::SkipEmptyParts);
    QString data;
    data.append(list.at(0)+"|"+(list.at(1)+"|")); //adding "tittles" | "vertex " |
    int i=2; //index where routes start.
    //printing
    while (i!=list.length()){
        qDebug() << list.at(i);
        data.append(list.at(i));
        if ((i+1)!=list.length()) data.append(",");
        i++;
    }
    return data.split("|");
}

//WriteOnly.
void txtManager::write(QString text){
    if (!exist())
        return;
    file->open(QIODevice::WriteOnly); //open file : mode WriteOnly.
    QTextStream txtStream(file);
    qDebug() << "--- Writing to file ---";
    txtStream << text;
    file->close(); //close file.
}
