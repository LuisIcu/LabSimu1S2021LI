/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc series.c -lm -o series
Fecha: Sun Apr 18 00:09:02 CST 2021
Librerías: math.h, stdio.h
Resumen: Calculadora de distintas series
Entrada: El límite superior n de las series
Salida: La respectiva serie
*/
 
//Librerías
#include <math.h>
#include <stdio.h>


double serie1(int n);
double serie2(int n);
double serie3(int n);
double serie4(int n);

void main(){
    int k=0;
    while (k == 0){ //Va a funcionar hasta que le cambiemos el valor al k
        int n=0; //Hasta el n a sumar
        int ind=0; //ind de indicador

        //Imprimimos cosas y pedimos qué operación se quiere realizar
        printf("¿Qué serie desea realizar? \n");
        printf("1. k^2(k-3) \n");
        printf("2. 3/(k-1) \n");
        printf("3. [1/((2^n)(sqrt(5)))][(1+sqrt(5))^n-(1-sqrt(5))^n] \n");
        printf("4. 0.1*(3*2^(k-2)+4) \n");
        printf("0. Salir \n");
        scanf("%d",&ind);

        //Verificamos
        if(ind == 1){
            serie1(n); //Va a la función suma
        } else if(ind == 2){
            serie2(n); //Va a la función resta
        } else if(ind == 3){
            serie3(n); //Va a la función multiplicación
        } else if(ind == 4){
            serie4(n); //Va a la función división
        } else if(ind == 0){
            printf("Gracias \n");
            k = 1; //Si se quiere salir, se cambia el valor de k y sale del while
        } else {
            printf("Ingrese un número válido \n");
        }
    }

}

//Todas las series es escribir la respectiva serie con un for que suma hasta el valor desado

double serie1(int n){
    double totser1=0;

    printf("Ha seleccionado:\n");
    printf(" k^2(k-3)\n");
    printf("Ingresar el valor n: \n");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++){
        totser1 += pow(i, 2)*(i-3);
    }
    printf("El valor de la sumatoria es:\n");
    printf("%f\n", totser1);
    return totser1;
}

double serie2(int n){
    double totser2=0;

    printf("Ha seleccionado:\n");
    printf(" 3/(k-1)\n");
    printf("Ingresar el valor n: \n");
    scanf("%d",&n);

    for (int i = 2; i <= n; i++){
        totser2 += 3*pow(i-1,-1);
    }
    printf("El valor de la sumatoria es:\n");
    printf("%f\n", totser2);
    return totser2;
}

double serie3(int n){
    float totser3=0;

    printf("Ha seleccionado:\n");
    printf(" [1/((2^n)(sqrt(5)))][(1+sqrt(5))^n-(1-sqrt(5))^n]\n");
    printf("Ingresar el valor n: \n");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++){
        totser3 += (1/(sqrt(5)*pow(2, i)))*(pow(1+sqrt(5), i)-pow(1-sqrt(5), i));
    }
    printf("El valor de la sumatoria es:\n");
    printf("%f\n", totser3);
    return totser3;
}

double serie4(int n){
    double totser4=0;

    printf("Ha seleccionado:\n");
    printf(" 0.1*(3*2^(k-2)+4)\n");
    printf("Ingresar el valor n: \n");
    scanf("%d",&n);

    for (int i = 2; i <= n; i++){
        totser4 += 0.1*(3*pow(2, i-2)+4);
    }
    printf("El valor de la sumatoria es:\n");
    printf("%f\n", totser4);
    return totser4;
}



