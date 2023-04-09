/*
Programa de Regresion Lineal

Compilacion: g++ main.cpp -o Ejecutable -std=c++11
Ejecucion: ./Ejecutable
*/

#include <iostream>
#include <unistd.h>
#include <math.h>

using namespace std;

double Theta_Init(int);
double S_Function(double*, int*, int, int);
double Sigmoid(double);     //Funcion de probabilidad
double Y_g(double);
double Cost_Function(int*, int, int, double);


int main(){
    int X[] = {1,  1, 1,
               1,  1, 3,
               1,  2, 4,
               1,  2, 6,
               1,  3, 2,
               1,  3, 8,
               1,  4, 5,
               1,  4, 9,
               1,  5, 2,
               1,  5, 4,
               1,  5, 8,
               1,  6, 6,
               1,  7, 1,
               1,  7, 7,
               1,  7, 9,
               1,  8, 4,
               1,  9, 1,
               1, 10, 2,
               1, 10, 5,
               1, 12, 1};
    int Yo[]  = {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0,  1,  1,  1};
    double Theta_act[3] = {0};
    int columns = 3;
    int rows = sizeof(X)/(4*columns);   //El 4 es porque el int es de 4 bytes
    
    double phat, y, J;
    int i;

    Theta_act[0] = Theta_Init(0);
    Theta_act[1] = Theta_Init(1);
    Theta_act[2] = Theta_Init(2);

    for(i = 0 ; i < rows ; i++){
        phat = Sigmoid(S_Function(Theta_act, X, i, columns));
        y = Y_g(phat);
        J += Cost_Function(Yo, rows, i, phat);
        cout<<"Iteracion "<<i+1<<endl;
        cout<<"Probabilidad: "<<p<<endl;
        cout<<X[i*columns + 1]<<" , "<<X[i*columns + 2]<<" , "<<Yo[i]<<endl<<endl;
        y = 0;
    }
    J = -J / (double)rows;
    cout<<"La funcion de costo es: "<<J<<endl;

    //cout<<"La funcion de costo es: "<<J<<endl;
    
    return 0;
}

double Theta_Init(int id){
    double Theta;
    int Sign;
    srand(id + (int)time(NULL));
    Sign = 1 + rand()%1000;
    if(Sign%2 == 0){    //Para genera numeros pseudoaleatorios positivos
        srand(id + (int)time(NULL));
        //Theta = 1 + rand()%9;
        Theta = 1 + ((rand()%(10001))/1000.00f);
    }
    else{               //Para generar numeros pseudoaleatorios negativos
        srand(id + (int)time(NULL));
        Theta = -9 + ((rand()%(-10001))/1000.00f);
    }
    return Theta;
}


double S_Function(double* Theta, int* X, int row, int col){
    return (Theta[0] + Theta[1]*X[row*col + 1] + Theta[2]*X[row*col + 2]);
}

double Sigmoid(double S){
    return 1/(1 + exp(-S));
}

double Y_g(double P){
    if(P < 0.5)
        return 0;
    return 1;
}

double Cost_Function(int* Y, int row, int i, double P){
    return Y[i]*log(P) + (1-Y[i])*log(1-P);
}
