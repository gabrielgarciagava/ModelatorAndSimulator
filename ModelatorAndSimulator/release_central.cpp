#include "release_central.h"
#include <iostream>

Release_Central::Release_Central(Central &central, Mensagem* msg) : Evento()
{
    this->central = central;
    this->msg     = msg;
}
bool Release_Central::run(priority_queue<situacao>& fila_de_eventos){
    cout << "Release" << endl;
    central.processar(msg, fila_de_eventos);
    return true;
}
