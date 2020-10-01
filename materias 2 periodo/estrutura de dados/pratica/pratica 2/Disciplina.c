#include "Disciplina.h"

struct disciplina{
    char nome[100];
    char codigo[72];
    double cargah;
    char curso[100];
    int sala;
};

Disciplina *criardisciplina(char *nome, char *codigo, double cargah, char *curso, int sala){
    Disciplina *disc=malloc(sizeof(Disciplina));
    strcpy(disc->nome, nome);
    strcpy(disc->codigo, codigo);
    disc->cargah=cargah;
    strcpy(disc->curso, curso);
    disc->sala=sala;
    return disc;
}

void apagarDisciplina(Disciplina *disc){
    free(disc);
}

void setNomeDisc(Disciplina *disc, char *nome){
    strcpy(disc->nome, nome);
}

void setCodigoDisc(Disciplina *disc, char *codigo){
    strcpy(disc->codigo, codigo);
}

void setCargaDisc(Disciplina *disc, double cargah){
    disc->cargah=cargah;
}

void setCursoDisc(Disciplina *disc, char *curso){
    strcpy(disc->curso, curso);
}

void setSalaDisc(Disciplina *disc, int sala){
    disc->sala=sala;
}

char* getNomeDisc(Disciplina *disc){
    return disc->nome;
}

char* getCodigoDisc(Disciplina *disc){
    return disc->codigo;
}

double getCargahDisc(Disciplina *disc){
    return disc->cargah;
}

char* getCursoDisc(Disciplina *disc){
    return disc->curso;
}

int getSalaDisc(Disciplina *disc){
    return disc->sala;
}

Disciplina* getDisciplina(Disciplina **disciplina, int posicao){
    return disciplina[posicao];
}

void imprimeDisc(Disciplina * disc){
  printf("%s\n%s\n%lf\n%s\n%d\n\n", getNomeDisc(disc), getCodigoDisc(disc), getCargahDisc(disc), getCursoDisc(disc), getSalaDisc(disc));
}
