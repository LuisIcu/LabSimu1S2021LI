/*
Autor:  root
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc rangoprimos1603.c -o rangoprimos1603
Fecha: Sun Mar 21 06:15:15 UTC 2021
Librerías: 
Resumen: 
Se ingresan dos números enteros positivos.
El programa busca todos los números primos entre el rango indicado.
*/
 
//Librerías
#include <stdio.h>

int main(){

//N1 es el límite inferior, N2 el superior
//Las demás variables sirven de indicadores
    int N1=0, N2=0, i=0, j=2, primo=1;

    printf("Ingresar el límite inferior del rango: \n");
    scanf("%d",&N1);
    printf("Ingresar el límite superior del rango: \n");
    scanf("%d",&N2);

    i=N1; 

    //Buscamos si nuestro límite inferior es o no primo.
    while(i<=N2){
        //El procedimiento que sigue es el mismo que el del
        //programa primos1603, así que no se detalla el procedimiento aquí
        while(j<i-1 && primo==1){
            if(i%j==0){
                primo=0;
            }
            j++;
        }
        //Si encuentra que N1 es primo, aquí lo escribe
        if(primo==1){
            printf("Este número es primo: %d\n", i);
        }

        i++; //Aumenta en 1 el valor de i, y así sucesivamente hasta N2
        //Reinicia el valor de nuestros indicadores
        j=2;
        primo=1;
    }

return 0;
}
