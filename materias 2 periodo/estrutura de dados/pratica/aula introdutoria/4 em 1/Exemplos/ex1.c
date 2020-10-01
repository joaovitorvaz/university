#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fatorials(int k);

int main()
{
    int z, *termosN, k, aux;
    double *cossen, *grauX, cossenprovi, fatorial;

    scanf("%d", &z);

    grauX = malloc(z * sizeof(double));
    termosN = malloc(z * sizeof(int));
    cossen = malloc(z * sizeof(double));

    for(int i=0; i<z; i++){
      scanf("%lf", &grauX[i]);
      scanf("%d", &termosN[i]);
      grauX[i]=grauX[i]*0.0174532925;
    }

    for(int i=0; i<z; i++){
      cossen[i]=1;
      aux=1;
      for(int j=0; j<termosN[i]; j++){
          k=2;
          fatorial=(fatorials(k));
          cossenprovi=pow(grauX[i], k)/fatorial;

          if(aux==1){
            cossenprovi=cossenprovi*-1;
          }

          cossen[i]+=cossenprovi;
          k+=2;

          if(aux==1){
            aux=0;
          }
          else
            aux=1;
      }
    }

    for(int i=0; i<z; i++){
      printf("%.2lf %d  %lf\n", grauX[i], termosN[i], cossen[i]);
    }

    free(grauX);
    free(termosN);
    free(cossen);

    return 0;
}

int fatorials(int k)
{
    int fatorial=1;
    for(int i=1; i<=k; i++){
      fatorial*=i;
    }
    return (fatorial);
}
