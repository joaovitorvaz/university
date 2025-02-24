#include"Cache.h"

struct cache{
    Block** bloco;
    int size;
    int hit;
    int miss;
};

Cache* createCache(int num){
    int size;
    do{
        scanf("%d", &size);
        if(size<2){
            printf("Tamanho invalido");
        }
    }while(size<2);

    Cache* novo = malloc(sizeof(Cache));

    novo->bloco = malloc(size*sizeof(Block*));
    for(int i = 0;i < size; i++){
        novo->bloco[i]=createBlock();
    }
    novo->size = size;
    novo->hit = 0;
    novo->miss = 0;
    return novo;
}

Cache* cache_creat_ram(int size){
    Cache* novo=malloc(sizeof(Cache));
    novo->bloco=malloc(size*sizeof(Block*));
    for(int i=0; i<size; i++){
        novo->bloco[i]=block_creat_random(i);
    }
    novo->size = size;
    novo->hit = 0;
    novo->miss = 0;
    return novo;
}

void clearCache(Cache* cache){
    for(int i = 0;i<getSizeCache(cache);i++){
        Block* aux = createBlock();
        cache->bloco[i] = aux;
    }
}

void deleteCache(Cache* cache){
    for(int i = 0; i<getSizeCache(cache); i++){
        deleteBlock(cache->bloco[i]);
    }
    free(cache->bloco);
    free(cache);
}

void cache_switch(Cache* cache1, int add1, Cache* cache2, int add2){
    Block* aux=cache1->bloco[add1];
    cache1->bloco[add1]=cache2->bloco[add2];
    cache2->bloco[add2]=aux;
}

void cache_up(Cache* cache1, int pos, Block* bloco){
    cache1->bloco[pos]=bloco;
}

Block* cache_return_block(Cache* cache, int addBlock){
    for(int i = 0; i < getSizeCache(cache); i++){
        if(getAddBlock(getBlockCache(cache, i)) == addBlock){
            return cache->bloco[i];
        }
    }
    return cache->bloco[0];
}

int getHitCache(Cache* cache){
    return cache->hit;
}

int getMissCache(Cache* cache){
    return cache->miss;
}

int getSizeCache(Cache* cache){
    return cache->size;
}

Block* getBlockCache(Cache* cache, int pos){
    return cache->bloco[pos];
}

void setHitCache(Cache* cache,int hit){
    cache->hit += hit;
}

void setMissCache(Cache* cache,int miss){
    cache->miss += miss;
}

void setSizeCache(Cache* cache, int size){
    cache->size = size;
}

void setBlockCache(Cache* cache, Block** bloco){
    cache->bloco = bloco;
}

void showCache(Cache* cache, char* name){
    printf("\n%s | HIT: %d | MISS: %d \n\n", name, getHitCache(cache), getMissCache(cache));
    for (int i=0; i<getSizeCache(cache); i++){
        printf("\t %d", i+1);
    }
    printf("\n");
    printf("Word1: ");
    for (int i=0; i<getSizeCache(cache); i++){
        printf("\t %d", getWordBlock(getBlockCache(cache, i), 0));
    }
    printf("\n");
    printf("Word2: ");
    for (int i=0; i<getSizeCache(cache); i++){
        printf("\t %d", getWordBlock(getBlockCache(cache, i), 1));
    }
    printf("\n");
    printf("Word3: ");
    for (int i=0; i<getSizeCache(cache); i++){
        printf("\t %d", getWordBlock(getBlockCache(cache, i), 2));
    }
    printf("\n");
    printf("Word4: ");
    for (int i=0; i<getSizeCache(cache); i++){
        printf("\t %d", getWordBlock(getBlockCache(cache, i), 3));
    }
    printf("\n");
    printf("R_add: ");
    for (int i=0; i<getSizeCache(cache); i++){
        printf("\t %d", getAddBlock(getBlockCache(cache, i)));
    }
    printf("\n");
    printf("Empty: ");
    for (int i=0; i<getSizeCache(cache); i++){
        printf("\t %d", getEmptyBlock(getBlockCache(cache, i)));
    }
    printf("\n");
}
void showCache_all(Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, Cache* RAM_memory){
    printf("------------------------------------------------------------------------------------------\n");
    char name[20];
    strcpy(name, "Cache L1");
    showCache(cacheL1, name);
    strcpy(name, "Cache L2");
    showCache(cacheL2, name);
    strcpy(name, "Cache L3");
    showCache(cacheL3, name);
    strcpy(name, "RAM_memory");
    showCache(RAM_memory, name);
}

void cache_show_statistic(Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, Cache* RAM_memory, double* time){
  printf("------------------------------------------------------------------------------------------\n");
  printf("Informativo\n");
  printf("------------------------------------------------------------------------------------------\n");
  printf("\nTamanho da Cache:\n\n");
  printf("CacheL1: %d\n", getSizeCache(cacheL1));
  printf("CacheL2: %d\n", getSizeCache(cacheL2));
  printf("CacheL3: %d\n", getSizeCache(cacheL3));
  printf("RAM_memory: %d\n", getSizeCache(RAM_memory));

  printf("\nQuantidade de HIT/MISS:\n\n");
  printf("CacheL1: HIT: %d | MISS: %d\n", getHitCache(cacheL1),getMissCache(cacheL1));
  printf("CacheL2: HIT: %d | MISS: %d\n", getHitCache(cacheL2),getMissCache(cacheL2));
  printf("CacheL3: HIT: %d | MISS: %d\n", getHitCache(cacheL3),getMissCache(cacheL3));
  printf("RAM_memory: HIT: %d | MISS: %d\n", getHitCache(RAM_memory), 0);

  printf("\nTempo de execucao: %lf ms.\n", *time);

  double l1=(100.0*(double)(getHitCache(cacheL1)))/(double)(getHitCache(cacheL1)+getHitCache(cacheL2)+getHitCache(cacheL3)+getHitCache(RAM_memory));
  double l2=(100.0*(double)(getHitCache(cacheL2)))/(double)(getHitCache(cacheL1)+getHitCache(cacheL2)+getHitCache(cacheL3)+getHitCache(RAM_memory));
  double l3=(100.0*(double)(getHitCache(cacheL3)))/(double)(getHitCache(cacheL1)+getHitCache(cacheL2)+getHitCache(cacheL3)+getHitCache(RAM_memory));
  double ram=(100.0*(double)(getHitCache(RAM_memory)))/(double)(getHitCache(cacheL1)+getHitCache(cacheL2)+getHitCache(cacheL3)+getHitCache(RAM_memory));
  double ltotal=(100.0*(double)(getHitCache(cacheL1)+getHitCache(cacheL2)+getHitCache(cacheL3)))/(double)(getHitCache(cacheL1)+getHitCache(cacheL2)+getHitCache(cacheL3)+getHitCache(RAM_memory));

  printf("\nDados estatisticos:\n\n");

  printf("Cache L1: HIT: %.2lf %% | Miss: %.2lf %% |\n", l1, 100-l1);
  printf("Cache L2: HIT: %.2lf %% | Miss: %.2lf %% |\n", l2, 100-l2);
  printf("Cache L3: HIT: %.2lf %% | Miss: %.2lf %% |\n", l3, 100-l3);
  printf("RAM_memory: HIT: %.2lf %% | Miss: 0.0 |\n", ram);
  printf("Total: HIT: %.2lf %% | Miss: %.2lf %% |\n", ltotal, 100-ltotal);
}
