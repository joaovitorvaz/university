#ifndef TRAPEZIO_H
#define TRAPEZIO_H

typedef struct trapezio Trapezio;

Trapezio* criarTrap(float baseMa, float baseMe, float height);
void lerTrap(Trapezio* trapezio);
Trapezio* atualizarTrap(Trapezio* trapezio, float baseMa, float baseMe, float height);
float areaTrap(Trapezio* trapezio);
void setBaseMaiorTrap(Trapezio* trapezio, float baseMa);
void setBaseMenorTrap(Trapezio* trapezio, float baseMe);
void setAlturaTrap(Trapezio* trapezio, float height);
float getBaseMaiorTrap(Trapezio* trapezio);
float getBaseMenorTrap(Trapezio* trapezio);
float getAlturaTrap(Trapezio* trapezio);

#endif
