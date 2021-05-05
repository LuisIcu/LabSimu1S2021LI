/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc vectores3x3.c -lm -o vectores3x3
Fecha: Wed May  5 15:37:23 CST 2021
Librerías: 
Resumen: 
Entrada: 
Salida: 
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

void imprimir(float vector[]); //Imprime un vector
void ingvector(float vector[]); //Ingresa los datos de un vector 3x3
float magnitud(float vector[]); //Da la magnitud del vector
void suma(float vector1[], float vector2[], float vectorsuma[]); //Suma los vectores
float escalar(float vector1[], float vector2[]); //Da el producto escalar de dos vectores
void vectorial(float vector1[], float vector2[]); //Da el producto vectorial de dos vectores



void imprimir(float vector[]){ //Imprime un vector
    printf("[");
    for (int i=0; i<3; i++){
        printf("%f, ",vector[i]);
    }
    printf("]");
} 

void ingvector(float vector[]){ //Ingresa los datos de un vector 3x3
    for (int i=0; i<3; i++){
        printf("Ingresar el dato %d:", i+1);
        scanf("%f\n",&vector[i]);
    }
}

float magnitud(float vector[]){ //Da la magnitud del vector
    float magnus=0;
    float sqrtmagnus=0;
    for (int i = 0; i < 3; i++)
    {
        magnus += pow(vector[i],2);
    }
    sqrtmagnus=sqrt(magnus); 
    return sqrtmagnus;
}

void suma(float vector1[], float vector2[], float vectorsuma[]){ //Suma los vectores
    for (int i = 0; i < 3; i++)
    {
        vectorsuma[i] = vector1[i]+vector2[i];
    } 
}

float escalar(float vector1[], float vector2[]){ //Da el producto escalar de dos vectores
    float scalar=0;
    for (int i = 0; i < 3; i++)
    {
        scalar = vector1[i]*vector2[i];
    }
    return scalar;
}

void vectorial(float vector1[], float vector2[]){ //Da el producto vectorial de dos vectores

}