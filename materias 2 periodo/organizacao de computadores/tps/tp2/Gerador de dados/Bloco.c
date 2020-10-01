#include"Bloco.h"

//Funcções boleanas são utilizadas de forma a verificar caso esteja vazio ou tenha sofrido uma atualização

struct block{
    int* words;
    bool empty;
    bool update;
    int add;
    int hit;
};

Block* createBlock(){
    Block* bloco = malloc(sizeof(Block));
    bloco->words = malloc(4*sizeof(int));
    for(int i = 0;i<4;i++){
        bloco->words[i] = 0;
    }
    bloco->add = 0;
    bloco->hit = 0;
    bloco->update = false;
    bloco->empty = true;
    return bloco;
}

Block* block_creat_random(int add){
    int num;
    Block* block=malloc(sizeof(Block));
    block->words=malloc(4*sizeof(int));
    for(int i=0; i<4; i++){
        num=rand()%100;
        block->words[i]=num;
    }
    block->add=add;
    block->hit=0;
    block->update=false;
    block->empty=false;
    return block;
}

void deleteBlock(Block* bloco){
    free(bloco->words);
    free(bloco);
}

int getWordBlock(Block* bloco, int add){
    return bloco->words[add];
}

int getAddBlock(Block* bloco){
    return bloco->add;
}

int getHitBlock(Block* bloco){
    return bloco->hit;
}

bool getUpdateBlock(Block* bloco){
    return bloco->update;
}

bool getEmptyBlock(Block* bloco){
    return bloco->empty;
}

void setWordBlock(Block* bloco,int add, int valor){
    bloco->words[add] = valor;
}

void setAddBlock(Block* bloco,int add){
    bloco->add = add;
}

void setHitBlock(Block* bloco, int hit){
    bloco->hit += hit;
}

void setHitZero(Block* bloco, int hit){
    bloco->hit = hit;
}

void setUpdateBlock(Block* bloco,bool update){
    bloco->update = update;
}

void setEmptyBlock(Block* bloco, bool empty){
    bloco->empty = empty;
}
