#include "central.h"
#include "iostream"
#include <stdlib.h>
#include <time.h>
#include "distribuicao.h"
#include "estatisticas.h"
#include "release_central.h"

Central::Central(){
}
Central::Central(int parami[3], double paramd[4])
{
    int total_servidores;
    double inf_local, inf_remoto, sup_local, sup_remoto;
    int percent_for_SUCESSO_local, percent_for_FRACASSO_local, percent_for_SUCESSO_remoto, percent_for_FRACASSO_remoto;
    total_servidores = parami[0];
    inf_local = paramd[0];
    inf_remoto = paramd[1];
    sup_local = paramd[2];
    sup_remoto = paramd[3];
    percent_for_SUCESSO_local = parami[1];
    percent_for_FRACASSO_local = parami[2];
    percent_for_SUCESSO_remoto = parami[3];
    percent_for_FRACASSO_remoto = parami[4];

    this->total_servidores = total_servidores;
    this->servidores_livre = total_servidores;

    this->_inf[0] = inf_local;
    this->_inf[1] = inf_remoto;
    this->_sup[0] = sup_local;
    this->_sup[1] = sup_remoto;
    this->percent_for_SUCESSO_local = percent_for_SUCESSO_local;
    this->percent_for_FRACASSO_local = percent_for_FRACASSO_local;
    this->percent_for_SUCESSO_remoto = percent_for_SUCESSO_remoto;
    this->percent_for_FRACASSO_remoto = percent_for_FRACASSO_remoto;
    srand( time(NULL) );
}

void Central::receber(Mensagem* msg, priority_queue< pair<Time,Evento*> >& fila_de_eventos){
    Time tnow = msg->time();
    int percent;
    percent = rand()%100;

    if(msg->destinatario() == LOCAL){
        if(percent < percent_for_SUCESSO_local){
            msg->set_situacao(SUCESSO);
        }
        else{
            percent -= percent_for_SUCESSO_local;
            if(percent < percent_for_FRACASSO_local){
                msg->set_situacao(FRACASSO);
            }
            else{
                msg->set_situacao(ADIAMENTO);
            }
        }
    } else {
        if(percent < percent_for_SUCESSO_remoto){
            msg->set_situacao(SUCESSO);
        }
        else{
            percent -= percent_for_SUCESSO_remoto;
            if(percent < percent_for_FRACASSO_remoto){
                msg->set_situacao(FRACASSO);
            }
            else{
                msg->set_situacao(ADIAMENTO);
            }
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
    }else{
        cout << "Release" << endl;
        if(msg->remetente() == LOCAL){
            cout << "Mensagem saindo da Central Local\n";
            Estatisticas::retirarMensagemCentralLocal(tnow);
        }else{
            cout << "Mensagem saindo da Central Remota\n";
            Estatisticas::retirarMensagemCentralRemota(tnow);
        }
        cout << "Retirando msg do sistema" << endl;
        Estatisticas::retirarMensagemSistema(tnow);
        Estatisticas::inserirMensagem(*msg);
        if(servidores_livre < total_servidores)
            servidores_livre++;
        delete msg;
    }

}
