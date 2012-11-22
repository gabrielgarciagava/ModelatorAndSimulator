#ifndef DISTRIBUICAO_H
#define DISTRIBUICAO_H
#define ERROR 0.0001

class Distribuicao
{
    static bool flag;
    static double r1;
    static double r2;
public:
    Distribuicao();
    static void init();
    static double expo  (double l);
    static double unif  (double inf, double sup);
    static double normal(double media, double desvio);
    static double triang(double a, double b, double c);
    static double exec(int remetente, int destinatario);
};

#endif // DISTRIBUICAO_H
