#ifndef MORADOR_H
#define MORADOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct morador Morador;

Morador *criarMorador(char *nome, char *dtIngresso, int condicao);
void apagarMorador(Morador *morador);
void setNomeMorador(Morador *morador, char *nome);
void setDtIngressoMorador(Morador *morador, char *dtIngresso);
void setCondMorador(Morador *morador, int condicao);
char *getNomeMorador(Morador *morador);
char *getDtIngressoMorador(Morador *morador);
int getCondMorador(Morador *morador);
void imprimeMorador(Morador* morador);

#endif
