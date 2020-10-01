//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC201-61P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 50
#define TM 100

typedef struct{
  char nome[T];
  double nota;
  double freq;
} Aluno;

int main()
{
  char arquivo[TM];
  int n;
  int cont=0;
  double mnota=0.00;
  double mfreq=0.00;
  double apr;

  printf("Digite o nome do arquivo: ");
  scanf("%s", arquivo);
  FILE *file = fopen(arquivo, "r");
  fscanf(file, "%d", &n);
  Aluno *v = malloc(n * sizeof(Aluno));

  for(int i=0; i<n; i++){
    fscanf(file, "%s %lf %lf", v[i].nome, &v[i].nota, &v[i].freq);
    mnota+=v[i].nota;
    mfreq+=v[i].freq;
    if ((v[i].nota>60.00) && (v[i].freq>75.00)){
      cont++;
    }
  }

  printf("\n");

  mnota=mnota/n;
  mfreq=mfreq/n;
  apr=(cont/n)*100;

  printf("Nota media: %.1lf\n", mnota);
  printf("Frequencia media: %.0lf%\n", mfreq);
  printf("Percentual de aprovacao: %.2lf%\n", apr);
  printf("\n");
  printf("Nomes dos alunos com nota acima da nota media:\n");

  for (int i=0; i<n; i++){
    if (v[i].nota > mnota)
      printf ("%s\n", v[i].nome);
  }
  return 0;
}
