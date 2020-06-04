#ifndef TXTMANAGER_H
#define TXTMANAGER_H

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <iostream>

class QFile;

class txtManager
{
public:
    txtManager(QString fileName);

    QFile *file;
    void create();
    void write(QString text);
    QString read();
    QStringList toQStringList(QString str);

private:
    QString path = "/home/shakime/AA-Repos/Datos2/T-01/Resources/";
    bool exist();
};
#endif // TXTMANAGER_H
