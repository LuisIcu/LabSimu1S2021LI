/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc EcLinealPV.c -lm -o EcLinealPV
Fecha: Sun May  2 12:44:25 CST 2021
Librerías: 
Resumen: 
Entrada: 
Salida: 
*/
 
//Librerías
#include <stdio.h>
#include <math.h>

//Ingresar los datos de P y V
float datosV[6]={54.3, 61.8, 72.4, 88.7, 118.6, 194};
float datosP[6]={61.2, 49.2, 37.6, 28.4, 19.2, 10.2};
float dV=0.1; //Incerteza en V
float dP=0.2; //Incerteza en P

//Iniciamos variables globales
int n = sizeof(datosV)/sizeof(datosV[0]); //número de datos
float A, B, r, a, b, vnuevo, pnuevo;

//Listas que nos van a servir después
float datosLnV[6];
float datosLnP[6];

//Prototipos de funciones
void converLn(float datos[], float datosLn[]); //pasar de lista P(x) a Q(ln(x))
void imprimvec(float lista[]); //Imprimir los datos de un vector
float sumdata(float datos[]); //Sumar los datos de un vector
float sumdatamul(float datos1[], float datos2[]); //Toma los datos de dos listas, multiplica por orden y suma
float deltaM(float datos[]); //Obtiene el denominador delta usada para hallar A y B
float pendiente(float datos1[], float datos2[]); //Obtiene la pendiente de la regresión lineal
float intersecto(float datos1[], float datos2[]); //Obtiene el intersecto de la regresión lineal

void main(){

    //Obtenemos el vector de datos convertidos
    converLn(datosV,datosLnV);
    converLn(datosP,datosLnP);

    //Imprimimos los vectores V y P
    printf("Imprimiendo los valores de V y P\n");
    printf("V: ");
    imprimvec(datosV);
    printf("P: ");
    imprimvec(datosP);

    //Imprimimos los vectores LnV y LnP
    printf("Imprimiendo los valores de ln(V) y ln(P)\n");
    printf("ln(V): ");
    imprimvec(datosLnV);
    printf("ln(P): ");
    imprimvec(datosLnP);

    //Escribiendo un poco para que se entienda
    printf("Inicialmente tenemos una relación PV^(a) = b\n");
    printf("Usando logaritmos, lo pasamos a ln(P)=-a*ln(V)+ln(b)\n");
    printf("Usando regresión lineal, calculamos A=-a y B=ln(b)\n");
    printf("ln(P) = Aln(V)+B\n");

    //Obtenemos las constantes
    A=pendiente(datosLnV,datosLnP)/deltaM(datosLnV);
    B=intersecto(datosLnV,datosLnP)/deltaM(datosLnV);
    r=(n*sumdatamul(datosLnV,datosLnP)-sumdata(datosLnV)*sumdata(datosLnP))/sqrt((n*sumdatamul(datosLnV,datosLnV)-sumdata(datosLnV)*sumdata(datosLnV))*(n*sumdatamul(datosLnP,datosLnP)-sumdata(datosLnP)*sumdata(datosLnP)));


    //Imprimiendo la ecuación lineal
    printf("Tenemos entonces la ecuación:\n");
    printf("y = %f x + %f\n",A,B);
    printf("Coeficiente de correlación: %f\n",r*r);

    //Recuperando las constantes a y b
    a = -A;
    b = exp(B);

    //Imprimiendo la ecuación real
    printf("Obtenemos las constantes importantes:\n");
    printf("a = -A y b = exp(B)\n");
    printf("Tenemos entonces: a= %f y b= %f\n",a,b);
    printf("La ecuación final es: PV^(%f)=%f\n",a,b);

    //Se pregunta por un valor de V y regresa el valor de P esperado
    printf("Ingresar el valor de V:");
    scanf("%f",&vnuevo);
    pnuevo = b/pow(vnuevo,a);
    printf("El valor asociado a V=%f es P=%f\n",vnuevo,pnuevo);

}


//Si existe la lista P(x) obtener una lista Q(ln(x))
void converLn(float datos[], float datosLn[]){
    for (int i=0; i< n; i++){
        datosLn[i] = log(datos[i]); 
    } 
}

//Imprimir los datos de una lista
void imprimvec(float datos[]){
    for (int i=0; i<n; i++){
        printf("%f ",datos[i]);
    }
    puts("\n");
}   

//se realiza la suma de un vector determinado
float sumdata(float datos[]){
    float rep=0;
    for (int i = 0; i < n; i++)
    {
        rep += datos[i];
    }
    return rep;
}

//se realiza la suma de dos vectores, multiplicando cada uno de sus valores  de forma consecurtiva
float sumdatamul(float datos1[], float datos2[]){
    float rep=0;
    for (int i = 0; i < n; i++)
    {
        rep += datos1[i]*datos2[i];
    }
    return rep;
}


//Obtiene el denominador delta usada para hallar A y B
float deltaM(float datos[]){
    float delta;
    delta = n*sumdatamul(datos,datos)-pow(sumdata(datos),2);
    return delta;
}

//Obtiene la pendiente de la regresión lineal
float pendiente(float datos1[], float datos2[]){
    float pend;
    pend = (n*sumdatamul(datos1, datos2)-sumdata(datos1)*sumdata(datos2));
    return pend;
}   

//Obtiene el intersecto de la regresión lineal
float intersecto(float datos1[], float datos2[]){
    float inter;
    inter = (sumdatamul(datos1,datos1)*sumdata(datos2)-sumdata(datos1)*sumdatamul(datos1,datos2));
    return inter;
}

