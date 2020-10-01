#include <stdio.h>
#include <stdlib.h>

#include "Livro.h"

#define T 100

void mostrarlivro(Livro **liv, char *titulo, int numlivro);

int main()
{
  char titulo[T], autor[T], genero[T], busca[T], rename[T];
  int ano, numlivro;

  scanf("%d", &numlivro);

  Livro **liv=malloc(numlivro *sizeof(Livro*));

  for(int i=0; i<numlivro; i++){
    scanf("%s %s %s %d", titulo, autor, genero, &ano);
    liv[i]=criarlivro(titulo, autor, genero, ano);
  }

  scanf("%s", rename);
  setTitulo(liv[1], rename);

  scanf("%s", busca);

  mostrarlivro(liv, busca, numlivro);

  for(int i=0; i<numlivro; i++){
    ApagarLivro(liv[i]);
  }

  return 0;
}

void mostrarlivro(Livro **liv, char *titulo, int numlivro){
  Livro *aux=buscarlivro(liv, titulo, numlivro);
  if(aux!=NULL){
    printf("%s \n%s \n%s \n%d\n\n", getTitulo(aux), getAutor(aux), getGenero(aux), getAno(aux));
  }
  else
    printf("Livro não encontrado!!!\n");
}
