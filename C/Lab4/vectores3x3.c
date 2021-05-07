/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc vectores3x3.c -lm -o vectores3x3
Fecha: Wed May  5 15:37:23 CST 2021
Librerías: stdio.h, math.h
Resumen: Calculadora de distintas operaciones con vectores: magnitud, suma, producto punto, producto cruz
Entrada: 1 o 2 vectores de dim3, dependiendo de la operación realizada
Salida: La operación resultante
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

//Variables
float A[3], B[3], totvec[3];
int ind;
float magnusA, magnusB, result;

//funciones a utilizar
void imprimir(float vector[]); //Imprime un vector
void ingvector(float vector[]); //Ingresa los datos de un vector 3x3
float magnitud(float vector[]); //Da la magnitud del vector
void suma(float vector1[], float vector2[], float vectorsuma[]); //Suma los vectores
float escalar(float vector1[], float vector2[]); //Da el producto escalar de dos vectores
int permutacion(int val1, int val2, int val3); //Da el signo de la permutación de 3 valores (signo de Levi-Civita)
void vectorial(float vector1[], float vector2[], float vectorcruz[]); //Da el producto vectorial de dos vectores 



void main(){
    int k=0;
    while (k == 0){ //Va a funcionar hasta que le cambiemos el valor al k
        //Imprimimos cosas y pedimos qué operación se quiere realizar
        printf("--Operaciones con 2 vectores de dimensión 3--\n");
        printf("¿Qué operación desea realizar?\n");
        printf("1. Ver la magnitud de cada vector\n");
        printf("2. Sumar los vectores\n");
        printf("3. El producto escalar entre los vectores\n");
        printf("4. El producto vectorial AxB\n");
        printf("0. Salir\n");
        scanf("%d",&ind);

        //Verificamos
        if(ind == 1){ //Magnitud
            printf("Ingrese el vector A: \n");
            ingvector(A);
            printf("Ingrese el vector B: \n");
            ingvector(B);
            magnusA = magnitud(A);
            magnusB = magnitud(B);
            printf("--1. Magnitudes--\n");
            printf("La magnitud del vector A es: %f\n", magnusA);
            printf("La magnitud del vector B es: %f\n", magnusB);
        } 
        
        else if(ind == 2){ //Suma
            printf("Ingrese el vector A: \n");
            ingvector(A);
            printf("Ingrese el vector B: \n");
            ingvector(B);
            suma(A,B, totvec);
            printf("El vector suma resultante es:\n");
            imprimir(totvec);
        } 
        
        else if(ind == 3){ //Producto escalar
            printf("Ingrese el vector A: \n");
            ingvector(A);
            printf("Ingrese el vector B: \n");
            ingvector(B);
            result = escalar(A,B);
            printf("El producto escalar es: %f\n",result);
        } 
        
        else if(ind == 4){ //Producto vectorial
            printf("Ingrese el vector A: \n");
            ingvector(A);
            printf("Ingrese el vector B: \n");
            ingvector(B);
            vectorial(A,B,totvec);
            printf("El vector AxB es:\n");
            imprimir(totvec);
        } 
        
        else if(ind == 0){
            printf("Gracias \n");
            k = 1; //Si se quiere salir, se cambia el valor de k y sale del while
        } else {
            printf("Ingrese un número válido \n");
        }
    }
}



void imprimir(float vector[]){ //Imprime un vector
    printf("[");
    for (int i=0; i<3; i++){
        printf("%f, ",vector[i]);
    }
    printf("]");
} 

void ingvector(float vector[]){ //Ingresa los datos de un vector 3x3
    for (int i=0; i<3; i++){
        printf("Ingresar el dato %d: ", i+1);
        scanf("%f",&vector[i]);
    }
}

float magnitud(float vector[]){ //Da la magnitud del vector
    float magnus=0;
    float sqrtmagnus=0;
    for (int i = 0; i < 3; i++)
    {
        magnus += vector[i]*vector[i];
    }
    sqrtmagnus=sqrt(magnus); 
    return sqrtmagnus;
}

void suma(float vector1[], float vector2[], float vectorsuma[]){ //Suma los vectores
    for (int i = 0; i < 3; i++)
    {
        vectorsuma[i] = vector1[i]+vector2[i];
    } 
}

float escalar(float vector1[], float vector2[]){ //Da el producto escalar de dos vectores
    float scalar=0;
    for (int i = 0; i < 3; i++)
    {
        scalar += vector1[i]*vector2[i];
    }
    return scalar;
}

int permutacion(int val1, int val2, int val3){ //(signo de Levi-Civita)
    int signo;
    if (val1 == val2 || val2 == val3 || val3 == val1){
        signo = 0;
    }else if(val1 < val2 && val2 < val3){ //1
        signo = 1;
    }else if(val1 < val2 && val3 < val1){ //2
        signo = 1;
    }else if(val2 < val3 && val3 < val1){ //3
        signo = 1;
    }else if(val2 > val3 && val3 > val1){ //4
        signo = -1;
    }else if(val1 > val2 && val3 > val1){ //5
        signo = -1;
    }else if(val1 > val2 && val2 > val3){ //6
        signo = -1;
    }
    return signo;
}

void vectorial(float vector1[], float vector2[], float vectorcruz[]){ //Da el producto vectorial de dos vectores
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k=0; k < 3; k++){
                vectorcruz[i] += permutacion(i,j,k)*vector1[j]*vector2[k];
            }
        }
    }
    
}