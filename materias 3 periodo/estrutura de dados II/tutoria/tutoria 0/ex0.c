#include <stdio.h>
#include <stdlib.h>

#define STRINGSIZE 60

typedef struct{
  char phrase[STRINGSIZE];
  char enter;
} Info;

int main(int argc, char* argv[]){
  Info info;
  FILE *commonTxt, *commonBin, *inverseTxt;

  if(argc < 3){
    printf("Erro no formato de execucao\n");
    exit(1);
  }

  //Teste.
  printf("%s %s %s \n", argv[1], argv[2], argv[3]);

  //Abrindo arquivo txt comum.
  if((commonTxt = fopen(argv[1], "r")) == NULL){
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  //Criando arquivo bin comum.
  if((commonBin = fopen(argv[2], "w+b")) == NULL){
    printf("Erro na criacao do arquivo.\n");
    exit(1);
  }

  //Criando arquivo txt inverso.
  if((inverseTxt = fopen(argv[3], "w")) == NULL){
    printf("Erro na criacao do arquivo.\n");
    exit(1);
  }

  //Percorrendo txt e gerando bin.
  while(!feof(commonTxt)){
    fscanf(commonTxt, "%[A-Z a-z] %[\n]", info.phrase, &info.enter);

    //Teste. (Looping here???)
    printf("%s\n", info.phrase);

    fwrite(&info, sizeof(Info), 1, commonBin);
  }

  rewind(commonBin);

  //Percorrendo bin e criando txt inverso.
  /// ...

  fclose(commonTxt);
  fclose(commonBin);
  fclose(inverseTxt);

  return 0;
}