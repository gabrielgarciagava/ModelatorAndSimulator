#ifndef RELEASE_CENTRAL_H
#define RELEASE_CENTRAL_H

#include "evento.h"
#include "central.h"
#include "mensagem.h"

class Release_Central : public Evento
{
    Central central;
    Mensagem* msg;
public:
    Release_Central(Central& central, Mensagem* msg);
    bool run(priority_queue<situacao>& fila_de_eventos);
    bool operator<(const Evento &aNode) const{ return this == &aNode; }
};

#endif // RELEASE_CENTRAL_H
