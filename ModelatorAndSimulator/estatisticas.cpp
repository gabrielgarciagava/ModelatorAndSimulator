#include "estatisticas.h"

Time Estatisticas::horaAtualizada;
Time Estatisticas::horaAtualizadaSistema;
Time Estatisticas::horaAtualizadaLocal;
Time Estatisticas::horaAtualizadaRemota;
int Estatisticas::msgsSistema;
int Estatisticas::msgsSistemaMax;
int Estatisticas::msgsSistemaPonderada;
int Estatisticas::msgsCentralLocal;
int Estatisticas::msgsCentralLocalMax;
int Estatisticas::msgsCentralLocalPonderada;
int Estatisticas::msgsCentralRemota;
int Estatisticas::msgsCentralRemotaMax;
int Estatisticas::msgsCentralRemotaPonderada;
int Estatisticas::msgsLL;
int Estatisticas::msgsLR;
int Estatisticas::msgsRL;
int Estatisticas::msgsRR;
int Estatisticas::msgsTotais;

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
}

void Estatisticas::inserirMensagemSistema(Time atual)
{
    msgsSistemaPonderada += msgsSistema * (atual.medida - horaAtualizadaSistema.medida);
    msgsSistema++;
    if(msgsSistema > msgsSistemaMax)
        msgsSistemaMax = msgsSistema;
    horaAtualizadaSistema = atual;
}

void Estatisticas::retirarMensagemSistema(Time atual)
{
    msgsSistemaPonderada += msgsSistema * (atual.medida - horaAtualizadaSistema.medida);
    msgsSistema--;
    horaAtualizadaSistema = atual;
}

void Estatisticas::inserirMensagemCentralLocal(Time atual)
{
    msgsCentralLocalPonderada += msgsCentralLocal * (atual.medida - horaAtualizadaLocal.medida);
    msgsCentralLocal++;
    if(msgsCentralLocal > msgsCentralLocalMax)
        msgsCentralLocalMax = msgsCentralLocal;
    horaAtualizadaLocal = atual;
}

void Estatisticas::retirarMensagemCentralLocal(Time atual)
{
    msgsCentralLocalPonderada += msgsCentralLocal * (atual.medida - horaAtualizadaLocal.medida);
    msgsCentralLocal--;
    horaAtualizadaLocal = atual;
}

void Estatisticas::inserirMensagemCentralRemota(Time atual)
{
    msgsCentralRemotaPonderada += msgsCentralRemota * (atual.medida - horaAtualizadaRemota.medida);
    msgsCentralRemota++;
    if(msgsCentralRemota > msgsCentralRemotaMax)
        msgsCentralRemotaMax = msgsCentralRemota;
    horaAtualizadaRemota = atual;
}

void Estatisticas::retirarMensagemCentralRemota(Time atual)
{
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
    if(msg.destinatario() == LOCAL){
        if(msg.remetente() == LOCAL){
            msgsLL++;
        } else {
            msgsLR++;
        }
    } else {
        if(msg.remetente() == LOCAL){
            msgsRL++;
        } else {
            msgsRR++;
        }
    }
    msgsTotais++;
}

string Estatisticas::toString()
{
    stringstream ss;
    ss << "Mensagens Totais : \t" << msgsTotais << "\n";
    ss << "---------------------------------\n";
    ss << "Mensagens LL : \t" << msgsLL << "\n";
    ss << "Mensagens LR : \t" << msgsLR << "\n";
    ss << "Mensagens RL : \t" << msgsRL << "\n";
    ss << "Mensagens RR : \t" << msgsRR << "\n\n\n";

    ss << "Informacõess de quantidade de mensagens no sistema durante a execução\n";
    ss << "---------------------------------\n";
    ss << "Nr mínimo de mensagens no sistema : \t" << minMsgsSistema() << "\n";
    ss << "Nr máximo de mensagens no sistema : \t" << msgsSistemaMax << "\n";
    ss << "Média de mensagens no sistema : \t" << msgsSistemaPonderada << "\n\n";

    ss << "Informacõess de quantidade de mensagens na central local durante a execução\n";
    ss << "---------------------------------\n";
    ss << "Nr mínimo de mensagens na central: \t" << minMsgsCLocal() << "\n";
    ss << "Nr máximo de mensagens na central : \t" << msgsCentralLocalMax << "\n";
    ss << "Média de mensagens na central : \t" << msgsCentralLocalPonderada << "\n\n";

    ss << "Informacõess de quantidade de mensagens na central remota durante a execução\n";
    ss << "---------------------------------\n";
    ss << "Nr mínimo de mensagens na central: \t" << minMsgsCRemota() << "\n";
    ss << "Nr máximo de mensagens na central : \t" << msgsCentralRemotaMax << "\n";
    ss << "Média de mensagens na central : \t" << msgsCentralRemotaPonderada << "\n\n";

    return ss.str();
}
