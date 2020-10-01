#include <stdio.h>
#include <stdlib.h>
#include "Trapezio.h"

struct trapezio{
	float baseMa;
	float baseMe;
	float height;
};

Trapezio* criarTrap(float baseMa, float baseMe, float height){
	Trapezio* trapezio=malloc(sizeof(Trapezio));
	trapezio->baseMa=baseMa;
	trapezio->baseMe=baseMe;
	trapezio->height=height;
	return trapezio;
}

void lerTrap(Trapezio* trapezio){
	printf("Trapezio: \n");
	printf("Base maior: %f\n", getBaseMaiorTrap(trapezio));
	printf("Base menor: %f\n", getBaseMenorTrap(trapezio));
	printf("Altura: %f\n", getAlturaTrap(trapezio));
}

Trapezio* atualizarTrap(Trapezio* trapezio, float baseMa, float baseMe, float height){
	setBaseMaiorTrap(trapezio, baseMa);
	setBaseMenorTrap(trapezio, baseMe);
	setAlturaTrap(trapezio, height);
	return trapezio;
}

float areaTrap(Trapezio* trapezio){
	float aux;
	aux=((trapezio->baseMa+trapezio->baseMe)*(trapezio->height))/2;
	return aux;
}

void setBaseMaiorTrap(Trapezio* trapezio, float baseMa){
	trapezio->baseMa=baseMa;
}

void setBaseMenorTrap(Trapezio* trapezio, float baseMe){
	trapezio->baseMe=baseMe;
}

void setAlturaTrap(Trapezio* trapezio, float height){
	trapezio->height=height;
}

float getBaseMaiorTrap(Trapezio* trapezio){
	return trapezio->baseMa;
}

float getBaseMenorTrap(Trapezio* trapezio){
	return trapezio->baseMe;
}

float getAlturaTrap(Trapezio* trapezio){
	return trapezio->height;
}
