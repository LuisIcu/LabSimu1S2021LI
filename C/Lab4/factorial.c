/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc 5factorial.c -o 5factorial
Fecha: Fri Apr 23 17:14:35 CST 2021
Librerías: 
Resumen: 
Entrada: 
Salida: 
*/
 
//Librerías
#include <stdio.h>

int main(){
    int num = 0;
    int fact = 1;

    printf("---Calculadora de factorial---\n");
    printf("Ingrese el número:\n");
    scanf("%d",&num);

    for(int i = 1; i<=num; i++){
        fact = i*fact;
    }
    printf("%d! = %d \n", num, fact);

    return 0;

}