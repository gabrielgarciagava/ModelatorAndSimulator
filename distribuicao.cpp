#include "distribuicao.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

bool Distribuicao::flag;
double Distribuicao::r1;
double Distribuicao::r2;

Distribuicao::Distribuicao()
{

}
void Distribuicao::init(){
    srand( time(NULL) );
}

double Distribuicao::expo(double l){
    double r;
    while ((r = ((double) rand())/RAND_MAX) == 0);
    return (-l)*log(r);
}

double Distribuicao::unif(double inf, double sup){
    double r = ((double) rand())/RAND_MAX;
    return inf + (sup-inf)*r;
}

double Distribuicao::normal(double media, double desvio){
    double value,z;

    if(flag){
        while((r1 = ((double) rand())/RAND_MAX) == 0);
        r2 = ((double) rand())/RAND_MAX;
        z = sqrt(-2*log(r1))*cos(2*M_PI*r2);
    } else {
        z = sqrt(-2*log(r1))*sin(2*M_PI*r2);
    }

    value = media + desvio*z;
    flag = !flag;
    return value;
}

double Distribuicao::triang(double a, double b, double c){
    double x,r = ((double) rand())/RAND_MAX;

    if(r < (b-a)/(c-a))
        x = a + sqrt(r*(b-a)*(c-a));
    else
        x = c - sqrt((1-r)*(c-b)*(c-a));

    return x;
}

double Distribuicao::exec(int remetente, int destinatario){
    double valor;
    if(remetente == 0){     // LOCAL
        if(destinatario==0){// LOCAL
            valor = normal(0.55, 0.05);
        }
        else{               // REMOTO
            valor = normal(0.65, 0.04);
        }
    }
    else{                   // REMOTO
        if(destinatario==0){// LOCAL
            valor = triang(0.14, 0.25, 0.55);
        }
        else{               // REMOTO
            valor = unif(0.09, 0.18);
        }
    }
    return valor;
}
