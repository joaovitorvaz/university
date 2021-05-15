#include <stdio.h>
#include <stdlib.h>

#define ITENSPAGINA 8
#define MAXTABELA 125

typedef struct{  
  int chave;
  long int preco;
  char titulo[20];
} Tipoitem;

typedef struct{
  int posicao;
  int chave;
} Tipoindice;

int txtToBin(FILE *dadosBin, Tipoitem x){
  FILE *entrada;
  char enter;

  if((entrada = fopen("arqSequencial.txt", "r")) == NULL){
    printf("Erro na abertura do arquivo.\n");
    return 1;
  }  

  while(!feof(entrada)){
    fscanf(entrada, "%d %ld %[A-Z a-z] %[\n]", &x.chave, &x.preco, x.titulo, &enter);
    fwrite(&x, sizeof(Tipoitem), 1, dadosBin);
  }

  fclose(entrada);

  return 0;
}

int pesquisa(Tipoindice tab[], int tam, Tipoitem *item, FILE *arq){
  Tipoitem pagina[ITENSPAGINA];  
  int quantitens;
  long desloc;
  int i = 0;

  while (i < tam && tab[i].chave <= item->chave) i++;

  if(i == 0){
    return 0;
  }    
  else{
    if (i < tam){
      quantitens = ITENSPAGINA;
    }      
    else{
      fseek(arq, 0, SEEK_END);
      quantitens = (ftell(arq) / sizeof(Tipoitem)) % ITENSPAGINA;
      if(quantitens == 0){
        quantitens = ITENSPAGINA;
      }
    }
  }

  desloc = (tab[i - 1].posicao - 1) * quantitens * sizeof(Tipoitem);
  fseek(arq, desloc, SEEK_SET);
  fread(&pagina, sizeof(Tipoitem), quantitens, arq);

  for (i = 0; i < quantitens; i++){
    if (pagina[i].chave == item->chave){
      *item = pagina[i];
      return 1;
    }
  }

  return 0;
}

int main(){
  Tipoindice tabela[MAXTABELA];
  Tipoitem x;

  FILE *dadosBin;

  int cont = 0;
  int pos = 0;  

  if((dadosBin = fopen("dadosBin.bin", "w+b")) == NULL){
    printf("Erro na criacao do arquivo.\n");
    return 0;
  }

  //Transformando o arquivo texto em binário.
  if(txtToBin(dadosBin, x) == 1){
    return 0;
  }

  //Retornando ao inicio do arquivo.
  rewind(dadosBin);

  //Criando tabela.
  while (fread(&x, sizeof(x), 1, dadosBin) == 1){
    cont++;
    if (cont % ITENSPAGINA == 1){
      tabela[pos].chave = x.chave;
      tabela[pos].posicao = pos + 1;
      pos++;
    }
  }

  fflush(stdout);
  printf("Código do livro desejado: ");
  scanf("%d", &x.chave);

  //Chamar pesquisa e tratar retornos.
  if(pesquisa(tabela, pos, &x, dadosBin)){
    printf("Livro de %s (Codigo %d) foi localizado.\n", x.titulo, x.chave);
  }    
  else{
    printf("Livro de (Codigo %d) nao foi localizado.\n", x.chave);
  }

  fclose(dadosBin);

  return 0;
}