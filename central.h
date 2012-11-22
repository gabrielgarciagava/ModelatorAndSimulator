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
    double _inf[2];
    double _sup[2];
    int percent_for_SUCESSO;
    int percent_for_FRACASSO;
public:
    Central();
    Central(int parami[3], double paramd[4]);
    void receber  (Mensagem* msg, priority_queue< pair<Time,Evento*> >& fila_de_eventos);
    void processar(Mensagem* msg, priority_queue< pair<Time,Evento*> >& fila_de_eventos);
};

#endif // CENTRAL_H
