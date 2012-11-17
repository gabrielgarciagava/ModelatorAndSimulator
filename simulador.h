#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "tempo.h"
#include "evento.h"
#include "queue"
#include "central.h"

class Simulador
{
private:
    Central local;
    Central remoto;
    static volatile bool running;
    priority_queue<situacao> fila_de_eventos;

public:
    Simulador(Time, int, int);
    ~Simulador();
    void simular();
    bool step();
    static void stop();
};

#endif // SIMULADOR_H
