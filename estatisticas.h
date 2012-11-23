#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "tempo.h"
#include "mensagem.h"
#include <string>
#include <sstream>

using namespace std;

class Estatisticas
{
private:
    static Time horaAtualizada;
    static Time horaAtualizadaSistema;
    static Time horaAtualizadaLocal;
    static Time horaAtualizadaRemota;
    static int msgsSistema;
    static int msgsSistemaMax;
    static double msgsSistemaPonderada;
    static int msgsCentralLocal;
    static int msgsCentralLocalMax;
    static double msgsCentralLocalPonderada;
    static int msgsCentralRemota;
    static int msgsCentralRemotaMax;
    static double msgsCentralRemotaPonderada;
    static int msgsLL;
    static int msgsLR;
    static int msgsRL;
    static int msgsRR;
    static int msgsTotais;
    static double tempoMinimoNoSistema;
    static double tempoMaximoNoSistema;
    static double somatorioTempoNoSistema;
    static double tempoLivreSistema;
    static double tempoLivreLocal;
    static double tempoLivreRemoto;

public:
    Estatisticas();

    static void limpar();
    static void atualizaTempoAtual(Time atual);
    static void inserirMensagemSistema(Time atual);
    static void retirarMensagemSistema(Time atual);
    static void inserirMensagemCentralLocal(Time atual);
    static void retirarMensagemCentralLocal(Time atual);
    static void inserirMensagemCentralRemota(Time atual);
    static void retirarMensagemCentralRemota(Time atual);
    static int minMsgsSistema();
    static int maxMsgsSistema();
    static double mediaMsgsSistema();
    static int minMsgsCLocal();
    static int maxMsgsCLocal();
    static double mediaMsgsCLocal();
    static int minMsgsCRemota();
    static int maxMsgsCRemota();
    static double mediaMsgsCRemota();
    static int msgsTotaisSistema();
    static int msgsTotaisLL();
    static int msgsTotaisLR();
    static int msgsTotaisRL();
    static int msgsTotaisRR();
    static void inserirMensagem(Mensagem msg);
    static string toString();
};

#endif // ESTATISTICAS_H
