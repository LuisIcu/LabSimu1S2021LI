/*
Autor:  root
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc primos1603.c -o primos1603
Fecha: Sun Mar 21 04:56:47 UTC 2021
Librerías: 
Resumen: 
Se ingresa un número y verifica si el número es primo o no.
*/
 
//Librerías
#include <stdio.h>

int main(){

//Iniciamos variables globales
    int N=0, i=2, primo=1;

    printf("Ingresar un número para verificar si es primo.\n");
    scanf("%d",&N);

//la variable "primo" funciona como un indicador de si avanza o no
//Va buscando uno a uno los divisores del número desde el dos
//En cuanto encuentre un número que deje residuo cero, lo marca como "no primo"
    while(i<N-1 && primo==1){
        //Aquí busca el residuo      
        if(N%i==0){
            primo=0; //indicador para salir de while
        }
        i++;
    }

    if(primo==0){
        printf("No es primo.\n");
    }else{
        printf("Es primo.\n");       
    }
    
    
return 0;
}