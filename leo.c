#include <stdio.h>

int main(){
    float pivo;
    int n = 3;
    int k;

    float matriz[3][4] = {
        {1, 1, 1, 6},
        {2, 3, 7, 20},
        {1, 3, 4, 14},
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