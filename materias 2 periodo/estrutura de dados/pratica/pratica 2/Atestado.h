#ifndef ATESTADO_H
#define ATESTADO_H

#include <stdlib.h>
#include <string.h>

typedef struct atestado Atestado;

Atestado *criarAtestado(Aluno *aluno, Disciplina **disc, int hmax);
void apagaAtestado(Atestado *atestado, int hmax);
void setAlunoAtestado(Atestado *atestado, Aluno *aluno);
void setDisciplinaAtestado(Atestado *atestado, Disciplina *disc, int opcao);
void setCargaAtestado(Atestado *atestado , int hmax);
void getAlunoAtestado(Atestado *atestado, Aluno *aluno);
void getDisciplinaAtestado(Atestado *atestado, Disciplina *disc, int opcao);
void getCargaAtestado(Atestado *atestado, int *hmax);
void imprimeAtestado(Atestado *atestado);
#endif
