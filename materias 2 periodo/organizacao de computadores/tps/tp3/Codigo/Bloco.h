#ifndef BLOCO_H
#define BLOCO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct block Block;

Block* createBlock();
Block* block_creat_random(int add);
void deleteBlock(Block* bloco);
int getWordBlock(Block* bloco, int add);
int getAddBlock(Block* bloco);
int getHitBlock(Block* bloco);
bool getUpdateBlock(Block* bloco);
bool getEmptyBlock(Block* bloco);
void setWordBlock(Block* bloco,int add, int valor);
void setAddBlock(Block* bloco,int add);
void setHitBlock(Block* bloco, int hit);
void setHitZero(Block* bloco, int hit);
void setUpdateBlock(Block* bloco,bool update);
void setEmptyBlock(Block* bloco, bool empty);
//Funções referentes ao tp3
void block_recebe_bloco(Block* block1, Block* block2);
Block* block_from_HD_bin(FILE* read, int pos);
void block_set_in_HD(FILE* hardDisk, Block* block, int addBlock1);
#endif
