/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc NewtonRaphson.c -lm -o NewtonRaphson
Fecha: Sun May  2 23:48:30 CST 2021
Librerías: 
Resumen: 
Entrada: 
Salida: 
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

//Variables importantes
int iter; //número de iteraciones
float tol; // tolerancia
float xin; //primera estimación
float xo; //este representa a x_{n}
float xop; //este representa a x_{n+1}
float difx; //difeencia xop-xo
int n=0; //un indicador que nos va a ayudar en el while

//Prototipos de funciones
float funcion(float x);
float derivada(float x);

void main(){
    printf("--Calcular una raíz real de sin(x)/x con Newton-Raphson--\n");
    printf("Ingresar la tolerancia aceptada: ");
    scanf("%f",&tol);
    printf("Ingresar el número de iteraciones: ");
    scanf("%d",&iter);
    printf("Ingresar un valor estimado inicial: ");
    scanf("%f",&xin);

    xo = xin - funcion(xin)/derivada(xin);

    if (fabs(xo-xin)<=tol)
    {
        n = iter +1;
        printf("Una raíz aproximada es %f\n",xo);
    }

    while (n <= iter){
        xop = xo - funcion(xo)/derivada(xo);
 
        if(fabs(xop-xo)<=tol){
            printf("Una raíz aproximada es %f\n",xop);
            n = iter+1;
        } else if (fabs(xop-xo) >= tol){
            xo = xop;
            n++;
        }
        
    }
    
}



float funcion(float x){
    float fx = 0;
    fx = sin(x)/x;
    return fx;
}

float derivada(float x){
    float devfx = 0;
    devfx = (x*cos(x)-sin(x))/(pow(x,2));
    return devfx;
}


