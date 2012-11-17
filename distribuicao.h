#ifndef DISTRIBUICAO_H
#define DISTRIBUICAO_H

class Distribuicao
{
public:
    Distribuicao();
    static double expo  (double l);
    static double unif  (double inf, double sup);
    static double normal(double media, double desvio);
    static double triang(double a, double b, double c);
    static double exec(int remetente, int destinatario);
};

#endif // DISTRIBUICAO_H
