/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc ordenamiento2.c -lm -o ordenamiento2
Fecha: Thu May  6 12:52:19 CST 2021
Librerías: stdio.h, math.h
Resumen: Se ingresan 5 valores enteros. El programa lo muestra ordenado ascendentemente
Entrada: 5 valores enteros
Salida: Visualización ascendente de los valores
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

int lista[5];//Aquí se guardan
int n=0, aux;//Variables auxiliares

void main(){
    //Ingresar los datos
    printf("--Ingresar números enteros--\n");
    while (n<5){
        scanf("%d",&lista[n]);
        n++;
    }

    //Ordenamos ascendentemente con el método "Selección"
    for (int i=0;i<=3;i++){
        for (int j=i+1;j<=4;j++){
            if(lista[i]>lista[j]){
                //Hacemos el cambio de lugar si se cumple
                //Esto se repite con todos los j, así nos aseguramos de tener al menor
                aux = lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }

    printf("Ordenados de forma ascendente:\n");
    for (int i = 0; i < 5; i++){
        printf("%d\n",lista[i]);
    }
    
}



