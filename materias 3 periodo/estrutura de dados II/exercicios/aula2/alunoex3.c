#include <stdio.h>
#include <string.h>

typedef struct{
  char matricula[5];
  char nome[31];
  float nota1, nota2, nota3;  
  int faltas;
} Aluno;

int main (){
  Aluno aluno;
  char delete[5];

  FILE *entrada;
  FILE *saida;

  if((entrada = fopen("dados.bin", "rb")) == NULL){
    printf("Erro na abertura do arquivo.\n");
    return 0;
  }

  if((saida = fopen("newdados.bin", "w+b")) == NULL){
    printf("Erro na criacao do arquivo.\n");
    return 0;
  }

  printf("Insira o número de matricula do aluno que deseja remover: ");
  scanf("%s", delete);

  while (fread(&aluno, sizeof(aluno), 1, entrada) == 1){
    if(strcmp(aluno.matricula, delete) != 0){
      fwrite(&aluno, sizeof(aluno), 1, saida);
    }
  }

  fclose(entrada);
  remove("dados.bin");
  fclose(saida);
  rename("newdados.bin", "dados.bin");

  return 0;
}