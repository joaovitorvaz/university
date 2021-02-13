//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 50

typedef struct{
  char nome[T];
  double nota;
  double freq;
} Aluno;

void gravar(Aluno *v, int n);

int main()
{
  int n;
  printf ("Insira o numero de alunos: ");
  scanf("%d", &n);
  Aluno *alunos = malloc(n * sizeof(Aluno));

  printf("\n");

  for(int i=0; i<n; i++){
    printf("Primeiro nome do aluno %d: ", i+1);
    scanf("%s", alunos[i].nome);
    printf("Nota do aluno %d: ", i+1);
    scanf("%lf", &alunos[i].nota);
    printf("Frequencia do aluno %d: ", i+1);
    scanf("%lf", &alunos[i].freq);
    printf("\n");
  }

  gravar(alunos, n);
  free(alunos);
  return 0;
}

void gravar(Aluno *v, int n){
  FILE *datax = fopen("Alunos.txt", "w");
  fprintf(datax, "%d\n", n);
  for(int i=0; i<n; i++){
    fprintf(datax, "%s ", v[i].nome);
    fprintf(datax, "%.2lf ", v[i].nota);
    fprintf(datax, "%.2lf\n", v[i].freq);
  }
  fclose(datax);
}
