#include"Instructions.h"

int* criaAritmetica(int size){
    int* ARITMETIC_memory=malloc(size*sizeof(int));
    for (int i=0; i<size; i++){
        ARITMETIC_memory[i]=0;
    }
    return ARITMETIC_memory;
}

void liberaAritmetica(int* ARITMETIC_memory){
    free(ARITMETIC_memory);
}

int** criaPrograma(int size){
  int** programa=malloc(size*sizeof(int*));
  for(int i=0; i<size; i++){
    programa[i]=malloc(4*sizeof(int));
  }
  return programa;
}

void delete_programa(int** program, int programa_size){
    for(int i=0; i<programa_size; i++){
        free(program[i]);
    }
    free(program);
}

//Se o usuario desejar realizar uma soma simples essa funcao e chamada e as instrucoes são encaminhadas para a maquina
int** programaSoma(int* ARITMETIC_memory, int size){

    size= 1+1;
    int** program=criaPrograma(size);

    program[0][0] = 0;
    program[0][1] = 1;
    program[0][2] = 2;
    program[0][3] = 0;

    //Halt
    program[1][0] = -1;
    program[1][1] = -1;
    program[1][2] = -1;
    program[1][3] = -1;

    return program;
}

//Logica semelhante da funcao proginstructionsaSoma, porem engloba a subtracao
int** programaSubtracao(int programa_size, int* Aritmetic_memory){
    programa_size=1+1;
    int** program=criaPrograma(programa_size);

    program[0][0] = 1;
    program[0][1] = 1;
    program[0][2] = 2;
    program[0][3] = 0;

    //halt
    program[1][0] = -1;
    program[1][1] = -1;
    program[1][2] = -1;
    program[1][3] = -1;

    return program;
}

int** starta_instrucoes(int* inst, int L1_size){
    int choice;
    bool *flag=malloc(sizeof(bool));
    int** problems = NULL;
        do{
            problems = ler_instrucoes(inst, flag);
        }while(!flag);

        return problems;
}


int** ler_instrucoes(int* inst, bool *flag){
    char name[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s",name);
    FILE* load = fopen(name,"r");
    if(load == NULL){
        printf("Erro ao tentar abrir arquivo\n");
        return NULL;
    }
    else{

        *inst = 0;
        char ch;

        while((ch = fgetc(load)) != EOF){
            if(ch == '\n'){
                (*inst)++;
            }
        }

        rewind(load);

        //Declara matriz com o mesmo numero de linhas que o arquivo
        int** novo=malloc((*inst) *sizeof(int*));
        for(int i=0; i<(*inst); i++){
            novo[i]=malloc(7 *sizeof(int));
        }

        int op;
        int addBlock1;
        int word1;
        int addBlock2;
        int word2;
        int addBlock3;
        int word3;

        //Adiciona os valores a matriz
        for(int index=0; index<(*inst); index++){
            fscanf(load,"%d %d %d %d %d %d %d", &op, &addBlock1, &word1, &addBlock2, &word2, &addBlock3, &word3);
            novo[index][0] = op;
            novo[index][1] = addBlock1;
            novo[index][2] = word1;
            novo[index][3] = addBlock2;
            novo[index][4] = word2;
            novo[index][5] = addBlock3;
            novo[index][6] = word3;

        }
        fclose(load);

        *flag=true;

        printf("\n\n");

        return novo;
    }
}
