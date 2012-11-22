#include "simulador.h"
#include "algorithm"
#include "dispose.h"
#include "criadouro.h"
#include <iostream>

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

    int i = 1;
    cout << "steps:" <<stepsPerSecond << endl;
    while(running && step()){
        cout << i << endl;
        if(i++ > stepsPerSecond){
            sleep(1);
            i = 0;
        }
        cout << endl;
    }
}

bool Simulador::step(){
    situacao s;
    Evento* e;
    bool on_execution = !fila_de_eventos.empty();

    cout << "Iniciando step" << endl;
    if(on_execution){
        cout << "top" << endl;
        s = fila_de_eventos.top();
        cout << "tempo: " << s.first.medida << endl;
        fila_de_eventos.pop();
        cout << "pop realizado" << endl;

        e = s.second;
        cout << "Vair rodar um evento" << endl;
        on_execution = e->run(fila_de_eventos);
        cout << "Evento executado" << endl;
    }
    return on_execution;
}

void Simulador::stop(){
    running = false;
}

void Simulador::set_stepsPerSeond(int s)
{
    stepsPerSecond == s;
}
