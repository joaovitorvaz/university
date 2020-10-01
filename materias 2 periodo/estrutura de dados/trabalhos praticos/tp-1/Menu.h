#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Morador.h"
#include "Tarefa.h"
#include "Afazer.h"
#include "Republica.h"

#define R 100

void mainMenu();
void menuAdd(int indiceAdd, Morador **auxMorador, Tarefa **auxTarefa, Afazer **auxAfazer, Republica *rep, int* nMoradores, int* nTarefas, int* nAfazeres);
void menuShow(int indiceAdd, Tarefa** auxTarefa, Republica* rep, int* m, int* t, int* a);
void menuEdit(int indiceEdit, Morador **auxMorador, Tarefa **auxTarefa, Afazer **auxAfazer, Republica* rep);
void menuDel(int indiceDel, Morador **auxMorador, Tarefa **auxTarefa, Afazer **auxAfazer);

#endif
