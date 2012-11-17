#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

class Estatisticas
{
private:
    Time horaAtualizada;
    int msgsSistema;
    int msgsCentralLocal;
    int msgsCentralRemota;
    int msgsLL;
    int msgsLR;
    int msgsRL;
    int msgsRR;

public:
    Estatisticas();

    static void atualizaTempoAtual(Time atual);
    static void inserirMensagemSistema(Time atual);
    static void retirarMensagemSistema(Time atual);
    static void inserirMensagemCentralLocal(Time atual);
    static void retirarMensagemCentralLocal(Time atual);
    static void inserirMensagemCentralRemota(Time atual);
    static void retirarMensagemCentralRemota(Time atual);
    static double minMsgsSistema();
    static double maxMsgsSistema();
    static double mediaMsgsSistema();
    static double minMsgsCLocal();
    static double maxMsgsCLocal();
    static double mediaMsgsCLocal();
    static double minMsgsCRemota();
    static double maxMsgsCRemota();
    static double mediaMsgsCRemota();
    static double inserirMensagem();
    static string toString();
};

#endif // ESTATISTICAS_H
