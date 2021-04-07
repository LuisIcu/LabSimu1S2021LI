/*
Autor:  root
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc raizcuadrara1603.c -o raizcuadrara1603
Fecha: Sun Mar 21 01:44:39 UTC 2021
Librerías: 
Resumen: 
Se ingresa un número positivo. El programa busca su raíz cuadrada
y le aplica la función piso, o sea, busca el entero menor a esta
raíz cuadrada.
*/
 
//Librerías
#include <stdio.h>


int main(){
//Iniciamos las variables globales

    float N=0;
    int i=0;

    printf("Ingresar un número positivo: ");
    scanf("%f",&N);

    //Por si ingresa un número negativo
    if(N<0){
        printf("No existe raíz cuadrada en los reales\n");
    } else if(N==0){
    //Por si ingresa el cero
        printf("La raíz cuadrada es: 0");
    } else if(N>0){
    //Busca el entero que se acerque más a la raíz cuadrada
        while(i*i <= N){
            i++;
        }
        printf("La raíz cuadrada es: %d \n", i-1);
    }

return 0;
}