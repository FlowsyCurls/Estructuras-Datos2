#include <utility>

#include "Product.h++"
Product::Product(string n) {
    this->name=move(n);
}
void Product::update(int price) {
    cout << name + " price:" + to_string(price);
}