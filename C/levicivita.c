/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc levicivita.c -lm -o levicivita
Fecha: Wed May  5 16:41:34 CST 2021
Librerías: 
Resumen: 
Entrada: 
Salida: 
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

int permutacion(int val1, int val2, int val3);

int A, B, C, signo;

void main(){
    printf("Introducir A: ");
    scanf("%d",&A);
    printf("Introducir B: ");
    scanf("%d",&B);
    printf("Introducir C: ");
    scanf("%d",&C);
    signo = permutacion(A,B,C);
    printf("El signo de la permutación es: %d\n",signo);
}

int permutacion(int val1, int val2, int val3){
    int signo;
    if (val1 == val2 || val2 == val3 || val3 == val1){
        signo = 0;
    }else if(val1 < val2 && val2 < val3){ //1
        signo = 1;
    }else if(val1 < val2 && val3 < val1){ //2
        signo = 1;
    }else if(val2 < val3 && val3 < val1){ //3
        signo = 1;
    }else if(val2 > val3 && val3 > val1){ //4
        signo = -1;
    }else if(val1 > val2 && val3 > val1){ //5
        signo = -1;
    }else if(val1 > val2 && val2 > val3){ //6
        signo = -1;
    }
    return signo;
}
