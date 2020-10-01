#ifndef NO_H
#define NO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

No* CriaNo();
No* LiberaNo(No* no);
void setContNo(No* no, int cont);
void setProxNo(No* no, No* prox);
int getContNo(No* no);
No* getProxNo(No* no);

#endif
