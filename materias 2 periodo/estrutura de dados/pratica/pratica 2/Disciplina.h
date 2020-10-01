#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct disciplina Disciplina;

Disciplina *criardisciplina(char *nome, char *codigo, double cargah, char *curso, int sala);
void apagarDisciplina(Disciplina *disc);
void setNomeDisc(Disciplina *disc, char *nome);
void setCodigoDisc(Disciplina *disc, char *codigo);
void setCargaDisc(Disciplina *disc, double cargah);
void setCursoDisc(Disciplina *disc, char *curso);
void setSalaDisc(Disciplina *disc, int sala);
char* getNomeDisc(Disciplina *disc);
char* getCodigoDisc(Disciplina *disc);
double getCargahDisc(Disciplina *disc);
char* getCursoDisc(Disciplina *disc);
int getSalaDisc(Disciplina *disc);
Disciplina* getDisciplina(Disciplina **disciplina, int posicao);
void imprimeDisc(Disciplina * disc);

#endif
