#include <stdio.h>
#include <stdlib.h>
#include "Quadrado.h"

struct quadrado{
	float lad;
};

Quadrado* criarQuad(float lado){
	Quadrado* quad= malloc(sizeof(Quadrado));
	quad->lad=lado;
	return quad;
}

void lerQuad(Quadrado* quad){
	printf("Quadrado: \n");
	printf("Lado: %f\n", getLadoQuad(quad));
}

Quadrado* atualizarQuad(Quadrado* quad, float lado){
	setLadoQuad(quad, lado);
	return quad;
}

float areaQuad(Quadrado *quad){
	float aux;
	aux=(quad->lad)*(quad->lad);
	return aux;
}

float getLadoQuad(Quadrado* quad){
	return quad->lad;
}

void setLadoQuad(Quadrado* quad, float lado){
	quad->lad= lado;
}
