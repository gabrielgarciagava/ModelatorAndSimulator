#include "estatisticas.h"

Estatisticas::Estatisticas()
{
}

void Estatisticas::inserirMensagemSistema(Time atual)
{
    msgsSistema++;
}

void Estatisticas::retirarMensagemSistema(Time atual)
{
    msgsSistema--;
}

void Estatisticas::inserirMensagemCentralLocal(Time atual)
{
}

void Estatisticas::retirarMensagemCentralLocal(Time atual)
{
}

void Estatisticas::inserirMensagemCentralRemota(Time atual)
{
}

void Estatisticas::retirarMensagemCentralRemota(Time atual)
{
}

double Estatisticas::minMsgsSistema()
{
}

double Estatisticas::maxMsgsSistema()
{
}

double Estatisticas::mediaMsgsSistema()
{
}

double Estatisticas::minMsgsCLocal()
{
}

double Estatisticas::maxMsgsCLocal()
{
}

double Estatisticas::mediaMsgsCLocal()
{
}

double Estatisticas::minMsgsCRemota()
{
}

double Estatisticas::maxMsgsCRemota()
{
}

double Estatisticas::mediaMsgsCRemota()
{
}

double Estatisticas::inserirMensagem()
{
}

string Estatisticas::toString()
{
}
