#include <stdio.h>

typedef struct{
  char matricula[5];
  char nome[31];
  float nota1, nota2, nota3;  
  int faltas;
} Aluno;

int main (){
  Aluno aluno;
  float media;
  char conceito;

  FILE *entrada;
  FILE *saida;

  if((entrada = fopen("dados.bin", "rb")) == NULL){
    printf("Erro na abertura do arquivo.\n");
    return 0;
  }

  if((saida = fopen("conceitos.txt", "w")) == NULL){
    printf("Erro na criacao do arquivo.\n");
    return 0;
  }

  while (fread(&aluno, sizeof(aluno), 1, entrada) == 1){
    media=(aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
    
    if(aluno.faltas > 18){
      conceito='F';
    } else if(media <= 6.0){
      conceito='R';
    } else if(media <= 7.5){
      conceito='C';
    } else if(media <= 9.0){
      conceito='B';
    } else if(media <= 10.0){
      conceito='A';
    }

    fprintf(saida, "%s %s %c \n", aluno.matricula, aluno.nome, conceito);
  }

  fclose(entrada);
  fclose(saida);

  return 0;
}