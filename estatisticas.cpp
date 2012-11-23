#include "estatisticas.h"
#include "iostream"

Time Estatisticas::horaAtualizada;
Time Estatisticas::horaAtualizadaSistema;
Time Estatisticas::horaAtualizadaLocal;
Time Estatisticas::horaAtualizadaRemota;
int Estatisticas::msgsSistema;
int Estatisticas::msgsSistemaMax;
double Estatisticas::msgsSistemaPonderada;
int Estatisticas::msgsCentralLocal;
int Estatisticas::msgsCentralLocalMax;
double Estatisticas::msgsCentralLocalPonderada;
int Estatisticas::msgsCentralRemota;
int Estatisticas::msgsCentralRemotaMax;
double Estatisticas::msgsCentralRemotaPonderada;
int Estatisticas::msgsLL;
int Estatisticas::msgsLR;
int Estatisticas::msgsRL;
int Estatisticas::msgsRR;
int Estatisticas::msgsTotais;
double Estatisticas::tempoMinimoNoSistema;
double Estatisticas::tempoMaximoNoSistema;
double Estatisticas::somatorioTempoNoSistema;
double Estatisticas::tempoLivreSistema;
double Estatisticas::tempoLivreLocal;
double Estatisticas::tempoLivreRemoto;

Estatisticas::Estatisticas()
{
}

void Estatisticas::limpar()
{
    horaAtualizada.medida = 0;
    horaAtualizadaSistema.medida = 0;
    horaAtualizadaLocal.medida = 0;
    horaAtualizadaRemota.medida = 0;
    msgsSistema = 0;
    msgsSistemaMax = 0;
    msgsSistemaPonderada = 0;
    msgsCentralLocal = 0;
    msgsCentralLocalMax = 0;
    msgsCentralLocalPonderada = 0;
    msgsCentralRemota = 0;
    msgsCentralRemotaMax = 0;
    msgsCentralRemotaPonderada = 0;
    msgsLL = 0;
    msgsLR = 0;
    msgsRL = 0;
    msgsRR = 0;
    msgsTotais = 0;
    tempoMinimoNoSistema = 9999999;
    tempoMaximoNoSistema = 0;
    somatorioTempoNoSistema = 0;
    tempoLivreSistema = 0;
    tempoLivreLocal = 0;
    tempoLivreRemoto = 0;
}

void Estatisticas::inserirMensagemSistema(Time atual)
{
    if(!msgsSistema)
        tempoLivreSistema += (atual.medida - horaAtualizadaSistema.medida);
    cout << "Tempo que ficou no estado" << msgsSistema << " : " << (atual.medida - horaAtualizadaSistema.medida) << endl;
    msgsSistemaPonderada += msgsSistema * (atual.medida - horaAtualizadaSistema.medida);
    msgsSistema++;
    if(msgsSistema > msgsSistemaMax)
        msgsSistemaMax = msgsSistema;
    horaAtualizadaSistema = atual;
    cout << "Somatorio de Msgs ponderadas no sistema : " << msgsSistemaPonderada << endl;
}

void Estatisticas::retirarMensagemSistema(Time atual)
{
    if(!msgsSistema)
        tempoLivreSistema += (atual.medida - horaAtualizadaSistema.medida);
    cout << "Tempo que ficou no estado" << msgsSistema << " : " << (atual.medida - horaAtualizadaSistema.medida) << endl;
    msgsSistemaPonderada += msgsSistema * (atual.medida - horaAtualizadaSistema.medida);
    msgsSistema--;
    horaAtualizadaSistema = atual;
    cout << "Somatorio de Msgs ponderadas no sistema : " << msgsSistemaPonderada << endl;
}

void Estatisticas::inserirMensagemCentralLocal(Time atual)
{
    if(!msgsCentralLocal)
        tempoLivreLocal += (atual.medida - horaAtualizadaLocal.medida);
    msgsCentralLocalPonderada += msgsCentralLocal * (atual.medida - horaAtualizadaLocal.medida);
    msgsCentralLocal++;
    if(msgsCentralLocal > msgsCentralLocalMax)
        msgsCentralLocalMax = msgsCentralLocal;
    horaAtualizadaLocal = atual;
}

void Estatisticas::retirarMensagemCentralLocal(Time atual)
{
    if(!msgsCentralLocal)
        tempoLivreLocal += (atual.medida - horaAtualizadaLocal.medida);
    msgsCentralLocalPonderada += msgsCentralLocal * (atual.medida - horaAtualizadaLocal.medida);
    msgsCentralLocal--;
    horaAtualizadaLocal = atual;
}

void Estatisticas::inserirMensagemCentralRemota(Time atual)
{
    if(!msgsCentralRemota)
        tempoLivreRemoto += (atual.medida - horaAtualizadaRemota.medida);
    cout << "Entrada: mensagem ponderada remota esta em " << msgsCentralRemotaPonderada << endl;
    msgsCentralRemotaPonderada += msgsCentralRemota * (atual.medida - horaAtualizadaRemota.medida);
    msgsCentralRemota++;
    if(msgsCentralRemota > msgsCentralRemotaMax)
        msgsCentralRemotaMax = msgsCentralRemota;
    horaAtualizadaRemota = atual;
}

