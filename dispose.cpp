#include "dispose.h"

Dispose::Dispose() : Evento()
{
}

bool Dispose::run(priority_queue<situacao>& fila_de_eventos){
    situacao s;
    Evento* e;
    while(!fila_de_eventos.empty()){
        s = fila_de_eventos.top();
        fila_de_eventos.pop();


        e = s.second;
        delete e;
    }
    return false;
}
