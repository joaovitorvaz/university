#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define T 4

void ex1();
void ex2();
void ex3();
void ex4();
int fatorials(int k);

int main()
{
  printf("\nBem vindo ao meu arquivo.\n\n");
  for(int i=0; i<T; i++){
    switch(i)
    {
       case 0:
        ex1();
       break;

       case 1:
        ex2();
       break;

       case 2:
        ex3();
       break;

       case 3:
        ex4();
       break;
    }
  }

  return 0;
}

void ex1()
{
  int z, *termosN, k, aux;
  double *cossen, *grauX, cossenprovi, fatorial;

  printf("--------------------------------------------------------------------------------------------------------------\n\n");

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

  printf("\n--------------------------------------------------------------------------------------------------------------");

}

void ex2()
{
  int num, *m, *supera;
  double *xa, *da, *ra, *saldoa;
  double *xb, *rb, *saldob;

  printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
  scanf("%d", &num);

  m=malloc(num *sizeof(int));
  supera=malloc(num *sizeof(int));
  xa=malloc(num *sizeof(double));
  xb=malloc(num *sizeof(double));
  da=malloc(num *sizeof(double));
  ra=malloc(num *sizeof(double));
  rb=malloc(num *sizeof(double));
  saldoa=malloc(num *sizeof(double));
  saldob=malloc(num *sizeof(double));

  for(int i=0; i<num; i++){
    scanf("%lf %lf %lf %lf %lf %d", &xa[i], &da[i], &ra[i], &xb[i], &rb[i], &m[i]);
  }

  for(int i=0; i<num; i++){
    supera[i]=0;
    saldoa[i]=xa[i];
    saldob[i]=xb[i];
    for(int j=0; j<m[i]; j++){
      saldoa[i]*=1+(ra[i]/100);
      saldoa[i]+=da[i];
      saldob[i]*=1+(rb[i]/100);
      if(saldob[i]>saldoa[i]){
        supera[i]++;
      }
    }
  }

  for(int i=0; i<num; i++){
    if(ra[i]>rb[i]){
      printf("Rendimento de B invalido\n");
    }
    else if(m[i]-supera[i]>=supera[i]){
      printf("%.2lf %.2lf B nao supera A\n", saldoa[i], saldob[i]);
    }
    else
      printf("%.2lf %.2lf %d\n", saldoa[i], saldob[i], supera[i]);

}

  free(m);
  free(supera);
  free(xa);
  free(xb);
  free(da);
  free(ra);
  free(rb);
  free(saldoa);
  free(saldob);

  printf("\n\n--------------------------------------------------------------------------------------------------------------");

}

void ex3()
{
  int num, linhas, colunas, **matriz, maior, menor;
  float media;

  printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
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
    printf("%d %d %f\n", maior, menor, media);
    for(int i=0; i<linhas; i++){
      free(matriz[i]);
    }
    free(matriz);
  }
  printf("\n--------------------------------------------------------------------------------------------------------------");
}

void ex4()
{
  int quest, alunos, *gabarito, **provas, *notas;

  printf("\n--------------------------------------------------------------------------------------------------------------\n\n");
  scanf("%d %d", &quest, &alunos);

  notas=malloc(alunos *sizeof(int));
  gabarito=malloc(quest * sizeof(int));
  for(int i=0; i< quest; i++){
    scanf("%d", &gabarito[i]);
  }

  provas=malloc(alunos *sizeof(int));
  for(int i=0; i< alunos; i++){
    provas[i]=malloc((quest+1) *sizeof(int));
    notas[i]=0;
    for(int j=0; j< quest+1; j++){
      scanf("%d", &provas[i][j]);
      if(provas[i][j]==gabarito[j]){
        notas[i]++;
      }
    }
    printf("%d  %d\n\n", provas[i][quest], notas[i]);
  }
  printf("\n--------------------------------------------------------------------------------------------------------------");
}

int fatorials(int k)
{
    int fatorial=1;
    for(int i=1; i<=k; i++){
      fatorial*=i;
    }
    return (fatorial);
}
