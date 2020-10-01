#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define T 100

int* criaAritmetica(int size);
void liberaAritmetica(int* ARITMETIC_memory);
int** criaPrograma(int size);
void delete_programa(int** program, int programa_size);
int** programaSoma(int size);
int** programaSubtracao(int programa_size);
int** starta_instrucoes(int* inst, int L1_size);
int** ler_instrucoes(int* inst, bool* flag);
void create_hardDisk_bin(FILE* create, int blocks);

#endif
