#include"Machine.h"

void maquina(int* ARITMETIC_memory, int** program){

    int pc = 0;
    int opcode = 0;
    while(opcode != -1){
        int* one_instruction=program[pc];
        opcode = one_instruction[0];
        switch(opcode){

          case 0:{
              //somar
              int add1 = ARITMETIC_memory[one_instruction[1]];
              int add2 = ARITMETIC_memory[one_instruction[2]];
              int sum=add1+add2;
              ARITMETIC_memory[one_instruction[3]]+=sum;
              break;
          }

          case 1:{

              //subtrai
              int add1 = ARITMETIC_memory[one_instruction[1]];
              int add2 = ARITMETIC_memory[one_instruction[2]];
              int sub=add1-add2;
              ARITMETIC_memory[one_instruction[3]]+=sub;
              break;
          }
        }
        pc++;
    }
}
