#include "criadouro.h"
#include "distribuicao.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

double Criadouro::media;
int Criadouro::percent_for_LL;
int Criadouro::percent_for_LR;
int Criadouro::percent_for_RL;
int Criadouro::percent_for_RR;

Criadouro::Criadouro(Time tnow, Central &local, Central &remoto) : Evento()
{
    this->tnow = tnow;
    this->local = local;
    this->remoto = remoto;
    srand( time(NULL) );
}

bool Criadouro::run(priority_queue< pair<Time,Evento*> >& fila_de_eventos){
    cout << "Criadouro" << endl;
    Time tnext(tnow.medida + Distribuicao::expo(media));
    int percent, remetente, destinatario;
    percent = rand()%100;

    if(percent < percent_for_LL){
        remetente    = LOCAL;
        destinatario = LOCAL;
        local.receber(new Mensagem(remetente,destinatario, tnow), fila_de_eventos);
    }
    else{
        percent-= percent_for_LL;
        if(percent < percent_for_LR){
            remetente    = LOCAL;
            destinatario = REMOTO;
            local.receber(new Mensagem(remetente,destinatario, tnow),fila_de_eventos);
        }
        else{
            percent-= percent_for_LR;
            if(percent < percent_for_RL){
                remetente    = REMOTO;
                destinatario = LOCAL;
                remoto.receber(new Mensagem(remetente,destinatario, tnow),fila_de_eventos);
            }
            else{
                remetente    = REMOTO;
                destinatario = REMOTO;
                remoto.receber(new Mensagem(remetente,destinatario, tnow),fila_de_eventos);
            }
        }
    }

    fila_de_eventos.push(make_pair(tnext, new Criadouro(tnext, this->local, this->remoto)));
    return true;
}

void Criadouro::set_media(double m)      {media = m;}
void Criadouro::set_percent_for_LL(int p){percent_for_LL = p;}
void Criadouro::set_percent_for_LR(int p){percent_for_LR = p;}
void Criadouro::set_percent_for_RL(int p){percent_for_RL = p;}
void Criadouro::set_percent_for_RR(int p){percent_for_RR = p;}
