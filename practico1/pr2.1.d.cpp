#include <stdio.h>

struct rep_fecha{
    unsigned int f;  
};

typedef struct rep_fecha *Tfecha;

Tfecha crearfecha(unsigned int d, unsigned int m,unsigned int y){
    Tfecha nueva = new rep_fecha;
    nueva->f = d+m*100 +y+10000;
    return nueva;
}

bool compararfechas(Tfecha f1, Tfecha f2){
    return f1<f2;
}

unsigned int dia(Tfecha f){
   return  f->f%100;
}

unsigned int mes(Tfecha f){
   return (f->f%10000)/100;
}

unsigned int año(Tfecha f){
   return f->f/10000;
}

int main(){

    const int largo = 3;    
    Tfecha fechas[largo];
    fechas[0] = crearfecha(19,4,2010);
    fechas[1] = crearfecha(22,3,2015);
    fechas[2] = crearfecha(9,12,2021);

    for (int i = 0 ; i<largo-1; i++){
        int min = 1;
        for (int j = i+1 ; j<largo;j++){
            if(compararfechas(fechas[i],fechas[min])){
                min = i;
            }
            Tfecha aux = fechas[i];
            fechas[i] = fechas[min];
            fechas[min] = aux;
        }
    }
    printf("%u/%u/%u",fechas[0],fechas[1],fechas[2]);

}