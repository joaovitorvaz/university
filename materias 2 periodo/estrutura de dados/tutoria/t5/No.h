#ifndef NO_H
#define NO_H

typedef struct no No;

No* criaNo(int info);
void liberaNo(No *no);
void imprimeNo(No *no);
int getInfoNo(No* no);
No* getProxNo(No* no);
void setInfoNo(No* no, int info);
void setProxNo(No* no, No* prox);

#endif
