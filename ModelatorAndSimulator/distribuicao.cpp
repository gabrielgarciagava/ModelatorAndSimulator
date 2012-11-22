#include "distribuicao.h"

Distribuicao::Distribuicao()
{

}

double Distribuicao::expo(double l){
    return l;
}

double Distribuicao::unif(double inf, double sup){
    return (inf+sup)/2;
}

double Distribuicao::normal(double media, double desvio){
    return media;
}

double Distribuicao::triang(double a, double b, double c){
    return a;
}

double Distribuicao::exec(int remetente, int destinatario){
    return 50;
}
