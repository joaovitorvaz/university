#include "Livro.h"
#define T 100

struct livro{
  char titulo[T];
  char autor[T];
  char genero[T];
  int ano;
};

Livro *criarlivro(char *titulo, char *autor, char *genero, int ano){
  Livro *liv = malloc(sizeof(Livro));

  strcpy(liv->titulo, titulo);
  strcpy(liv->autor, autor);
  strcpy(liv->genero, genero);
  liv->ano=ano;
}

void ApagarLivro(Livro *liv){
    free(liv);
}

void setTitulo(Livro *liv, char *titulo){
    strcpy(liv->titulo, titulo);
}

void setAutor(Livro *liv, char *autor){
    strcpy(liv->autor, autor);
}

void setGenero(Livro *liv, char *genero){
    strcpy(liv->genero, genero);
}

void setAno(Livro *liv, int ano){
    liv->ano=ano;
}

char* getTitulo(Livro *liv){
    return liv->titulo;
}

char* getAutor(Livro *liv){
    return liv->autor;
}

char* getGenero(Livro *liv){
    return liv->genero;
}

int getAno(Livro *liv){
    return liv->ano;
}

Livro *buscarlivro(Livro **liv, char *titulo, int numlivro){
  for(int i=0; i< numlivro; i++){
    if (strcmp(getTitulo(liv[i]), titulo )==0) { 
      return liv[i];
    }
  }
  return NULL;
}
