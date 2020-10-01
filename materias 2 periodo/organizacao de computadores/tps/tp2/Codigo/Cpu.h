#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include"Instructions.h"
#include"Cpu.h"
#include"Cache.h"
#include"Bloco.h"
#include"Machine.h"

void CPU(Cache* RAM_memory, Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, int* ARITMETIC_memory, int** instructions);
int MMU(Cache* RAM_memory,Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, int addBlock1, int word, int addBlock2);
int ALU(int* ARITMETIC_memory, int pick, int* one_problem, Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, Cache* RAM_memory);

#endif
