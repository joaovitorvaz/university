#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto* criarPt(float p1, float p2);
void liberarPt(Ponto *ponto);
void acessarPt(Ponto *ponto, float *p1, float *p2);
void atribuirPt(Ponto *ponto, float p1, float p2);

#endif
