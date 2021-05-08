/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc 5factorial.c -o
Fecha: Fri Apr 23 17:14:35 CST 2021
Librerías: stdio.h
Resumen: Calculadora del factorial de un número
Entrada: Un número entero positivo n
Salida: El factorial de n: 1*2*...*n=n!
*/
 
//Librerías
#include <stdio.h>

void main(){
    int num = 0;
    int fact = 1;

    printf("---Calculadora de factorial---\n");
    printf("Ingrese el número:\n");
    scanf("%d",&num);

    for(int i = 1; i<=num; i++){
        fact = i*fact;//función recursiva que multiplica desde 1 hasta n
    }
    printf("%d! = %d \n", num, fact);
}