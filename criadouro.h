#ifndef CRIADOURO_H
#define CRIADOURO_H
#include "evento.h"
#include "mensagem.h"
#include "tempo.h"
#include "central.h"

class Criadouro : public Evento
{
private:
    Time tnow;
    Central local;
    Central remoto;
    static double media;
    static int percent_for_LL;
    static int percent_for_LR;
    static int percent_for_RL;
    static int percent_for_RR;
public:
    Criadouro(Time tnow, Central& local, Central& remoto);
    bool run(priority_queue< pair<Time,Evento*> >& fila_de_eventos);
    bool operator<(const Evento &aNode) const{ return this == &aNode; }
    static void set_media(double m);
    static void set_percent_for_LL(int p);
    static void set_percent_for_LR(int p);
    static void set_percent_for_RL(int p);
    static void set_percent_for_RR(int p);
};

#endif // CRIADOURO_H
