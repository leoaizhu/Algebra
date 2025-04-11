#include <stdio.h>

int main(){
    printf("Codigo de Gauss\n");
    float pivo;
    int n = 3;
    int k;

    float matriz[3][4] = {
        {1, 2, 1, 8},
        {2, 1, 3, 17},
        {3, 3, 2, 20},
    };


    for (int i = 0; i < n;i++){
        pivo = matriz[i][i];
        for (int j = 0; j < n + 1;j++){
            matriz[i][j] = matriz[i][j] / pivo;
        }
 
        for (k = 0; k < n ;k++){
            if(k!=i){
                float fator = matriz[k][i];
                for (int j = 0; j < n + 1;j++){
                    matriz[k][j] -= fator * matriz[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n;i++){
            printf("olaaaa %.6f\t", matriz[i][n]);
        }
    
}