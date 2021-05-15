#include <stdio.h>

typedef struct{
  char matricula[5];
  char nome[31];
  float nota1, nota2, nota3;  
  int faltas;
} Aluno;

int main (){
  Aluno aluno;
  char enter;

  FILE *entrada;
  FILE *saida;

  if((entrada = fopen("alunos.txt", "r")) == NULL){
    printf("Erro na abertura do arquivo.\n");
    return 0;
  }

  if((saida = fopen("dados.bin", "w+b")) == NULL){
    printf("Erro na criacao do arquivo.\n");
    return 0;
  }

  while (!feof(entrada)){
    fscanf(entrada, "%[0-9] %[A-Z a-z] %f %f %f %d %[\n]", aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.faltas, &enter);
    fwrite(&aluno, sizeof(aluno), 1, saida);
  }

  fclose(entrada);
  fclose(saida);

  return 0;
}