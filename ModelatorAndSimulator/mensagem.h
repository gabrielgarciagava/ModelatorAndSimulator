#ifndef MENSAGEM_H
#define MENSAGEM_H
#define LOCAL      0
#define REMOTO     1
#define SUCESSO    2
#define FRACASSO   3
#define ADIAMENTO  4
#define INDEFINIDO 5

#include "tempo.h"

class Mensagem
{
private:
    int _remetente;
    int _destinatario;
    int _situacao;
    Time _stamp;

public:
    Mensagem(int, int, Time);
    int  remetente();
    int  destinatario();
    int  situacao();
    void set_situacao(int);
    Time time();
    void stamp(Time& tnow);
};

#endif // MENSAGEM_H
