#include <stdio.h>
#include <string.h>

#define T 50

typedef struct {
  char nome[T];
  int idade;
} Cadastro;

int main()
{
  int n;
  printf("Insira o numero de pessoas: ");
  scanf("%d", &n);

  Cadastro cadastro[n];

  for(int i=0; i<n; i++){
    printf("\nInsira seu nome aluno %d: ", i+1);
    scanf("%s", cadastro[i].nome);
    printf("Insira sua idade aluno %d: ", i+1);
    scanf("%d", &cadastro[i].idade);
  }

  printf("\n\n");

  for(int i=0; i<n; i++){
    printf("\nAluno %d: %s - %d anos de idade.", i+1, cadastro[i].nome, cadastro[i].idade);
  }

  printf("\n\n");

  return 0;
}
