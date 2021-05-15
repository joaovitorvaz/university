#include <stdio.h>

int main (){
  char matricula[5];
  char nome[31];
  float nota1, nota2, nota3, media;  
  int faltas;
  char conceito;
  char enter;

  FILE *arqAlunos;
  FILE *arqConceito;

  if((arqAlunos = fopen("alunos.txt", "r")) == NULL){
    printf("Erro na abertura do arquivo.");
    return 0;
  }

  if((arqConceito = fopen("conceitos.txt", "w")) == NULL){
    printf("Erro na criacao do arquivo.");
    return 0;
  }

  while (!feof(arqAlunos)){
    fscanf(arqAlunos, "%[0-9] %[A-Z a-z] %f %f %f %d %[\n]", matricula, nome, &nota1, &nota2, &nota3, &faltas, &enter);
    media=(nota1 + nota2 + nota3) / 3;

    if(faltas > 18){
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

    printf("%s %s %c \n", matricula, nome, conceito);

    fprintf(arqConceito, "%s %s %c \n", matricula, nome, conceito);
  }

  fclose(arqAlunos);
  fclose(arqConceito);

  return 0;
}