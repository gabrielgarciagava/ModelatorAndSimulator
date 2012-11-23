#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "tempo.h"
#include "evento.h"
#include "queue"
#include "central.h"
#include <string>
#include <unistd.h>

class Simulador
{
private:
    Central local;
    Central remoto;
    static volatile bool running;
    priority_queue<situacao> fila_de_eventos;
    static volatile int stepsPerSecond;

public:
    Simulador(Time, int locali[], double locald[], int remotoi[], double remotod[]);
    ~Simulador();
    void simular();
    bool step();
    static void stop();
    void set_stepsPerSeond(int s);
    string coletarEstatisticas();
};

#endif // SIMULADOR_H
