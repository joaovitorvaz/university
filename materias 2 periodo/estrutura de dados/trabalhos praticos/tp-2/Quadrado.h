#ifndef QUADRADO_H
#define QUADRADO_H

typedef struct quadrado Quadrado;

Quadrado* criarQuad(float lado);
void lerQuad(Quadrado* quad);
Quadrado* atualizarQuad(Quadrado* quad, float lado);
float areaQuad(Quadrado *quad);
float getLadoQuad(Quadrado* quad);
void setLadoQuad(Quadrado* quad, float lado);

#endif
