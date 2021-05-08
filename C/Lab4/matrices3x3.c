/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc matrices3x3.c -lm
Fecha: Wed May  5 18:32:01 CST 2021
Librerías: stdio.h, math.h
Resumen: Calculadora de varias operaciones con matrices de dim3
multiplicar por una constante, sumar, restar, multiplicar, determinante y transpuesta
Entrada: Una o dos matrices 
Salida: La operación deseada
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

//Variables
float matA[3][3], matB[3][3], kmat[3][3], summat[3][3], resmat[3][3], mulmat[3][3], transmat[3][3];
float cons, resultado;


//Funciones
void imprimir(float matriz[3][3]); //Imprime una matriz
void ingresar(float mat[3][3]); //Ingresar los datos de una matriz
void constante(float mat[3][3], float constmat[3][3], float a); //multiplicar una matriz por una constante
void suma(float mat1[3][3],float mat2[3][3],float summat[3][3]); //suma dos matrices
void resta(float mat1[3][3],float mat2[3][3],float restmat[3][3]); //resta dos matrices
void multi(float mat1[3][3],float mat2[3][3],float multmat[3][3]); //multiplica dos matrices
int permutacion(int val1, int val2, int val3); //Da el signo de la permutación de 3 valores (signo de Levi-Civita)
float determinante(float mat[3][3]); //Saca el determinante de la matriz
void transpuesta(float mat[3][3], float transmat[3][3]); //Muestra el determinante de una matriz


void main(){
    printf("--Operaciones con matrices 3x3--\n");
    printf("Ingresar los valores de matA: \n");
    ingresar(matA);
    printf("Ingresar los valores de matB: \n");
    ingresar(matB);
    printf("Ingresar una constante: \n");
    scanf("%f",&cons);

    //k*matA
    printf("1. k*matA\n");
    constante(matA, kmat, cons);
    imprimir(kmat);

    //Suma A+B
    printf("2. matA+matB\n");
    suma(matA,matB,summat);
    imprimir(summat);

    //Resta A-B
    printf("3. matA-matB\n");
    resta(matA,matB,resmat);
    imprimir(resmat);

    //Multiplicación AB
    printf("4. matA*matB\n");
    multi(matA,matB,mulmat);
    imprimir(mulmat);

    //detA
    printf("5. det(A)\n");
    resultado = determinante(matA);
    printf("det(A)= %f\n", resultado);

    //B transpuesta
    printf("6. matB^t\n");
    transpuesta(matA, transmat);
    imprimir(transmat);
}


void imprimir(float mat[3][3]){//Imprime una matriz
    for (int i=0; i<3; i++){
        printf("[");
        for (int j=0; j<3; j++){
            printf("%f, ",mat[i][j]);
        }
        printf("]\n");
    }
}

void ingresar(float mat[3][3]){//Ingresar los datos de una matriz
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("Ingresar el dato %d,%d: ", i+1,j+1);
            scanf("%f",&mat[i][j]);
        }
    }
}

void constante(float mat[3][3], float constmat[3][3], float a){//multiplicar una matriz por una constante
    for (int i = 0; i<3; i++){
        for (int j=0; j<3; j++){
            constmat[i][j] = a*mat[i][j];
        }
    }
}

void suma(float mat1[3][3],float mat2[3][3],float summat[3][3]){//suma dos matrices
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            summat[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
}

void resta(float mat1[3][3],float mat2[3][3],float restmat[3][3]){//resta dos matrices
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            restmat[i][j] = mat1[i][j]-mat2[i][j];
        }
    }
}

void multi(float mat1[3][3],float mat2[3][3],float multmat[3][3]){//multiplica dos matrices
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            for (int r=0; r<3; r++){
                multmat[i][j] += mat1[i][r]*mat2[r][j];
            }
        }   
    }
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

float determinante(float mat[3][3]){//Saca el determinante de la matriz por el método de Levi-Civita
    float det=0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                det += permutacion(i,j,k)*mat[i][0]*mat[j][1]*mat[k][2];
            }
        }   
    }
    return det;
}

void transpuesta(float mat[3][3], float transmat[3][3]){//Muestra el determinante de una matriz
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            transmat[i][j] = mat[j][i];
        }
    }
}