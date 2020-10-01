#ifndef AFAZER_H
#define AFAZER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Morador.h"
#include "Tarefa.h"

typedef struct afazer Afazer;

Afazer *CriaAfazer(Morador *morador, Tarefa *tarefa);
void LiberaAfazer(Afazer *afazer);
void setMorador(Afazer *afazer, Morador *morador);
void setTarefa(Afazer *afazer, Tarefa *tarefa);
Morador *getMorador(Afazer *afazer);
Tarefa *getTarefa(Afazer *afazer);
void imprimeAfazer(Afazer* afazer);

#endif
