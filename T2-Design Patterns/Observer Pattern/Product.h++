#ifndef DATOS_2___2_0_PRODUCTO_H
#define DATOS_2___2_0_PRODUCTO_H
#include <iostream>
#include <string>
#include "Observer.h++"

using namespace std;
class Product: public Observer{
    string name;
public:
    explicit Product(string nombre);
    void update(int price) override;
};

#endif //DATOS_2___2_0_PRODUCTO_H
