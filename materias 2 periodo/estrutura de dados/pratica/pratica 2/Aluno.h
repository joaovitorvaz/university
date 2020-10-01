#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno Aluno;

Aluno *criarAluno(char *nome, double cpf, int nMatricula, char *curso, char *dtIngresso);
void apagarAluno(Aluno *aluno);
void setNomeAluno(Aluno *aluno, char *nome);
void setCpfAluno(Aluno *aluno, double cpf);
void setMatriculaAluno(Aluno *aluno, int nMatricula);
void setCursoAluno(Aluno *aluno, char *curso);
void setDtIngressoAluno(Aluno *aluno, char *dtIngresso);
char* getNomeAluno(Aluno *aluno);
double getCpfAluno(Aluno *aluno);
int getMatriculaAluno(Aluno *aluno);
char* getCursoAluno(Aluno *aluno);
char* getDtIngressoAluno(Aluno *aluno);
void imprimealuno(Aluno * aluno);

#endif
