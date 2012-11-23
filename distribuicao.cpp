#include "distribuicao.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
bool Distribuicao::flag;
double Distribuicao::r1;
double Distribuicao::r2;

Distribuicao::Distribuicao()
{

}
void Distribuicao::init(){
    flag = 1;
    srand( time(NULL) );
}

double Distribuicao::expo(double l){
    double r,v;
    do {
        while ((r = (double)(rand()%10000)/10000) == 0);
        v = (-l)*log(r);
    } while(v < 0);
    return v;
}

double Distribuicao::unif(double inf, double sup){
    double r = ((double) rand())/RAND_MAX;
    return inf + (sup-inf)*r;
}

double Distribuicao::normal(double media, double desvio){
    double value,z;

    do{
        if(flag){
            while((r1 = (double)(rand()%10000)/10000) == 0);
            r2 = ((double) rand())/RAND_MAX;
            z = sqrt(-2*log(r1))*cos(2*M_PI*r2);
        } else {
            z = sqrt(-2*log(r1))*sin(2*M_PI*r2);
        }
        value = media + desvio*z;
        flag = !flag;
    } while(value < 0);

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
        if(destinatario == 0){// LOCAL
            valor = normal(0.55, 0.05);
        }
        else{               // REMOTO
            valor = normal(0.65, 0.04);
        }
    }
    else{                   // REMOTO
        if(destinatario == 0){// LOCAL
            valor = triang(0.14, 0.25, 0.55);
        }
        else{               // REMOTO
            valor = unif(0.09, 0.18);
        }
    }
    return valor;
}
