#ifndef CENTRAL_H
#define CENTRAL_H
#include "tempo.h"
#include "mensagem.h"
#include "queue"
#include "evento.h"

class Central
{
private:
    int total_servidores;
    int servidores_livre;
    Time tLivre;
    static double _inf[2];
    static double _sup[2];
    static int percent_for_SUCESSO;
    static int percent_for_FRACASSO;
    static int percent_for_ADIAMENTO;
public:
    Central();
    Central(int);
    void receber  (Mensagem* msg, priority_queue< pair<Time,Evento*> >& fila_de_eventos);
    void processar(Mensagem* msg, priority_queue< pair<Time,Evento*> >& fila_de_eventos);

    static void set_percent_for_inf(double local, double remoto);
    static void set_percent_for_sup(double local, double remoto);
    static void set_percent_for_SUCESSO(int p);
    static void set_percent_for_FRACASSO(int p);
    static void set_percent_for_ADIAMENTO(int p);
};

#endif // CENTRAL_H
