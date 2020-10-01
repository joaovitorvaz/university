#ifndef HASH_H
#define HASH_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Aluno.h"

#define N 10

typedef struct hash Hash;

Hash* criaHash();
void liberaHash(Hash* hash);
int fhash(Hash* hash, int mat);
int searchash(Hash* hash, int mat);
int insereHash(Hash* hash, Aluno* aluno);
void redimensionar(Hash* hash);
int removeHash(Hash* hash, int mat);
Aluno* getAluno(Hash* hash, int h);

#endif
