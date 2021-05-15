#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototipos de Funcoes
void criarArquivos(FILE** ArqLEs, FILE** ArqLi, FILE** ArqEi, FILE** ArqTexto, int situacao, int quantidade);
void converterBin(FILE* arqOriginal, FILE* arqBin, int quantidade);
void converterTexto(FILE* arqOriginal, FILE* arqTexto, int quantidade);

#endif