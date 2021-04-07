/*
Autor:  Luis Icú
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

float sum(float A, float B){ //La función suma
    float sumtot=0; //El total de la suma

    printf("Ha seleccionado A+B \n");
    printf("Ingresar A: \n");
    scanf("%f",&A);
    printf("Ingresar B: \n");
    scanf("%f",&B);
    sumtot = A+B;
    printf("%f + %f = %f \n", A, B, sumtot);
    return sumtot;
}

float rest(float A, float B){ //La función resta
    float restot=0; //El total de la resta

    printf("Ha seleccionado A-B \n");
    printf("Ingresar A: \n");
    scanf("%f",&A);
    printf("Ingresar B: \n");
    scanf("%f",&B);
    restot = A-B;
    printf("%f - %f = %f \n", A, B, restot);
    return restot;
}

float multi(float A, float B){ //La función de multiplicación
    float multitot=0; //El total de la multiplicación
    
    printf("Ha seleccionado A*B \n");
    printf("Ingresar A: \n");
    scanf("%f",&A);
    printf("Ingresar B: \n");
    scanf("%f",&B);
    multitot = A*B;
    printf("%f * %f = %f \n", A, B, multitot);
    return multitot;
}

float divi(float A, float B){ //La función de división
    float divtot=0; //El total de la división

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
    int k=0;
    while (k == 0){ //Va a funcionar hasta que le cambiemos el valor al k
        float A=0;
        float B=0;
        int ind=0; //ind de indicador

        //Imprimimos cosas y pedimos qué operación se quiere realizar
        printf("¿Qué operación desea realizar? \n");
        printf("1. Suma \n");
        printf("2. Resta \n");
        printf("3. Multiplicación \n");
        printf("4. División \n");
        printf("0. Salir \n");
        scanf("%d",&ind);

        //Verificamos
        if(ind == 1){
            sum(A,B); //Va a la función suma
        } else if(ind == 2){
            rest(A,B); //Va a la función resta
        } else if(ind == 3){
            multi(A,B); //Va a la función multiplicación
        } else if(ind == 4){
            divi(A,B); //Va a la función división
        } else if(ind == 0){
            printf("Gracias \n");
            k = 1; //Si se quiere salir, se cambia el valor de k y sale del while
        } else {
            printf("Ingrese un número válido \n");
        }
    }
    
return 0;
}




