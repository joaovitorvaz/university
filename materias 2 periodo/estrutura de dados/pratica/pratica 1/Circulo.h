#include "Ponto.h"
#ifndef ITEM_H
#define ITEM_H

typedef struct circulo Circulo;

Circulo* criarCir(Ponto *ponto, float raio);
void liberarCir(Circulo *circulo);
float calcularCir(Circulo *circulo);

#endif
