//Punto.h

#ifndef _PUNTO_H
#define _PUNTO_H

/*representacion de Punto*/
typedef struct rep_punto *punto;

/*Operaciones de punto*/

/*Devuelve un 'punto' de coordenadas 'x' e 'y'.*/
punto crearpunto(double x, double y);

/*Devuelve la coordenada 'x' de 'punto'*/
double coordX(punto p);

/*Devuelve la coordenada 'y' de 'punto'*/
double coordY(punto p);

#endif
