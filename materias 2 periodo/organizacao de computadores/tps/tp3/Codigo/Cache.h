#ifndef CACHE_H
#define CACHE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include"Bloco.h"

typedef struct cache Cache;

Cache* createCache(int num);
Cache* cache_creat_ram(int size);
void clearCache(Cache* cache);
void deleteCache(Cache* cache);
void cache_switch(Cache* cache1, int add1, Cache* cache2, int add2);
void cache_up(Cache* cache1, int pos, Block* bloco);
Block* cache_return_block(Cache* cache, int addBlock);
int getHitCache(Cache* cache);
int getMissCache(Cache* cache);
int getSizeCache(Cache* cache);
Block* getBlockCache(Cache* cache, int pos);
void setHitCache(Cache* cache,int hit);
void setMissCache(Cache* cache,int miss);
void setSizeCache(Cache* cache, int size);
void setBlockCache(Cache* cache, Block** bloco);
void showCache_all(Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, Cache* RAM_memory);
void cache_show_statistic(Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, Cache* RAM_memory, double* time, int interrupution, int inst, int HDHit);

#endif
