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

//Funções relacionadas ao TP3
void block_recebe_bloco(Block* block1, Block* block2){
  deleteBlock(block1);
  block1 = createBlock();
  block1 = block2;
}

Block* block_from_HD_bin(FILE* read, int pos){
  int word0,word1,word2,word3;
  if(read != NULL){
    fseek(read,sizeof(int)*4*pos, 0);
    fread(&word0,sizeof(int), 1, read);
    fread(&word1,sizeof(int), 1, read);
    fread(&word2,sizeof(int), 1, read);
    fread(&word3,sizeof(int), 1, read);
    rewind(read);
    Block* new = block_creat_random(pos);
    setWordBlock(new, 0, word0);
    setWordBlock(new, 1, word1);
    setWordBlock(new, 2, word2);
    setWordBlock(new, 3, word3);
    return new;
  }
  else{
      printf("Erro de leitura");
        return NULL;
  }
}
void block_set_in_HD(FILE* hardDisk, Block* block, int addBlock1){
    if(hardDisk != NULL){
        int word0 = getWordBlock(block, 0);
        int word1 = getWordBlock(block, 1);
        int word2 = getWordBlock(block, 2);
        int word3 = getWordBlock(block, 3);
        fseek(hardDisk, sizeof(int)*4*getAddBlock(block) , 0);
        fwrite (&word0, sizeof (int), 1, hardDisk);
        fwrite (&word1, sizeof (int), 1, hardDisk);
        fwrite (&word2, sizeof (int), 1, hardDisk);
        fwrite (&word3, sizeof (int), 1, hardDisk);
        rewind(hardDisk);
        fseek(hardDisk, sizeof(int)*4*addBlock1 , 0);
        fread (&word0, sizeof (int), 1, hardDisk);
        fread (&word1, sizeof (int), 1, hardDisk);
        fread (&word2, sizeof (int), 1, hardDisk);
        fread (&word3, sizeof (int), 1, hardDisk);
        rewind(hardDisk);
        setWordBlock(block, 0, word0);
        setWordBlock(block, 1, word1);
        setWordBlock(block, 2, word2);
        setWordBlock(block, 3, word3);
        setAddBlock(block, addBlock1);
        block->hit = 0;
    }
    else{
        printf("Erro na leitura\n");
    }
}
