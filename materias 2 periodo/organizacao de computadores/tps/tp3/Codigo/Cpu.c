#include"Cpu.h"

int CPU(FILE* hardDisk, Cache* RAM_memory, Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, int* ARITMETIC_memory, int** instructions, int* HDHit){
    int time=0;
    int pick=0;
    int result;
    int interruption;
    int interrup=0;

    while(pick!=-1){

        int* one=instructions[time];
        pick=one[0];

        if(pick==-1){
            continue;
        }
        else{
            ARITMETIC_memory[10]=0;
            ARITMETIC_memory[0]=0;
            printf("Comando executado: ");
            ARITMETIC_memory[1]=MMU(hardDisk, RAM_memory, cacheL1, cacheL2, cacheL3, one[1], one[2], one[3], HDHit);
            ARITMETIC_memory[2]=MMU(hardDisk, RAM_memory, cacheL1, cacheL2, cacheL3, one[3], one[4], one[1], HDHit);
            //Acrescentar pra pegar o word3
            //Salvando na memoria cache.
            setWordBlock(getBlockCache(cacheL1, 0), 0, ALU(ARITMETIC_memory, pick));
            printf("%d\n\n", getWordBlock(getBlockCache(cacheL1, 0), 0));
        }

        //showCache_all(cacheL1, cacheL2, cacheL3, RAM_memory);

        // Interrupção
        interruption=rand()%10;

          if(interruption<=4){

            interrup++;

            for(int i=0; i<I; i++){

              ARITMETIC_memory[10]=0;
              ARITMETIC_memory[0]=0;
              int add1=rand()%100;
              int add2=rand()%100;
              int word=rand()%4;
              printf("Interrupcao: ");
              ARITMETIC_memory[1]=MMU(hardDisk, RAM_memory, cacheL1, cacheL2, cacheL3, add1, word, add2, HDHit);
              ARITMETIC_memory[2]=MMU(hardDisk, RAM_memory, cacheL1, cacheL2, cacheL3, add2, word, add1, HDHit);

              // SALVAR NA CACHE
              setWordBlock(getBlockCache(cacheL1, 0), 0 , ALU(ARITMETIC_memory, pick));
              printf("%d\n", getWordBlock(getBlockCache(cacheL1, 0), 0));

              if(i==I-1){
                printf("\n");
              }
          }
        }

        free(one);

        time++;
    }
    clearCache(RAM_memory);
    clearCache(cacheL3);
    clearCache(cacheL2);
    clearCache(cacheL1);

    return interrup;
}

