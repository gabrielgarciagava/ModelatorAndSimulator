#include "tempo.h"

Time::Time(){
    this->medida = -1;
}

Time::Time(double medida){
    this->medida = medida;
}

bool Time::operator<(const Time &aNode) const{
    return this->medida > aNode.medida;
}

Time& Time::operator=(const Time& other){
    if(this != &other){
        medida = other.medida;
    }
    return *this;
}

