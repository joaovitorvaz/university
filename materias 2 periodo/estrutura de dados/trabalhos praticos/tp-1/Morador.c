#include "Morador.h"

struct morador{
    char nome [100];
    char dtIngresso[12];
    int condicao;
};

Morador *criarMorador(char *nome, char *dtIngresso, int condicao){
    Morador* morador = malloc(sizeof(Morador));
    strcpy(morador->nome, nome);
    strcpy(morador->dtIngresso, dtIngresso);
    morador->condicao=condicao;
    return morador;
};

void apagarMorador(Morador *morador){
    free(morador);
}

void setNomeMorador(Morador *morador, char *nome){
    strcpy(morador->nome, nome);
}

void setDtIngressoMorador(Morador *morador, char *dtIngresso){
    strcpy(morador->dtIngresso, dtIngresso);
}

void setCondMorador(Morador *morador, int condicao){
    morador->condicao = condicao;
}

char* getNomeMorador(Morador *morador){
    return morador->nome;
}

char* getDtIngressoMorador(Morador *morador){
    return morador->dtIngresso;
}

int getCondMorador(Morador *morador){
    return morador->condicao;
}

void imprimeMorador(Morador* morador){
    printf("%s", morador->nome);
    printf("%s", morador->dtIngresso);
    printf("%d", morador->condicao);
}
