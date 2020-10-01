//Marcus Vinícius Souza Fernandes  -  19.1.4046  -  BCC201-61P
#include <stdio.h>
#include <string.h>

#define T 100
#define M 10
#define N 100

typedef struct{
  char nome[T];
  int matri;
  float nota[M];
  float media;
} Aluno;

Aluno encontraAluno(Aluno alunos[], int n, int matricula);

int main()
{
  int n, m;
  int matricula;
  float mediag=0;
  float mediaaf=0;

  do {
  printf("Insira o numero de alunos: ");
  scanf("%d", &n);
  } while(n>100);

  do {
  printf("Insira o numero de notas: ");
  scanf("%d", &m);
} while(m>10);

  Aluno alunos[n];
  Aluno encontrado;

  printf("\n\n");

  for (int i=0; i<n; i++){
    getchar();
    printf("Aluno %d:", i+1);
    printf("\nInsira o nome completo: ");
    fgets(alunos[i].nome, T, stdin);
    printf("Insira matricula: ");
    scanf("%d", &alunos[i].matri);
      for (int j=0; j<m; j++){
        printf("Insira a nota p%d: ", j+1);
        scanf("%f", &alunos[i].nota[j]);
        alunos[i].media+=alunos[i].nota[j];
      }
    printf("\n");
    mediag+=alunos[i].media;
    alunos[i].media/=m;
  }

  mediag=mediag/(n*m);

  printf("Media total dos alunos: %f", mediag);
  printf("\n\nInsira um numero de matricula: ");
  scanf("%d", &matricula);

  encontrado=encontraAluno(alunos, n, matricula);

  printf("\n\nNome: %s", encontrado.nome);
  printf("Media das notas: %f", encontrado.media);

  printf("\n\n");

  return 0;
}

Aluno encontraAluno(Aluno alunos[], int n, int matricula) {
  for(int i=0; i<n; i++){
    if (alunos[i].matri==matricula){
      return alunos[i];
    }
  }
  Aluno SemCadastro = {"Nao encontrado\n", 0, {0,0,0,0,0,0,0,0,0,0}, 0};
  return SemCadastro;
}
