#include "Bookshop.h++"

void Bookshop::Attach(Observer *obs) {
    observers.push_back(obs);
}
void Bookshop::Detach(Observer *obs) {
    for(int i=0;i<observers.size();i++){
        if(obs==observers[i])
            observers.erase(observers.begin()+i);
    }
}
void Bookshop::notify() {
    for(Observer *observer : observers){
        observer->update(price);
    }
}
void Bookshop::setState(int price) {
    this->price=price;
    notify();
}

