#ifndef EVENTO_H
#define EVENTO_H

#include "tempo.h"
#include "queue"
#include "utility"
using namespace std;

class Evento
{
public:
    Evento(){}
    virtual bool run(priority_queue< pair<Time,Evento*> >& fila_de_eventos) = 0;
    bool operator<(const Evento &aNode) const{ return this == &aNode; }
};

typedef pair<Time,Evento*> situacao;

#endif // EVENTO_H
