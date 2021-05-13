/*
Autor:  luisicu
Compilador:  gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Para compilar: gcc examenfinal.c -lm
Fecha: Thu May 13 10:22:11 CST 2021
Librerías: 
Resumen: 
Entrada: 
Salida: 
*/
 
//Librerías
#include <stdio.h>
#include <math.h>


//Definimos constantes universales
float G = 6e-11; //constante de gravitación
float Rt = 6.378e6; //radio de la tierra
float Mt = 5.973e24;//masa de la tierra
float R = 287.6;//constante de gases
float L = 6.5e-3;//cons
float g0 = 9.81;//gravedad a nivel del mar
float T0 = 288.15;//temperatura a nivel del mar
float P0 = 101325;//presión a nivel del mar

//Constantes del cohete
float E0;//Empuje
float TSFC;//Consumo específico de empuje
float CD;//Coeficiente de forma
float A;//Sección transversal del cohete
float m0;//Masa del propulsor
float mf0;//Masa inicial de combustible


//Valores de las constantes del cohete
//Cada sublista está ordenada de esta forma
//{E0, TSFC, CD, A, m0, mf0}
float caracteristicas[3][6]={{3e7,3.248e-4,61.27,201.6,1.1e5,1.5e6},{2.7e7,2.248e-4,61.27,201.6,1.1e5,1.5e6},{2.5e7,2.248e-4,70.25,215,1.8e5,2.1e6}};

//Constantes del problema
float dt = 0.1;//intervalo de tiempo
float tiempoin=0;//Comienza en t=0
float yin=0.65;//altura inicial
float velin=0;//velocidad inicial


float gravedad(float y);//Gravedad a cierta altura
float densidad(float y);//Densidad a cierta altura
float friccion(float y, float dy);//fricción a cierta altura
float masacomb(float t); //masa de combustible
float masacohete(float t);//masa del cohete
float empuje(float mf);//Fuerza de empuje
float aceleracion(float y, float dy, float t);//aceleración

int main(){
    //constantes locales
    int ind;//indicador para ver cuál cohete usar
    float altn,altn1,veln,veln1;//constantes para el método numérico
    float tiempo, altmax;

    //Este for es para pasar por las 3 listas, o sea, los tres cohetes
    for (ind = 0; ind < 3; ind++){
        if (ind==0){
            printf("--Ah Mun--\n");
        }else if(ind==1){
            printf("--Ahau Kin--\n");
        }else if(ind==2){
            printf("--Chac--\n");
        }

        //Según qué cohete toque usamos esa sublista para las constantes
        E0=caracteristicas[ind][0];
        TSFC=caracteristicas[ind][1];
       CD=caracteristicas[ind][2];
        A=caracteristicas[ind][3];
        m0=caracteristicas[ind][4];
        mf0=caracteristicas[ind][5];

        //Imprimimos
        printf("Empuje: %f N\n",E0);
        printf("Consumo específico: %f kg/(N s)\n",TSFC);
        printf("Coeficiente de forma: %f\n",CD);
        printf("Sección transversal: %f m^2\n",A);
        printf("Masa del propuslor: %f kg\n",m0);
        printf("Masa inicial: %f kg\n",mf0);

        //Aquí usamos el método de Euler para una ecuación de segundo orden
        //Si tenemos un y(x) y sus dos primeras derivadas, si podemos despejar la segunda y''(x) = f(x,y,y')
        //y tenemos y(x0) y y'(x0) entonces podemos hallar para algún x:
        //y_{n+1} = y_{n}+h*y'_{n}
        //y'_{n+1} = y'_{n}+h*f(x_n,y_n,y'_n)
        //Para este caso, alt es la altura, vel es velocidad
        //si termina en n se refiere al n-ésimo término, si termina en n1 es el (n+1)-ésimo término

        //Obtenemos los alt_1 y vel_1 a partir de los iniciales
        altn = yin+dt*velin;
        veln = velin+dt*aceleracion(yin, velin, tiempoin);

        //Aumentamos el intervalo de tiempo
        tiempo = tiempoin+dt;

        //Obtenemos los siguientes
        altn1 = altn+dt*veln;
        veln1 = veln+dt*aceleracion(altn, veln, tiempo);

        //A partir de aquí lo hacemos con un do-while, hasta que detecte una altura negativa
        do{
            altn=altn1;
            veln=veln1; 

            tiempo += dt;
            altn1 = altn+dt*veln;
            veln1 = veln+dt*aceleracion(altn, veln, tiempo);

            if (round(veln1)==0){
                altmax = altn;//Cuando la velocidad aproxime a cero, significa que estamos en el punto más alto
            }
        }while(altn>0);
    
        printf("Tiempo en quedarse sin combustible: %f s\n", mf0/(TSFC*E0));//De la ecuación del comustible, calculamos cuando se anula
        printf("El tiempo que tardó en caer fue: %f min\n",tiempo/60);//El momento cuando cae
        printf("La altura máxima fue: %f m\n",altmax);//Altura máxima
    }
    return 0;
}

//Las funciones que utilizamos
//Todas están a formulazo
float gravedad(float y){//Gravedad a cierta altura
    float g;
    g = (G*Mt)/pow(Rt+y,2);
    return g;
}

float densidad(float y){//Densidad a cierta altura
    float rho;
    //Este if hace que se cumpla la condición que solo aplica a cierta altura
    if (y<=T0/L){
        rho = (P0/(R*T0))*pow(1-(L*y)/(T0),g0/(R*L));
    }else{
        rho=0;
    }
    return rho;
}

float friccion(float y, float dy){//fricción a cierta altura
    float fric;
    fric = (densidad(y)/2)*CD*A*dy*fabs(dy);
    return fric;
}

float masacomb(float t){//masa del combustible
    float fcomb;
    float mf;
    mf = -TSFC*E0*t+mf0;
    if (mf <=0){//A partir de cierto valor, ya no toma en cuenta esto para no tomar masas negativas
        fcomb=0;
    }else{
        fcomb=mf;
    }
    return fcomb;
}

float masacohete(float t){//masa del cohete
    float mcohete;
    mcohete = m0 + masacomb(t);
    return mcohete;
}

float empuje(float mf){//Fuerza de empuje
    float emp;
    if (mf > 0){//Solo cuando hay combustible hay empuje
        emp=E0;
    }else{
        emp = 0;
    }
    return emp;
}

float aceleracion(float y, float dy, float t){//ecuación para la aceleración
    float acel;
    acel = (empuje(masacomb(t))-friccion(y,dy)-masacohete(t)*gravedad(y))/masacohete(t);
    return acel;
}



