#include "simulador.h"
#include "algorithm"
#include "dispose.h"
#include "criadouro.h"
#include "estatisticas.h"
#include "distribuicao.h"
#include <iostream>

using namespace std;

volatile bool Simulador::running;
volatile int Simulador::stepsPerSecond;

Simulador::Simulador(Time fimDaSimulacao, int locali[5], double locald[4], int remotoi[5], double remotod[4]) :
    local(locali,locald), remoto(remotoi,remotod)
{
    Criadouro::init();
    cout << "A simulacao vai durar : " << fimDaSimulacao.medida << endl;
    fila_de_eventos.push(make_pair(Time(0), new Criadouro(Time(0), local, remoto)));
    fila_de_eventos.push(make_pair(fimDaSimulacao, new Dispose()));
    Distribuicao::init();
    Estatisticas::limpar();
}

Simulador::~Simulador(){
}

void Simulador::simular(){
    running = true;

    int i = 1;
    cout << "steps:" <<stepsPerSecond << endl;
    while(running && step()){
        cout << i << endl;
        if(i++ >= stepsPerSecond){
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
        s = fila_de_eventos.top();
        fila_de_eventos.pop();

        e = s.second;
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
    stepsPerSecond = s;
}

string Simulador::coletarEstatisticas()
{
    return Estatisticas::toString();
}
