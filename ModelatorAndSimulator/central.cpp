#include "central.h"
#include <stdlib.h>
#include <time.h>
#include "distribuicao.h"
#include "release_central.h"

double Central::_inf[2];
double Central::_sup[2];
int Central::percent_for_SUCESSO;
int Central::percent_for_FRACASSO;
int Central::percent_for_ADIAMENTO;

Central::Central(){
}
Central::Central(int total_servidores)
{
    this->total_servidores = total_servidores;
    this->servidores_livre = total_servidores;
    srand( time(NULL) );
}

void Central::receber(Mensagem* msg, priority_queue< pair<Time,Evento*> >& fila_de_eventos){
    Time tnow = msg->time();
    int percent;
    percent = rand()%100;

    if(percent < percent_for_SUCESSO){
        msg->set_situacao(SUCESSO);
    }
    else{
        percent-= percent_for_SUCESSO;
        if(percent < percent_for_FRACASSO){
            msg->set_situacao(FRACASSO);
        }
        else{
            msg->set_situacao(ADIAMENTO);
        }
    }
    Time tExecucao;
    if(servidores_livre){
        tExecucao.medida = tnow.medida;
        --servidores_livre;
    }
    else{
        if(tnow.medida > tLivre.medida){
            tExecucao.medida = tnow.medida;
        }
        else{
            tExecucao.medida = tLivre.medida;
        }
    }
    tExecucao.medida+= Distribuicao::unif(_inf[msg->destinatario() == REMOTO], _sup[msg->destinatario() == REMOTO]);
    tExecucao.medida+= Distribuicao::exec(msg->remetente(), msg->destinatario());
    if(tLivre.medida < tExecucao.medida)
        tLivre = tExecucao;
    msg->stamp(tExecucao);
    fila_de_eventos.push(make_pair(tExecucao, new Release_Central(*this, msg)));
}

void Central::processar(Mensagem* msg, priority_queue< pair<Time,Evento*> >& fila_de_eventos){
    Time tnow = msg->time();

    if(msg->situacao() == ADIAMENTO){
        this->receber(msg, fila_de_eventos);
    }

}

void Central::set_percent_for_inf(double local, double remoto){_inf[0] = local; _inf[1] = remoto;}
void Central::set_percent_for_sup(double local, double remoto){_sup[0] = local; _sup[1] = remoto;}
void Central::set_percent_for_SUCESSO(int p){percent_for_SUCESSO = p;}
void Central::set_percent_for_FRACASSO(int p){percent_for_FRACASSO = p;}
void Central::set_percent_for_ADIAMENTO(int p){percent_for_ADIAMENTO = p;}
