//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 50
#define TA 100

typedef struct{
  char nomecomida[T];
  double peso;
  double cal;
} Dieta;

Dieta *lerarquivo(int *n);

int main()
{
  int n, cont;
  double maior=0.00;
  Dieta *ler= lerarquivo(&n);
  double *caloriaporgrama=malloc(n * sizeof(double));

  for(int i=0; i<n; i++){
    caloriaporgrama[i] = (ler[i].cal / ler[i].peso);
    if (caloriaporgrama[i] > maior){
      maior=caloriaporgrama[i];
      cont=i;
    }
  }
  printf("Alimento \t\tcal/grama\n");
  printf("-----------------------------------\n");

  for (int i=0; i<n; i++){
    printf ("%s \t%.2lf", ler[i].nomecomida, caloriaporgrama[i]);
    if (cont==i){
      printf ("*");
    }
    printf ("\n");
  }
  printf ("\n");
  return 0;
}

Dieta *lerarquivo(int *n){
  char arquivo[TA];
  printf("Digite o nome do arquivo: ");
  scanf("%s", arquivo);
  printf("\n");
  FILE *file = fopen(arquivo, "r");
  fscanf(file, "%d", n);
  Dieta *v = malloc(*n * sizeof(Dieta));

  for(int i=0; i<*n; i++){
    fscanf (file, "%s %lf %lf", v[i].nomecomida, &v[i].peso, &v[i].cal);
  }

  fclose(file);
  return v;
}
