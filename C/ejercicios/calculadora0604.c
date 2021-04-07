/*
Autor:  root
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc calculadora.c -o calculadora
Fecha: Tue Apr  6 23:32:00 UTC 2021
Librerías: 
Resumen: 
Entrada: 
Salida: 
*/
 
//Librerías
#include <stdio.h>

//Numerar pasos del pseudocódidgo

float sum(float A, float B){
    float sumtot=0;

    printf("Ha seleccionado A+B \n");
    printf("Ingresar A: \n");
    scanf("%f",&A);
    printf("Ingresar B: \n");
    scanf("%f",&B);
    sumtot = A+B;
    printf("%f + %f = %f \n", A, B, sumtot);
    return sumtot;
}

float rest(float A, float B){
    float restot=0;

    printf("Ha seleccionado A-B \n");
    printf("Ingresar A: \n");
    scanf("%f",&A);
    printf("Ingresar B: \n");
    scanf("%f",&B);
    restot = A-B;
    printf("%f - %f = %f \n", A, B, restot);
    return restot;
}

float multi(float A, float B){
    float multitot=0;
    
    printf("Ha seleccionado A*B \n");
    printf("Ingresar A: \n");
    scanf("%f",&A);
    printf("Ingresar B: \n");
    scanf("%f",&B);
    multitot = A*B;
    printf("%f * %f = %f \n", A, B, multitot);
    return multitot;
}

float divi(float A, float B){
    float divtot=0;

    printf("Ha seleccionado A/B \n");
    printf("Ingresar A: \n");
    scanf("%f",&A);
    printf("Ingresar B: \n");
    scanf("%f",&B);
    divtot = A/B;
    printf("%f / %f = %f \n", A, B, divtot);
    return divtot;
}


int main(){
    float A=0;
    float B=0;
    int ind=0; //ind de indicador

    printf("¿Qué operación desea realizar? \n");
    printf("1. Suma \n");
    printf("2. Resta \n");
    printf("3. Multiplicación \n");
    printf("4. División \n");
    printf("0. Salir \n");
    scanf("%d",&ind);

    if(ind == 1){
        sum(A,B);
    } else if(ind == 2){
        rest(A,B);
    } else if(ind == 3){
        multi(A,B);
    } else if(ind == 4){
        divi(A,B);
    } else if(ind == 0){
        printf("Gracias \n");
    } else {
        printf("Ingrese un número válido \n");
    }

return 0;
}


