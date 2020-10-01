#ifndef CPU_H
#define CPU_H

#include<stdio.h>
#include<stdlib.h>
#include"Instructions.h"
#include"Cpu.h"
#include"Cache.h"
#include"Bloco.h"
#include"Machine.h"

#define I 50

int CPU(FILE* hardDisk,Cache* RAM_memory, Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, int* ARITMETIC_memory, int** instructions, int* HDHit);
int MMU(FILE* hardDisk,Cache* RAM_memory,Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, int addBlock1, int word, int addBlock2, int* HDHit);
int ALU(int* ARITMETIC_memory, int pick);

#endif
