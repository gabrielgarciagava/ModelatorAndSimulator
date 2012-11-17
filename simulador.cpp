#include "simulador.h"
#include "algorithm"
#include "dispose.h"
#include "criadouro.h"
using namespace std;

volatile bool Simulador::running;

Simulador::Simulador(Time fimDaSimulacao, int serv_local, int serv_remoto) : local(serv_local), remoto(serv_remoto)
{
    fila_de_eventos.push(make_pair(Time(0), new Criadouro(Time(0), local, remoto)));
    fila_de_eventos.push(make_pair(fimDaSimulacao, new Dispose()));
}

Simulador::~Simulador(){
}

void Simulador::simular(){
    running = true;

    while(running && step());
}

bool Simulador::step(){
    situacao s;
    Evento* e;
    bool on_execution = !fila_de_eventos.empty();

    if(on_execution){
        s = fila_de_eventos.top();
        fila_de_eventos.pop();

        e = s.second;
        on_execution = e->run(fila_de_eventos);
    }
    return on_execution;
}

void Simulador::stop(){
    running = false;
}