int MMU(FILE* hardDisk, Cache* RAM_memory,Cache* cacheL1, Cache* cacheL2, Cache* cacheL3, int addBlock1, int word, int addBlock2, int* HDHit){
    //Verificação da cache 1
    for(int i = 0; i<getSizeCache(cacheL1); i++){
        if(getAddBlock(getBlockCache(cacheL1,i)) == addBlock1 && !getEmptyBlock(getBlockCache(cacheL1,i))){
            setHitCache(cacheL1,1);
            setHitBlock(getBlockCache(cacheL1,i),1);
            return getWordBlock(getBlockCache(cacheL1,i), word);
        }
    }
    setMissCache(cacheL1,1);

    //Verificacao da cache 2
    for(int i = 0; i<getSizeCache(cacheL2); i++){
        if(getAddBlock(getBlockCache(cacheL2, i)) == addBlock1 && !getEmptyBlock(getBlockCache(cacheL2,i))){
            setHitCache(cacheL2,1);
            setHitBlock(getBlockCache(cacheL2,i),1);

            //Caso cache 1 esteja vazia
            for(int j = 0; j<getSizeCache(cacheL1); j++){
                if(getEmptyBlock(getBlockCache(cacheL1,j))){
                    //Um bloco vai da cache 2 para a cache 1
                    cache_switch(cacheL1,j,cacheL2,i);
                    return getWordBlock(getBlockCache(cacheL1,j), word);
                }
            }
            //Caso a cache 1 não esteja vazia
            int add = 0;
            int menor = getHitBlock(getBlockCache(cacheL1,add));
            for(int j = 0; j<getSizeCache(cacheL1); j++){
                if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                    if(getAddBlock(getBlockCache(cacheL1,j))!= addBlock1){
                        if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock2){
                            add = j;
                            menor = getHitBlock(getBlockCache(cacheL1,add));
                            break;
                        }
                    }
                }
            }
            cache_switch(cacheL1,add,cacheL2,i);
            return getWordBlock(getBlockCache(cacheL1,add), word);
        }
    }
    setMissCache(cacheL2,1);

    //Verificacao na cache 3
    for(int i = 0; i<getSizeCache(cacheL3); i++){
        if(getAddBlock(getBlockCache(cacheL3,i)) == addBlock1 && !getEmptyBlock(getBlockCache(cacheL3,i))){
            setHitCache(cacheL3,1);
            setHitBlock(getBlockCache(cacheL3,i),1);

            //Verifica se cache 2  ta vazia
            //Se cache 2 esta vazia
            for(int j = 0; j< getSizeCache(cacheL2); j++){
                if(getEmptyBlock(getBlockCache(cacheL2,j)))
          {
                    cache_switch(cacheL2,j,cacheL3,i);

                    //Caso a cache 1 esteja vazia
                    for(int k = 0; k<getSizeCache(cacheL1); k++){
                        if(getEmptyBlock(getBlockCache(cacheL1,k))){
                            cache_switch(cacheL1,k,cacheL2,j);
                            return getWordBlock(getBlockCache(cacheL1,k), word);
                        }
                    }

                    //Caso a cache 1 não esteja vazia
                    int add = 0;
                    int menor = getHitBlock(getBlockCache(cacheL1,add));
                    for(int k = 0; k<getSizeCache(cacheL1); k++){
                        if(getHitBlock(getBlockCache(cacheL1,k)) <= menor){
                            if(getAddBlock(getBlockCache(cacheL1,k)) != addBlock1){
                                if(getAddBlock(getBlockCache(cacheL1,k)) != addBlock2){
                                    add = k;
                                    menor = getHitBlock(getBlockCache(cacheL1,add));
                                    break;
                                }
                            }
                        }
                    }
                    //Troca de um bloco entre cache 2 e cache 1
                    cache_switch(cacheL1,add,cacheL2,j);
                    return getWordBlock(getBlockCache(cacheL1,add),word);

            }

            //Caso a cache 2 nao esteja vazia
            int add2 = 0;
            int menor = getHitBlock(getBlockCache(cacheL2,add2));
            for(int j = 0; j<getSizeCache(cacheL2); j++){
                if(getHitBlock(getBlockCache(cacheL2,j))<=menor){
                    if(getAddBlock(getBlockCache(cacheL2,j))!=addBlock1){
                        if(getAddBlock(getBlockCache(cacheL2,j))!=addBlock2){
                            add2 = j;
                            menor = getHitBlock(getBlockCache(cacheL2,add2));
                            break;
                        }
                    }
                }
            }
            //Troca de bloco entre cache 3 e cache 2
            cache_switch(cacheL2,add2,cacheL3,i);
            int add1 = 0;
            menor  = getHitBlock(getBlockCache(cacheL1,add1));
            for(int j = 0; j<getSizeCache(cacheL1); j++){
                if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                    if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock1){
                        if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock2){
                            add1 = j;
                            menor = getHitBlock(getBlockCache(cacheL1,add1));
                            break;
                        }
                    }
                }
            }
            //Troca um bloco entre a cache 2 e a cache 1
            cache_switch(cacheL1,add1,cacheL2,add2);
            return getWordBlock(getBlockCache(cacheL1,add1),word);
        }
    }
    setMissCache(cacheL3,1);
    }
    //Verifica na memoria Ram(ultimo caso para pesquisa)
    for(int i = 0; i<getSizeCache(RAM_memory); i++){
        if(getAddBlock(getBlockCache(RAM_memory,i)) == addBlock1){
            setHitCache(RAM_memory,1);
            setHitBlock(getBlockCache(RAM_memory,i),1);

            //Caso a cache 3 esteja vazia
            for(int m = 0; m<getSizeCache(cacheL3); m++){
                if(getEmptyBlock(getBlockCache(cacheL3,m))){
                    cache_up(cacheL3,m,cache_return_block(RAM_memory, i));

                    //Verifica se a cache 2 tá vazia
                    //Se a cache 2 estiver vazia
                    for(int j = 0; j<getSizeCache(cacheL2); j++){
                        if(getEmptyBlock(getBlockCache(cacheL2,j))){
                            cache_switch(cacheL2,j,cacheL3,m);
                            //Se a cache 1 esta vazia
                            for(int k = 0;k<getSizeCache(cacheL1);k++){
                              if(getEmptyBlock(getBlockCache(cacheL1,k))){
                                cache_switch(cacheL1, k, cacheL2, j);
                                return getWordBlock(getBlockCache(cacheL1, k),word);
                              }
                            }
                            //Se a cache 1 nao esta vazia
                            int add = 0;
                            int menor  = getHitBlock(getBlockCache(cacheL1,add));
                            for(int k = 0; k<getSizeCache(cacheL1); k++){
                                if(getHitBlock(getBlockCache(cacheL1,k))<=menor){
                                    if(getAddBlock(getBlockCache(cacheL1,k))!= addBlock1){
                                        if(getAddBlock(getBlockCache(cacheL1,k))!= addBlock2){
                                            add = k;
                                            menor = getHitBlock(getBlockCache(cacheL1,add));
                                            break;
                                        }
                                    }
                                }
                            }
                            cache_switch(cacheL1,add,cacheL2,j);
                            return getWordBlock(getBlockCache(cacheL1,add),word);

                        }
                    }
                    //Caso a cache 2 nao esteja vazia
                    int add2 = 0;
                    int menor = getHitBlock(getBlockCache(cacheL2,add2));
                    for(int j = 1; j<getSizeCache(cacheL2); j++){
                        if(getHitBlock(getBlockCache(cacheL2,j))<=menor){
                            if(getAddBlock(getBlockCache(cacheL2,j))!=addBlock1){
                                if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock2){
                                    add2 = j;
                                    menor = getHitBlock(getBlockCache(cacheL2,add2));
                                    break;
                                }
                            }
                        }
                    }
                    //Troca um bloco entre cache 3 e cache 2
                    cache_switch(cacheL2,add2,cacheL3,m);
                    int add1 = 0;
                    menor = getHitBlock(getBlockCache(cacheL1,add1));
                    for(int j = 1; j<getSizeCache(cacheL1); j++){
                        if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                            if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock1){
                                if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock2){
                                    add1 = j;
                                    menor  = getHitBlock(getBlockCache(cacheL1,add1));
                                    break;
                                }
                            }
                        }
                    }
                    cache_switch(cacheL1,add1,cacheL2,add2);
                    return getWordBlock(getBlockCache(cacheL1,add1),word);
                }
            }
            //Caso a cache 3 nao esteja vazia
            int add3 = 0;
            int menor = getHitBlock(getBlockCache(cacheL3,add3));
            for(int j = 1; j<getSizeCache(cacheL3); j++){
                if(getHitBlock(getBlockCache(cacheL3,j)) <= menor){
                    if(getAddBlock(getBlockCache(cacheL3,j)) != addBlock1){
                        if(getAddBlock(getBlockCache(cacheL3,j)) != addBlock2){
                            add3 = j;
                            menor = getHitBlock(getBlockCache(cacheL3,add3));
                            break;
                        }
                    }
                }
            }
            cache_up(cacheL3,add3,cache_return_block(RAM_memory,addBlock1));
            //Se a cache 2 nao estiver vazia
            int add2 = 0;
            menor = getHitBlock(getBlockCache(cacheL2,add2));
            for(int j = 1; j< getSizeCache(cacheL2); j++){
                if(getHitBlock(getBlockCache(cacheL2,j))<=menor){
                    if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock1){
                        if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock2){
                            add2 = j;
                            menor = getHitBlock(getBlockCache(cacheL2,add2));
                            break;
                        }
                    }
                }
            }
            cache_switch(cacheL2,add2,cacheL3,add3);
            int add1 = 0;
            menor = getHitBlock(getBlockCache(cacheL1, add1));
            for(int j = 1; j<getSizeCache(cacheL1); j++){
                if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                    if(getAddBlock(getBlockCache(cacheL1,j))!=addBlock1){
                        if(getAddBlock(getBlockCache(cacheL1,j))!=addBlock2){
                            add1 = j;
                            menor = getHitBlock(getBlockCache(cacheL1,add1));
                            break;
                        }
                    }
                }
            }
            cache_switch(cacheL1,add1,cacheL2,add2);
            return getWordBlock(getBlockCache(cacheL1,add1),word);
        }
    }
    setMissCache(RAM_memory,1);
    //Verifica no HD(hard disk)
    *HDHit+=1;
    for(int i = 0;i<getSizeCache(RAM_memory);i++){
      if(getEmptyBlock(getBlockCache(RAM_memory, i))){
        cache_up(RAM_memory, i, block_from_HD_bin(hardDisk, addBlock1));

        //Caso a cache 3 esteja vazia
        for(int m = 0; m<getSizeCache(cacheL3); m++){
            if(getEmptyBlock(getBlockCache(cacheL3,m))){
                cache_switch(cacheL3, m, RAM_memory, i);

                //Verifica se a cache 2 tá vazia
                //Se a cache 2 estiver vazia
                for(int j = 0; j<getSizeCache(cacheL2); j++){
                    if(getEmptyBlock(getBlockCache(cacheL2,j))){
                        cache_switch(cacheL2,j,cacheL3,m);
                        //Se a cache 1 esta vazia
                        for(int k = 0;k<getSizeCache(cacheL1);k++){
                          if(getEmptyBlock(getBlockCache(cacheL1,k))){
                            cache_switch(cacheL1, k, cacheL2, j);
                            return getWordBlock(getBlockCache(cacheL1, k),word);
                          }
                        }
                        //Se a cache 1 nao esta vazia
                        int add = 0;
                        int menor  = getHitBlock(getBlockCache(cacheL1,add));
                        for(int k = 0; k<getSizeCache(cacheL1); k++){
                            if(getHitBlock(getBlockCache(cacheL1,k))<=menor){
                                if(getAddBlock(getBlockCache(cacheL1,k))!= addBlock1){
                                    if(getAddBlock(getBlockCache(cacheL1,k))!= addBlock2){
                                        add = k;
                                        menor = getHitBlock(getBlockCache(cacheL1,add));
                                        break;
                                    }
                                }
                            }
                        }
                        cache_switch(cacheL1,add,cacheL2,j);
                        return getWordBlock(getBlockCache(cacheL1,add),word);
                      }
                  }
                  //Caso a cache 2 nao esteja vazia
                  int add2 = 0;
                  int menor = getHitBlock(getBlockCache(cacheL2,add2));
                  for(int j = 1; j<getSizeCache(cacheL2); j++){
                      if(getHitBlock(getBlockCache(cacheL2,j))<=menor){
                          if(getAddBlock(getBlockCache(cacheL2,j))!=addBlock1){
                              if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock2){
                                  add2 = j;
                                  menor = getHitBlock(getBlockCache(cacheL2,add2));
                                  break;
                              }
                          }
                      }
                  }
                  //Troca um bloco entre cache 3 e cache 2
                  cache_switch(cacheL2,add2,cacheL3,m);
                  int add1 = 0;
                  menor = getHitBlock(getBlockCache(cacheL1,add1));
                  for(int j = 1; j<getSizeCache(cacheL1); j++){
                      if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                          if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock1){
                              if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock2){
                                  add1 = j;
                                  menor  = getHitBlock(getBlockCache(cacheL1,add1));
                                  break;
                              }
                          }
                      }
                  }
                  cache_switch(cacheL1,add1,cacheL2,add2);
                  return getWordBlock(getBlockCache(cacheL1,add1),word);
              }
          }
          //Caso a cache 3 nao esteja vazia
          int add3 = 0;
          int menor = getHitBlock(getBlockCache(cacheL3,add3));
          for(int j = 1; j<getSizeCache(cacheL3); j++){
              if(getHitBlock(getBlockCache(cacheL3,j)) <= menor){
                  if(getAddBlock(getBlockCache(cacheL3,j)) != addBlock1){
                      if(getAddBlock(getBlockCache(cacheL3,j)) != addBlock2){
                          add3 = j;
                          menor = getHitBlock(getBlockCache(cacheL3,add3));
                          break;
                      }
                  }
              }
          }
          cache_switch(cacheL3, add3, RAM_memory, i);
          //Se a cache 2 nao estiver vazia
          int add2 = 0;
          menor = getHitBlock(getBlockCache(cacheL2,add2));
          for(int j = 1; j< getSizeCache(cacheL2); j++){
              if(getHitBlock(getBlockCache(cacheL2,j))<=menor){
                  if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock1){
                      if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock2){
                          add2 = j;
                          menor = getHitBlock(getBlockCache(cacheL2,add2));
                          break;
                      }
                  }
              }
          }
          cache_switch(cacheL2,add2,cacheL3,add3);
          int add1 = 0;
          menor = getHitBlock(getBlockCache(cacheL1, add1));
          for(int j = 1; j<getSizeCache(cacheL1); j++){
              if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                  if(getAddBlock(getBlockCache(cacheL1,j))!=addBlock1){
                      if(getAddBlock(getBlockCache(cacheL1,j))!=addBlock2){
                          add1 = j;
                          menor = getHitBlock(getBlockCache(cacheL1,add1));
                          break;
                      }
                  }
              }
          }
          cache_switch(cacheL1,add1,cacheL2,add2);
          return getWordBlock(getBlockCache(cacheL1,add1),word);
          }

          else{
            int add4 = 0;
            int menor = getHitBlock(getBlockCache(RAM_memory, add4));
            for(int a = 1;a<getSizeCache(RAM_memory);a++){
              if(getHitBlock(getBlockCache(RAM_memory,a))<=menor){
                if(getAddBlock(getBlockCache(RAM_memory, a))!=addBlock1){
                  if(getAddBlock(getBlockCache(RAM_memory,a))!=addBlock2){
                    add4 = a;
                    menor = getHitBlock(getBlockCache(RAM_memory,add4));
                    break;
                  }
                }
              }
            }
            block_set_in_HD(hardDisk, getBlockCache(RAM_memory, add4), addBlock1);
            //Caso a cache 3 esteja vazia
            for(int m = 0; m<getSizeCache(cacheL3); m++){
                if(getEmptyBlock(getBlockCache(cacheL3,m))){
                    cache_switch(cacheL3, m, RAM_memory, add4);

                    //Verifica se a cache 2 tá vazia
                    //Se a cache 2 estiver vazia
                    for(int j = 0; j<getSizeCache(cacheL2); j++){
                        if(getEmptyBlock(getBlockCache(cacheL2,j))){
                            cache_switch(cacheL2,j,cacheL3,m);
                            //Se a cache 1 esta vazia
                            for(int k = 0;k<getSizeCache(cacheL1);k++){
                              if(getEmptyBlock(getBlockCache(cacheL1,k))){
                                cache_switch(cacheL1, k, cacheL2, j);
                                return getWordBlock(getBlockCache(cacheL1, k),word);
                              }
                            }
                            //Se a cache 1 nao esta vazia
                            int add = 0;
                            int menor  = getHitBlock(getBlockCache(cacheL1,add));
                            for(int k = 0; k<getSizeCache(cacheL1); k++){
                                if(getHitBlock(getBlockCache(cacheL1,k))<=menor){
                                    if(getAddBlock(getBlockCache(cacheL1,k))!= addBlock1){
                                        if(getAddBlock(getBlockCache(cacheL1,k))!= addBlock2){
                                            add = k;
                                            menor = getHitBlock(getBlockCache(cacheL1,add));
                                            break;
                                        }
                                    }
                                }
                            }
                            cache_switch(cacheL1,add,cacheL2,j);
                            return getWordBlock(getBlockCache(cacheL1,add),word);
                          }
                      }
                      //Caso a cache 2 nao esteja vazia
                      int add2 = 0;
                      int menor = getHitBlock(getBlockCache(cacheL2,add2));
                      for(int j = 1; j<getSizeCache(cacheL2); j++){
                          if(getHitBlock(getBlockCache(cacheL2,j))<=menor){
                              if(getAddBlock(getBlockCache(cacheL2,j))!=addBlock1){
                                  if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock2){
                                      add2 = j;
                                      menor = getHitBlock(getBlockCache(cacheL2,add2));
                                      break;
                                  }
                              }
                          }
                      }
                      //Troca um bloco entre cache 3 e cache 2
                      cache_switch(cacheL2,add2,cacheL3,m);
                      int add1 = 0;
                      menor = getHitBlock(getBlockCache(cacheL1,add1));
                      for(int j = 1; j<getSizeCache(cacheL1); j++){
                          if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                              if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock1){
                                  if(getAddBlock(getBlockCache(cacheL1,j)) != addBlock2){
                                      add1 = j;
                                      menor  = getHitBlock(getBlockCache(cacheL1,add1));
                                      break;
                                  }
                              }
                          }
                      }
                      cache_switch(cacheL1,add1,cacheL2,add2);
                      return getWordBlock(getBlockCache(cacheL1,add1),word);
                  }
              }
              //Caso a cache 3 nao esteja vazia
              int add3 = 0;
              menor = getHitBlock(getBlockCache(cacheL3,add3));
              for(int j = 1; j<getSizeCache(cacheL3); j++){
                  if(getHitBlock(getBlockCache(cacheL3,j)) <= menor){
                      if(getAddBlock(getBlockCache(cacheL3,j)) != addBlock1){
                          if(getAddBlock(getBlockCache(cacheL3,j)) != addBlock2){
                              add3 = j;
                              menor = getHitBlock(getBlockCache(cacheL3,add3));
                              break;
                          }
                      }
                  }
              }
              cache_switch(cacheL3, add3, RAM_memory, i);
              //Se a cache 2 nao estiver vazia
              int add2 = 0;
              menor = getHitBlock(getBlockCache(cacheL2,add2));
              for(int j = 1; j< getSizeCache(cacheL2); j++){
                  if(getHitBlock(getBlockCache(cacheL2,j))<=menor){
                      if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock1){
                          if(getAddBlock(getBlockCache(cacheL2,j)) != addBlock2){
                              add2 = j;
                              menor = getHitBlock(getBlockCache(cacheL2,add2));
                              break;
                          }
                      }
                  }
              }
              cache_switch(cacheL2,add2,cacheL3,add3);
              int add1 = 0;
              menor = getHitBlock(getBlockCache(cacheL1, add1));
              for(int j = 1; j<getSizeCache(cacheL1); j++){
                  if(getHitBlock(getBlockCache(cacheL1,j))<=menor){
                      if(getAddBlock(getBlockCache(cacheL1,j))!=addBlock1){
                          if(getAddBlock(getBlockCache(cacheL1,j))!=addBlock2){
                              add1 = j;
                              menor = getHitBlock(getBlockCache(cacheL1,add1));
                              break;
                          }
                      }
                  }
              }
              cache_switch(cacheL1,add1,cacheL2,add2);
              return getWordBlock(getBlockCache(cacheL1,add1),word);
        }
    }
    return 0;
 }



int ALU(int* ARITMETIC_memory, int pick){
    int** program  = NULL;
    int program_size;
    int term1=ARITMETIC_memory[1], term2=ARITMETIC_memory[2];
    switch(pick){
        case 0:{
            program=programaSoma(program_size);
            maquina(ARITMETIC_memory, program);
            printf("%d + %d = ", term1, term2);
            return ARITMETIC_memory[0];
            break;
        }
        case 1:{
            program = programaSubtracao(program_size);
            maquina(ARITMETIC_memory, program);
            printf("%d - %d = ", term1, term2);
            return ARITMETIC_memory[0];
            break;
        }
    }
    delete_programa(program, program_size);
    return ARITMETIC_memory[0];
}
