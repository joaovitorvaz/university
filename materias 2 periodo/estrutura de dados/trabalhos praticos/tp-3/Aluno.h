#ifndef ALUNO_H
#define ALUNO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int cpf, int matricula);
void liberaAluno(Aluno* aluno);
void imprimeAluno(Aluno* aluno);
char* getNome(Aluno* aluno);
int getCPF(Aluno* aluno);
int getMatricula(Aluno* aluno);
bool getExistente(Aluno* aluno);
void setNome(Aluno* aluno, char* nome);
void setCPF(Aluno* aluno, int cpf);
void setMatricula(Aluno* aluno, int matricula);
void setExiste(Aluno* aluno);

#endif
