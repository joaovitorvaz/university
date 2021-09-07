#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/syscall.h>

int SALDO = 0;
int KEY;

struct T_args {
    pthread_t thread;
};

void interface();

// Funções de cada uma das threads
void *addMoneyUnit(void *arg);
void *removeMoneyUnit(void *arg);
void *printMoneyUnit(void *arg);
void *restartSystem(void *arg);

int main(){
    
    interface();
    
    pthread_t addMoneyUnitThread;
    pthread_t removeMoneyUnitThread;
    pthread_t printMoneyUnitThread;
    pthread_t restartSystemThread;
    
    // Captura do valor da tecla sem pressionar ENTER
    system("/bin/stty raw");
    
    // Argumentos das threads
    struct T_args *threadPrint  = (struct T_args *) malloc(sizeof(struct T_args));
    struct T_args *threadAdd    = (struct T_args *) malloc(sizeof(struct T_args));
    struct T_args *threadRemove = (struct T_args *) malloc(sizeof(struct T_args));
    threadPrint->thread  = printMoneyUnitThread;
    threadAdd->thread    = addMoneyUnitThread;
    threadRemove->thread = removeMoneyUnitThread;
    
    // Cria threads de soma, remoção e impressão
    pthread_create(&printMoneyUnitThread,  NULL, printMoneyUnit,  (void *) threadPrint);
    pthread_create(&addMoneyUnitThread,    NULL, addMoneyUnit,    (void *) threadAdd);
    pthread_create(&removeMoneyUnitThread, NULL, removeMoneyUnit, (void *) threadRemove);

    do{
        // Altera opções
        KEY = getc(stdin);
        
        // Mata threads
        // k
        if (KEY == 107){
            pthread_kill(addMoneyUnitThread, 0);
            pthread_kill(removeMoneyUnitThread, 0);
            pthread_kill(printMoneyUnitThread, 0);
            printf("\n=======================================\n");
            printf("Terminando (kill) Threads... OK\n");
            printf("=======================================\n");
        }

        // Reinicia o sistema limpando operações e tela
        // r
        else if(KEY == 114){
            
            // Termina as thread em execução e cria novas
            pthread_join(addMoneyUnitThread, NULL);
            pthread_kill(addMoneyUnitThread, 0);
            pthread_join(removeMoneyUnitThread, NULL);
            pthread_kill(removeMoneyUnitThread, 0);
            pthread_join(printMoneyUnitThread, NULL);
            pthread_kill(printMoneyUnitThread, 0);
            
            pthread_create(&restartSystemThread, NULL, restartSystem, NULL);
            pthread_create(&printMoneyUnitThread, NULL, printMoneyUnit, (void *) threadPrint);
            pthread_create(&addMoneyUnitThread, NULL, addMoneyUnit, (void *) threadAdd);
            pthread_create(&removeMoneyUnitThread, NULL, removeMoneyUnit, (void *) threadRemove);
            
            pthread_join(restartSystemThread, NULL);
            interface();
        }

    // k
    }while(KEY != 107);
    
    system ("/bin/stty cooked");
    
    return  0;
}

// Interface do menu
void interface(){    
    printf("--------------------------------------------\n");
    printf("Pressione [+] Para adicionar 100 UD ao saldo\n");
    printf("Pressione [-] Para retirar 50 UD do saldo   \n");
    printf("Pressione [s] Para imprimir o saldo         \n");
    printf("Pressione [k] Para matar as thread criadas  \n");
    printf("Pressione [r] Para limpar a tela e operações\n");
    printf("--------------------------------------------\n\n");    
}

// Deposita 100 unidadeds de dinheiro
void *addMoneyUnit(void *arg){    
    do{
    
        if (KEY == 43){
            printf("\nAdicionando 100 UD com TID: %ld\n", syscall(__NR_gettid));
            SALDO += 100;
            KEY = 0;
        }
        
        else if (KEY == 107 || KEY == 114){
            pthread_exit(0);
        }
        
    }while(1);    
}

// Retira 50 unidadeds de dinheiro
void *removeMoneyUnit(void *arg){    
    do{
        
        if (KEY == 45){
            printf("\nRemovendo 50 UD com TID   : %ld\n", syscall(__NR_gettid));
            SALDO -= 50;
            KEY = 0;
        }
        
        else if (KEY == 107 || KEY == 114){
            pthread_exit(0);
        }
        
    }while(1);    
}

// Printa saldo
void *printMoneyUnit(void *arg){    
    do{
    
        if (KEY == 115){
            printf("\n----------------------------------------\n");
            printf("Mostrando saldo UD com TID: %ld\n", syscall(__NR_gettid));
            printf("Saldo em conta            : %d UD\n", SALDO);
            printf("----------------------------------------\n");
            KEY = 0;
        }
        
        else if (KEY == 107 || KEY == 114){
            pthread_exit(0);
        }
        
    }while(1);    
}

// Reinicia
void *restartSystem(void *arg){    
    SALDO = 0;
    KEY = 0;
    system("clear");
    pthread_exit(0);    
}
