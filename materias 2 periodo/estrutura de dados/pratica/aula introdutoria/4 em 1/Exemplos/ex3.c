#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num, linhas, colunas, **matriz, maior, menor;
    float media;
    scanf("%d", &num);

    for(int i=0; i<num; i++){
      scanf("%d", &linhas);
      scanf("%d", &colunas);

      maior=0;
      menor=1000;
      media=0;

      matriz=malloc(linhas *sizeof(int));
      for(int j=0; j<linhas; j++){
        matriz[j]=malloc(colunas *sizeof(int));
        for(int k=0; k<colunas; k++){
          scanf("%d", &matriz[j][k]);
          if(matriz[j][k]>maior){
            maior=matriz[j][k];
          }
          if(matriz[j][k]<menor){
            menor=matriz[j][k];
          }
          media+=matriz[j][k];
        }
      }
      media=media/(linhas*colunas);
      printf("%d %d %f\n\n", maior, menor, media);
      for(int i=0; i<linhas; i++){
        free(matriz[i]);
      }
      free(matriz);
    }

    return 0;
}