void Estatisticas::retirarMensagemCentralRemota(Time atual)
{
    if(!msgsCentralRemota)
        tempoLivreRemoto += (atual.medida - horaAtualizadaRemota.medida);
    cout << "Saida: mensagem ponderada remota esta em " << msgsCentralRemotaPonderada << endl;
    msgsCentralRemotaPonderada += msgsCentralRemota * (atual.medida - horaAtualizadaRemota.medida);
    msgsCentralRemota--;
    horaAtualizadaRemota = atual;
}

int Estatisticas::minMsgsSistema()
{
    return 0;
}

int Estatisticas::maxMsgsSistema()
{
    return msgsSistemaMax;
}

double Estatisticas::mediaMsgsSistema()
{
    if(horaAtualizadaSistema.medida == 0) return 0;
    return (double)msgsSistemaPonderada/horaAtualizadaSistema.medida;
}

int Estatisticas::minMsgsCLocal()
{
    return 0;
}

int Estatisticas::maxMsgsCLocal()
{
    return msgsCentralLocalMax;
}

double Estatisticas::mediaMsgsCLocal()
{
    if(horaAtualizadaLocal.medida == 0) return 0;
    return (double)msgsCentralLocalPonderada/horaAtualizadaLocal.medida;
}

int Estatisticas::minMsgsCRemota()
{
    return 0;
}

int Estatisticas::maxMsgsCRemota()
{
    return msgsCentralRemotaMax;
}

double Estatisticas::mediaMsgsCRemota()
{
    if(horaAtualizadaRemota.medida == 0) return 0;
    return (double)msgsCentralRemotaPonderada/horaAtualizadaRemota.medida;
}

int Estatisticas::msgsTotaisSistema()
{
    return msgsTotais;
}

int Estatisticas::msgsTotaisLL()
{
    return msgsLL;
}

int Estatisticas::msgsTotaisLR()
{
    return msgsLR;
}

int Estatisticas::msgsTotaisRL()
{
    return msgsRL;
}

int Estatisticas::msgsTotaisRR()
{
    return msgsRR;
}

void Estatisticas::inserirMensagem(Mensagem msg)
{
    if(msg.remetente() == LOCAL){
        if(msg.destinatario() == LOCAL){
            msgsLL++;
        } else {
            msgsLR++;
        }
    } else {
        if(msg.destinatario() == LOCAL){
            msgsRL++;
        } else {
            msgsRR++;
        }
    }
    msgsTotais++;
    double tempoNoSistema = msg.time().medida - msg.begin_time().medida;
    if(tempoNoSistema < tempoMinimoNoSistema)
        tempoMinimoNoSistema = tempoNoSistema;
    if(tempoNoSistema > tempoMaximoNoSistema)
        tempoMaximoNoSistema = tempoNoSistema;
    somatorioTempoNoSistema += tempoNoSistema;
}

string Estatisticas::toString()
{
    stringstream ss;
    ss << "Mensagens Totais : \t" << msgsTotais << "\n";
    ss << "------------------------------------------------------------------\n";
    ss << "Mensagens LL : \t" << msgsLL << "\n";
    ss << "Mensagens LR : \t" << msgsLR << "\n";
    ss << "Mensagens RL : \t" << msgsRL << "\n";
    ss << "Mensagens RR : \t" << msgsRR << "\n\n\n";

    ss << "Informacoes de quantidade de mensagens no SISTEMA durante a execucao\n";
    ss << "------------------------------------------------------------------\n";
    ss << "Nr minimo de mensagens no sistema : \t" << minMsgsSistema() << "\n";
    ss << "Nr maximo de mensagens no sistema : \t" << maxMsgsSistema() << "\n";
    ss << "Media de mensagens no sistema : \t\t" << mediaMsgsSistema() << "\n";
    ss << "Taxa de ocupacao do sistema : \t\t" << 1-(tempoLivreSistema/horaAtualizadaSistema.medida) << "\n\n";


    ss << "Informacoes de quantidade de mensagens na CENTRAL LOCAL durante a execucao\n";
    ss << "------------------------------------------------------------------\n";
    ss << "Nr minimo de mensagens na central : \t" << minMsgsCLocal() << "\n";
    ss << "Nr maximo de mensagens na central : \t" << maxMsgsCLocal() << "\n";
    ss << "Media de mensagens na central : \t\t" << mediaMsgsCLocal() << "\n";
    ss << "Taxa de ocupacao da central : \t\t" << 1-(tempoLivreLocal/horaAtualizadaLocal.medida) << "\n\n";

    ss << "Informacoes de quantidade de mensagens na CENTRAL REMOTA durante a execucao\n";
    ss << "------------------------------------------------------------------\n";
    ss << "Nr minimo de mensagens na central : \t" << minMsgsCRemota() << "\n";
    ss << "Nr maximo de mensagens na central : \t" << maxMsgsCRemota() << "\n";
    ss << "Media de mensagens na central : \t\t" << mediaMsgsCRemota() << "\n";
    ss << "Taxa de ocupacao da central : \t\t" << 1-(tempoLivreRemoto/horaAtualizadaRemota.medida) << "\n\n";

    ss << "Informacoes temporal das mensagens\n";
    ss << "------------------------------------------------------------------\n";
    ss << "Tempo minimo de uma mensagem no sistema : \t" << tempoMinimoNoSistema << "\n";
    ss << "Tempo maximo de uma mensagem no sistema : \t" << tempoMaximoNoSistema << "\n";
    ss << "Media de tempo das mensagens no sistema : \t" << ((double)somatorioTempoNoSistema)/msgsTotais<< "\n\n";

    return ss.str();
}
