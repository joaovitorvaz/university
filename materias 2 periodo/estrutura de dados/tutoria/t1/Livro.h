#ifndef LIVRO_H
#define LIVRO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct livro Livro;

Livro *criarlivro(char *titulo, char *autor, char *genero, int ano);
void ApagarLivro(Livro *liv);
void setTitulo(Livro *liv, char *titulo);
void setAutor(Livro *liv, char *autor);
void setGenero(Livro *liv, char *genero);
void setAno(Livro *liv, int ano);
char* getTitulo(Livro *liv);
char* getAutor(Livro *liv);
char* getGenero(Livro *liv);
int getAno(Livro *liv);

Livro *buscarlivro(Livro **liv, char *titulo, int numlivro);

#endif
