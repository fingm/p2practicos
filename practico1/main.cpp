#include "punto.h"
#include <math.h>

double distancia(punto a, punto b){
    return (sqrt(pow(coordX(a)-coordX(b),2) + pow(coordY(a)-coordY(b),2)));
}


int main(){

//inicializo 3 puntos
punto a = crearpunto(3.0,5.5);
punto b = crearpunto(0,5.5);
punto c = crearpunto(-2.0,17.5);

double dist = distancia(a,b);

//calcular las 3 diastancias e imprimir

}