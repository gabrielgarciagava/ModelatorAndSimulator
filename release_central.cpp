#include "release_central.h"

Release_Central::Release_Central(Central &central, Mensagem* msg) : Evento()
{
    this->central = central;
    this->msg     = msg;
}
bool Release_Central::run(priority_queue<situacao>& fila_de_eventos){
    central.processar(msg, fila_de_eventos);
    return true;
}
