#ifndef ASI_H
#define ASI_H

#include "tp1.h"

//Macros
#define ITENSPAGINA 8
#define MAXTABELA 125000 //Permite a pesquisa no ASI com um arquivo que possua ate 1 milhao de registros

//Prototipos de Funcoes
int* criarIndiceDePaginas(FILE* arq, int ordenacao, Analise* a);
int pesquisa1(int tab[], int tam, Registro* item, FILE* arq, int ordenacao, Analise* a);

#endif