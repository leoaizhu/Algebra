#include <stdio.h>
#include <math.h>

# define H 0.1
# define parar 0.0001

double definido(double x){

    float resultado = -2 * (1 + pow(x, 2));
    return resultado;
}

void GS(){
  double estatico = definido(H);
  double x[31] = {0}; 
  double r[31][200]={0};
  int k = 1;
   
    while(k<200){
        x[1] = (1 - x[2]) / estatico;
        r[1][k] = x[1];

            for (int i = 2; i < 30;i++){
                x[i] = (-x[i-1] - x[i+1]) / estatico;
                r[i][k] = x[i];
            }

        x[30] = (1 - x[29]) / estatico;
        r[30][k] = x[30];

        int converge = 0;
        double soma;
            for (int leo = 1; leo < 31;leo++){
                soma = -1*(r[leo][k] - r[leo][k - 1]);
                if(soma<parar){
                    converge++;
             }
            } 
        
            if(converge==30)
                {
                printf("CONVERGIU NA LINHA: %d\n", k);
                break;
            } 
        k++;
        
    }

            for (int j = 1; j <=k;j++){
                   printf("I : %d\n", j);
                   for (int i = 1; i < 31; i++)
                    { 
                      printf("X[%d] : %.9f , DIFF = %.9f\n", i, r[i][j],-1*(r[i][j]-r[i][j-1]));
            }   
          } 
        }

    
int main(){


    GS();

    return 0;
}