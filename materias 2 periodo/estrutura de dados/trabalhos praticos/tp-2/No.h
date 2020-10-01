#ifndef NO_H
#define NO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct no No;

No* CriaNo(int n);
void loop(int n);
No* LiberaNo(No* no);
void setTemp(No *no, float temp);
void setIdentificadorNo(No *no, char *identificador);
void setDescricaoNo(No *no, char *descricao);
void setProxNo(No* no, No* prox);
float getTempNo(No *no);
char* getIdentificadorNo(No *no);
char* getDescricaoNo(No *no);
No* getProxNo(No* no);

#endif
