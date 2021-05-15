#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

  if((entrada = fopen("dados.bin", "r+b")) == NULL){
    printf("Erro na abertura do arquivo.\n");
    return 0;
  }

  printf("Insira o número de matricula do aluno que deseja remover: ");
  scanf("%s", delete);

  while (fread(&aluno, sizeof(aluno), 1, entrada) == 1){
    if(strcmp(aluno.matricula, delete) != 0){
      strcpy(aluno.matricula, "0000");
      fseek(entrada, -sizeof(aluno), SEEK_CUR);
      fwrite(&aluno, sizeof(aluno), 1, entrada);
      break;
    }
  }

  fclose(entrada);

  return 0;
}