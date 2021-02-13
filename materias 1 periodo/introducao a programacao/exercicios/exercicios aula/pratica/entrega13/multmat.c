
//Marcus Vinícius Souza Fernandes - 19.1.4046 - BCC265-32P
#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int ***R, int **A, int n, int m, int **B, int p, int q);

int main()
{
    int n, m;
    int p, q;
    int r;
    int **matR;

    //Matriz A

    printf("Insira os tamanhos da matriz A: ");
    scanf("%d %d", &n, &m);
    int **A=malloc(n * sizeof(int*));
    for (int i=0; i<n; i++){
      A[i]=malloc(m * sizeof(int));
    }
    printf("\nDigite os dados da matriz A: ");
    printf("\n\n");
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        scanf("%d", &A[i][j]);
      }
    }

    printf("\n");

    //Matriz B

    printf("Insira os tamanhos da matriz B: ");
    scanf("%d %d", &p, &q);
    int **B=malloc(p * sizeof(int*));
    for (int i=0; i<p; i++){
      B[i]=malloc(q * sizeof(int));
    }
    printf("\nDigite os dados da matriz B: ");
    printf("\n\n");
    for(int i=0; i<p; i++){
      for(int j=0; j<q; j++){
        scanf("%d", &B[i][j]);
      }
    }

    printf("\n");

    if (multiplicaMatrizes(&matR, A, n, m, B, p, q)){
      printf("Resultado de A x B: \n\n");
      for(int i=0; i<n; i++){
        for(int j=0; j<q; j++){
          printf("%d ", matR[i][j]);
        }
        printf("\n");
      }
    }
    else
      printf("Nao ha solucao.");

    //Liberar memória

    for(int i=0; i<m; i++){
      free(A[i]);
    }
    for(int i=0; i<q; i++){
      free(B[i]);
    }
    for(int i=0; i<n; i++){
      free(matR[i]);
    }
    free(A);
    free(B);
    free(matR);

    return 0;
}

int multiplicaMatrizes(int ***R, int **A, int n, int m, int **B, int p, int q){

  if (m == p){

    *R = malloc (n * sizeof (int*));
      for (int i = 0; i < n; i ++){
        (*R)[i] = calloc (q, sizeof (int));
      }

    for(int i=0; i<n; i++){
      for (int j=0; j < q; j++){
        for (int k=0; k < m; k++){
          (*R)[i][j]+= A[i][k] * B[k][j];
        }
      }
    }
    return 1;
    }

  else
    return 0;
}
