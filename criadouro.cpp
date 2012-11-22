#include "criadouro.h"
#include "distribuicao.h"
#include "estatisticas.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int Criadouro::percent_for_LL;
int Criadouro::percent_for_LR;
int Criadouro::percent_for_RL;
int Criadouro::percent_for_RR;

Criadouro::Criadouro(Time tnow, Central &local, Central &remoto) : Evento()
{
    this->tnow = tnow;
    this->local = local;
    this->remoto = remoto;
}

bool Criadouro::run(priority_queue< pair<Time,Evento*> >& fila_de_eventos){
    cout << "Criadouro" << endl;
    cout << "Inserindo mensagem no sistema" << endl;
    Estatisticas::inserirMensagemSistema(tnow);

    Time tnext(tnow.medida + Distribuicao::expo(media));
    int percent, remetente, destinatario;
    percent = rand()%100;

    if(percent < percent_for_LL){
        remetente    = LOCAL;
        destinatario = LOCAL;
        local.receber(new Mensagem(remetente,destinatario, tnow), fila_de_eventos);

        cout << "Mensagem entrando na Central Local\n";
        Estatisticas::inserirMensagemCentralLocal(tnow);
    }
    else{
        percent-= percent_for_LL;
        if(percent < percent_for_LR){
            remetente    = LOCAL;
            destinatario = REMOTO;
            local.receber(new Mensagem(remetente,destinatario, tnow),fila_de_eventos);

            cout << "Mensagem entrando na Central Local\n";
            Estatisticas::inserirMensagemCentralLocal(tnow);
        }
        else{
            percent-= percent_for_LR;
            if(percent < percent_for_RL){
                remetente    = REMOTO;
                destinatario = LOCAL;
                remoto.receber(new Mensagem(remetente,destinatario, tnow),fila_de_eventos);

                cout << "Mensagem entrando na Central Remota\n";
                Estatisticas::inserirMensagemCentralRemota(tnow);
            }
            else{
                remetente    = REMOTO;
                destinatario = REMOTO;
                remoto.receber(new Mensagem(remetente,destinatario, tnow),fila_de_eventos);

                cout << "Mensagem entrando na Central Remota\n";
                Estatisticas::inserirMensagemCentralRemota(tnow);
            }
        }
    }

    fila_de_eventos.push(make_pair(tnext, new Criadouro(tnext, this->local, this->remoto)));
    return true;
}

//void Criadouro::set_media(double m)      {media = m;}
void Criadouro::set_percent_for_LL(int p){percent_for_LL = p;}
void Criadouro::set_percent_for_LR(int p){percent_for_LR = p;}
void Criadouro::set_percent_for_RL(int p){percent_for_RL = p;}
void Criadouro::set_percent_for_RR(int p){percent_for_RR = p;}

void Criadouro::init()
{
    percent_for_LL = 50;
    percent_for_LR = 25;
    percent_for_RL = 15;
    percent_for_RR = 10;
}
