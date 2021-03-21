/*
Autor:  root
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc alturas1603.c -o alturas1603
Fecha: Sun Mar 21 03:53:53 UTC 2021
Librerías: 
Resumen: 
Se ingresan varias alturas. Al momento de ingresar una altura
negativa, se obtiene el promedio de las alturas previas, 
la altura máxima y la altura mínima.
*/
 
//Librerías
#include <stdio.h>


int main(){
//Declaramos variables globales

    float x=0, media=0, min=0, max=0;
    int n=0;

    printf("Ingresar alturas positivas\n");

//Ingresamos la primera altura
    printf("Ingrese una altura: ");
    scanf("%f",&x);
    min=x;
    max=x;

//El proceso se va a repetir meintras se cumpla que sea positivo
    while(x>=0){
        n++;//Aumentamos la cantidad de valores
        media+=x;
        //Si es la altura máxima, aquí se guarda
        if(x>max){
            max=x;
        }
        //Si es la altura mínima, aquí se guarda
        if(x<min){
            min=x;
        }
        //Repetimos el proceso
        printf("Ingrese una altura: ");
        scanf("%f",&x);
    }

    //Por si no se introdujo ningún valor válido (el primero fue negativo)
    if(n==0){
        printf("No se ingresó ningún valor válido.");
    }else{
    //Aquí se muestra el valor
        printf("La media de alturas es: %.3f \n", media/n);
        printf("La altura mínima fue: %f \n", min);
        printf("La altura máxima fue: %f \n", max);
    }

return 0;
}