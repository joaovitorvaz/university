//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC265-32P
#include <stdio.h>
#include <stdlib.h>

int **alocarfunc(int n);
void confere(int **matriz, int n);

int main()
{
    int n;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    printf("\n");

    int **matriz=alocarfunc(n);

    printf("Digite o valor da matriz n x n:\n\n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n");

    confere(matriz, n);

    for(int i=0; i<n; i++){
        free(matriz[i]);
    }

    free(matriz);
    return 0;
}

int **alocarfunc(int n){
    int **matriz = malloc(n * sizeof(int*));
        for(int i=0; i<n; i++){
            matriz[i] = malloc(n * sizeof(int));
        }

    return matriz;
}

void confere(int **matriz, int n){
    int quadmagico=0;
    int linha[n];
    int coluna[n];
    int dp=0, ds=0;
    int cont=0, c=0;;
    int ideal;

    for(int i=0; i<1; i++){
        for(int j=0; j<n; j++){
            quadmagico+=matriz[i][j];
        }
    }

    for(int i=0; i<n; i++){
    coluna[i]=0;
        for(int j=0; j<n; j++){
            coluna[i]+=matriz[i][j];
        }
      if (coluna[i]==quadmagico){
      cont++;
      }
    }

    for(int j=0; j<n; j++){
    linha[j]=0;
        for(int i=0; i<n; i++){
            linha[j]+=matriz[i][j];
        }
      if (linha[j]==quadmagico){
      cont++;
      }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
            dp+=matriz[i][j];
            }
        }
    }
    if(dp==quadmagico){
        cont++;
    }

    for(int i=n-1; i>=0; i--){
        ds+=matriz[c][i];
        c++;
    }

    if(ds==quadmagico){
        cont++;
    }

    ideal=n+n+2;

    if(cont==ideal){
        printf("Esta matriz e um quadrado magico!\n");
    }
    else
        printf("Esta matriz nao e um quadrado magico!\n");
}
