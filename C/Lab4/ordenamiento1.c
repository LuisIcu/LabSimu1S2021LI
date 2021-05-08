/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc ordenamiento1.c -lm 
Fecha: Fri May  7 00:53:16 CST 2021
Librerías: stdio.h, math.h
Resumen: Se ingresan 10 datos pares entre 2 y 20. El usuario decide verlos en forma ascendente o descendente
Entrada: 10 valores enteros entre 2 y 20
Salida: La visualización ordenada de los valores.
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

int lista[10];//Donde se guardan los valores
char ind;//Indicador si va a ser ascendente o descendente
int n=0, aux, k=0; //variables auxiliares

void main(){
    //Ingresar los datos
    printf("--Ingresar números pares del 2 al 20--\n");
    while (n<10){
        scanf("%d",&lista[n]);
        if (lista[n]%2==0 && lista[n]<=20 && lista[n]>0){
            n++;
        } else if (lista[n]<=0){
            printf("Debe ser mayor que 0\n");
        } else if (lista[n]>20){
            printf("Debe ser menor que 20\n");
        } else{
            printf("No es par\n");
        }
    }

    //Ordenamos ascendentemente con el método "Selección"
    for (int i=0;i<=8;i++){
        for (int j=i+1;j<=9;j++){
            if(lista[i]>lista[j]){
                //Hacemos el cambio de lugar si se cumple
                //Esto se repite con todos los j, así nos aseguramos de tener al menor
                aux = lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }

    printf("¿Ver ascendente (a) o descendente (d)?\n");
    while (k==0){//Aquí sigue hasta ingresar un valor válido
        scanf("%c",&ind);
        if(ind == 'a'){ //Si es a los muestra en orden ascendente
            for (int i = 0; i < 10; i++){
                printf("%d\n",lista[i]);
                k=1;
            }
        } else if(ind == 'd'){//Si es d los muestra en orden descendente
            for (int i = 9; i >= 0; i--){
                printf("%d\n",lista[i]);
                k=1;
            }
        }
    
}
