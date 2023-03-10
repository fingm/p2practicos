#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 100


/*
Ejercicio 1 Promedio clase

Suponga que a los estudiantes de programación 2 se les dice que su calificación final será el promedio de
las cuatro calificaciones más altas de entre las cinco que hayan obtenido en el curso.

(a) Escribir una función llamada PromClase con cinco parámetros de entrada (las calificaciones obtenidas)
que realice dicho cálculo y lo devuelva.
*/

/*
(b) Escribir un programa principal (main ()) que permita ejecutar la función PromClase. Dicho programa
deberá leer de la entrada estándar (teclado) 5 calificaciones, invocar al procedimiento PromClase con
dichos parámetros, y finalmente mostrar en la salida estándar (pantalla) el resultado.
*/

    float promClase(int a,int b, int c, int d, int e){
        int min = a;
        for (char i=b;i<=e;i++){
            if(i<min){
                min=i;
            }
        }
        return (a+b+c+d+e-min)/4;
    }
/*
Ejercicio 2 Primos

Escriba un procedimiento que calcule e imprima en pantalla todos los números primos entre dos enteros
positivos A y B cualesquiera.
*/
    void primos(int a , int b){
        int i,j;
        if(a>=2){
            if (a==2){
                printf(".2");
            } 
            for (i = a ; i <= b ; i++){
                j = 2;
                while( ((j<sqrt(i))) && (i%j != 0)){
                    j++;
                }
                if(i%j != 0){
                    printf(".%d",i);
                }
            }
        }
    }

/*
Ejercicio 3 Ocurrencias

Se quiere implementar una función que cuente la cantidad de veces que una letra aparece en una frase.
La frase se representa como un arreglo de caracteres, y dado que se conoce que el largo máximo de
una frase es de 100 caracteres, la frase se implementa como char frase[100]. Usando esta representación
escriba una función Ocurrencias que recibe una frase, un natural llamado largo que representa el número
de caracteres en la frase, y el caracter a buscar (almacenado en la variable letra), y devuelve el número de
ocurrencias del carácter letra en el arreglo frase.
*/

    int ocurrencias(char frase[],int tope , char letra){
        int res = 0;
        if(tope>0){
            for (int i=0; i<=tope; i++){
                if(frase[i] == letra){
                    res++;
                }
            }
        }
        return res;
    }

    void cargararreglo(char frase[],int &cont){
        char caract = ' ';
        while(cont<100  && caract != '$'){
            if (caract != '$'){
                scanf("%c",&caract);
                frase[cont] = caract;
                cont++;  
            }
            
        }
    }

    void mostrararreglo(char frase[], int tope){
        for(int i = 0; i<tope; i++){
            printf("%c",frase[i]);
        }
    }

/*
Ejercicio 4 Es Palíndrome

Considere ahora que la frase se representa como un arreglo de caracteres implementado como char
*frase.

(a) ¿Qué diferencias hay entre esta representación y la que utilizó en el Ejercicio 3?

(b) Escriba una función EsPalindrome que recibe una frase representada como un puntero a char y de-
vuelve TRUE si la misma es un palíndrome, FALSE en otro caso.
*/

    bool espalindrome(char * frase){
        int largo = strlen(frase)-1;
        if (largo == 1){
            return true;
        }else{
            int cont = 0;
            while(cont<(largo/2) && (frase[cont] == frase[largo-cont])){
                cont++;
            }
            return frase[cont] == frase[largo-cont];
        }
    }

/*
Ejercicio 5 Insertar Punto

Los siguientes tipos definen los conceptos punto y colección de puntos. La colección se representa con un
arreglo con tope.*/

typedef struct rep_punto {
int coordX , coordY ;
} Punto ;

typedef struct rep_colPuntos {
int capacidad ;
int cantidad ;
Punto * arregloPuntos ;
} ColPuntos ;

/*

Implemente una función que inserte un punto en una colección de puntos:
*/
bool esmenor(Punto p1 , Punto p2){
    return (p1.coordX < p2.coordY) || ((p1.coordX < p2.coordX) && (p1.coordY < p2.coordY));
}

void insertarPunto ( ColPuntos & colPtos , Punto pto ){
    if(colPtos.capacidad > colPtos.cantidad){
        colPtos.cantidad++;
        int i = colPtos.cantidad;
        while((i>0) && esmenor(pto,colPtos.arregloPuntos[i-1])){
            colPtos.arregloPuntos[i] = colPtos.arregloPuntos[i-1];
            i--;
        }
        colPtos.arregloPuntos[i] = pto;
    }

}
/*
La colección está ordenada y debe quedar así después de la inserción. El orden es tal que para cada par de
puntos el que tenga menor coordenada X precede al otro, y si esas coordenadas son iguales el que tenga
menor coordenada Y precede al otro (orden lexicográfico).
Si la cantidad de puntos es igual a la capacidad del arreglo la operación no tiene efecto.

Ejercicio 6 Ordenar arreglo

Escriba una función que recibe un arreglo de enteros y devuelve un nuevo arreglo que contiene a los ele-
mentos del primero en orden ascendente. Indique qué algoritmos de ordenación utiliza.*/

int *ordenar(int *A , int n){
    int *B = new int[n];
    for(int i =0; i<n ; i++){
        B[i] = A[i];
    }

    for (int i = 1 ; i < n ; i++){
        int pos = i-1;
        int insertando = B[i];
        while((pos>0) && B[pos] >insertando){
            B[pos+1] = B[pos];
            pos--;
        }
        B[pos+1] = insertando;
    }
    return B;
}

int main(){

    printf("\n1).Ejercicio 1 : Promedio clase\n");
    printf("\n2).Ejercicio 2 : Primos\n");
    printf("\n3).Ejercicio 3 : Ocurrencias\n");
    printf("\n4).Ejercicio 4 : Es palindrome\n");

    int ej;
    printf("\ningrese el numero de ejercicio: ");
    scanf("%d",&ej);
    printf("Probaremos el ejercicio: %d\n", ej);

    if(ej == 1){
        int a,b,c,d,e;
        printf("\nIngrese 5 valores\n");
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        printf("El promedio es : %f",promClase(a,b,c,d,e));

    }else if(ej == 2){
        int a,b;
        printf("\nIngrese 2 valores\n");
        scanf("%d %d",&a,&b);
        primos(a,b);
    }else if (ej == 3){
        printf("\n Ingrese el texto: ");
        char frase[MAX];
        int tope =0;
        cargararreglo(frase,tope);
        printf("\nEl texto Ingresado es el siguiente : ");
        mostrararreglo(frase , tope);
        char letra = 's';
        printf("\n Ingrese la letra que desea contar ocurrencias:");
        scanf("\n %c",&letra);
        printf("\nLa letra %c aparece %d veces",letra,ocurrencias(frase,tope,letra));
    }else if (ej == 4){
        char *arreglo = new char[5];
        arreglo[0]='e';
        arreglo[1]='f';
        arreglo[2]='h';
        arreglo[3]='s';
        arreglo[4]='e';
        if (espalindrome(arreglo)){
            printf("Es aplindrome");
        }else{
            printf("no es palindrome");
        }
    }
    


}
