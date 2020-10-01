#ifndef LOSANGO_H
#define LOSANGO_H

typedef struct losango Losango;

Losango* criarLos(float dma, float dme);
void lerLos(Losango* los);
Losango* atualizarLos(Losango* los, float dma, float dme);
float areaLos(Losango* los);
float getDiagonalMaiorLos(Losango* los);
float getDiagonalMenorLos(Losango* los);
void setDiagonalMaiorLos(Losango* los, float dma);
void setDiagonalMenorLos(Losango* los, float dme);

#endif
