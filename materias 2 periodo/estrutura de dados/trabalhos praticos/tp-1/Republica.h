#ifndef REPUBLICA_H
#define REPUBLICA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Morador.h"
#include "Tarefa.h"
#include "Afazer.h"

#define T 5

typedef struct republica Republica;

Republica *criaRep(char* nome);
void delRep(Republica* rep);
void setMoradorR(Republica* rep, Morador *morador, int nMorador);
void setTarefaR(Republica* rep, Tarefa *tarefa, int nTarefa);
void setAfazeresR(Republica* rep, Afazer *afazeres, int nAfazeres);
Morador** getMoradorR(Republica* rep);
Morador* getMoradorEspecR(Republica* rep, int pos);
Tarefa** getTarefasR(Republica* rep);
Tarefa* getTarefasEspecR(Republica* rep, int pos);
Afazer** getAfazeresR(Republica* rep);
Afazer* getAfazeresEspecR(Republica* rep, int pos);
void ImprimeNomeMorador(Republica* rep, int pos);
void ImprimeDescTarefa(Republica* rep, int pos);
void ImprimeAfazerR(Republica* rep, int pos);

#endif
