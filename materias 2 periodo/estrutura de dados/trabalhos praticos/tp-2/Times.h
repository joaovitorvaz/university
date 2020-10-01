#ifndef TIMES_H
#define TIMES_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct time Time;

Time* CriaTimes(int clubes);
void Jogos(Time *time, int clubes, int njogos);
void AtualizarCampos(Time* time, int clubes);
void PrintarTime(Time* time, int clubes);
void MergeOrdena(Time* time, int esq, int dir);
void MergeIntercala(Time* time, int esq, int meio, int dir);
Time* LiberaTimes(Time* time);
void setNomeTime(Time* time, char *nome, int pos);
void setPontosTime(Time* time, int pontos, int pos);
void setVitoriasTime(Time* time, float vitorias, int pos);
void setJogosTime(Time* time, float jogos, int pos);
void setGolsmTime(Time* time, int golsm, int pos);
void setGolssTime(Time* time, int golss, int pos);
void setSgTime(Time* time, int pos);
void setAprovTime(Time* time, int pos);
void setPtotalTime(Time* time, int pos);
char* getNomeTime(Time *time, int pos);
int getPontosTime(Time* time, int pos);
float getVitoriasTime(Time* time, int pos);
float getJogosTime(Time* time, int pos);
int getGolsmTime(Time* time, int pos);
int getGolssTime(Time* time, int pos);
int getSgTime(Time* time, int pos);
float getAprovTime(Time* time, int pos);
int getPtotalTime(Time* time, int pos);

#endif
