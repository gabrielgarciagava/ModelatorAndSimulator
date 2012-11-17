#ifndef DISPOSE_H
#define DISPOSE_H

#include "evento.h"

class Dispose : public Evento
{
public:
    Dispose();
    bool run(priority_queue<situacao>& fila_de_eventos);
    bool operator<(const Evento &aNode) const{ return this == &aNode; }
};

#endif // DISPOSE_H
