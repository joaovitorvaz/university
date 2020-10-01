#include <stdio.h>
#include <stdlib.h>
#include "Losango.h"

struct losango{
	float dma;
	float dme;
};

Losango* criarLos(float dma, float dme){
	Losango *los=malloc(sizeof(Losango));
	los->dma=dma;
	los->dme=dme;
	return los;
}

void lerLos(Losango* los){
	printf("Losango: \n");
	printf("Diagonal maior: %f\n", getDiagonalMaiorLos(los));
	printf("Diagonal menor: %f\n", getDiagonalMenorLos(los));
}

Losango* atualizarLos(Losango* los, float dma, float dme){
	setDiagonalMaiorLos(los, dma);
	setDiagonalMenorLos(los, dme);
	return los;
}

float areaLos(Losango* los){
	float aux;
	aux=(los->dma*los->dme)/2;
	return aux;
}

float getDiagonalMaiorLos(Losango* los){
	return los->dma;
}

float getDiagonalMenorLos(Losango* los){
	return los->dme;
}

void setDiagonalMaiorLos(Losango* los, float dma){
	los->dma=dma;
}

void setDiagonalMenorLos(Losango* los, float dme){
	los->dme=dme;
}
