#include <stdlib.h>
#include "Ponto.h"

struct ponto{
    float p1, p2;
};

Ponto* criarPt(float p1, float p2){
    Ponto* ponto=malloc(sizeof(Ponto));
    ponto->p1 = p1;
    ponto->p2 = p2;
    return ponto;
}
void liberarPt(Ponto *ponto){
    free(ponto);
}
void acessarPt(Ponto *ponto, float *p1, float *p2){
    *p1  = ponto->p1;
    *p2  = ponto->p2;
}
void atribuirPt(Ponto *ponto, float p1, float p2){
    ponto->p1 = p1;
    ponto->p2 = p2;
}
