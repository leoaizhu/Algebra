#include <stdio.h>
#include <math.h>

#define H 0.1
#define parar 0.0001

double definido(double x){

    float resultado = -2 * (1 + pow(x, 2));
    return resultado;
}

void GJ(){

    double estatico = definido(H);
    double x[31]={0};
    double temporario[31] = {0};
    double resultado[31][300] = {0};
    int k = 1;

    while(k<300){
    
        temporario[1] = x[1];
        x[1] = (1 - x[2]) / estatico;
        resultado[1][k] = x[1];

        for (int i = 2; i < 29;i++){
            temporario[i] = x[i];
            x[i] = (-temporario[i-1] - x[i+1]) / estatico;
            resultado[i][k] = x[i];
    
            }
        x[30] = (1 - temporario[29]) / estatico;
        resultado[30][k]=x[30];

        int converge = 0;
        double soma;
        for (int leoleo = 1; leoleo < 31;leoleo++){
            soma = -1 * (resultado[leoleo][k] - resultado[leoleo][k - 1]);
            if(soma<parar){
                converge++;
            }
        }
        if(converge==30){
            printf("Convergiu na linha %d\n\n", k);
            break;
        } 
        k++;
}

for (int j = 1; j <= k;j++){
    printf("I : %d\n", j);
    for (int i= 1; i < 31;i++){
        printf("X[%d] : %.9f, DIFF = %.9f\n",i, resultado[i][j],-1*(resultado[i][j]-resultado[i][j-1]));
    }
    printf("\n");
}

}

int main(){

    GJ();
    return 0;

}