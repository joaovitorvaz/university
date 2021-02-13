//Marcus Vinícius Souza Fernandes  -  19.1.4046  -  BCC201-61P
#include <stdio.h>
#define X 10

void matriz(double mult [][X], int m, int n, int p, int q);

int main ()
{
  int m, n, p, q;
  double mult [m][q];

  do {
  printf ("Insira valores de M e P: ");
  scanf ("%d %d", &m, &p);
  printf ("Insira valores de Q e N: ");
  scanf ("%d %d", &q, &n);
  } while ((p!=q) || (m>X) || (n>X) || (p>X) || (q>X));

  printf("\n");

  matriz(mult, m, n, p, q);

  return 0;
}

void matriz(double mult [] [X], int m, int n, int p, int q) {

double ma1 [m] [p];
double ma2 [q] [n];

  for (int i=0; i<m; i++){
    for (int j=0; j<p; j++){
      printf ("Insira um valor para | linha: %d | coluna: %d | matriz 1:  ", i+1, j+1);
      scanf ("%lf", &ma1 [i] [j]);
    }
  }

  printf("\n\n");

  for (int i=0; i<q; i++){
    for (int j=0; j<n; j++){
      printf ("Insira um valor para | linha: %d | coluna: %d | matriz 2:  ", i+1, j+1);
      scanf ("%lf", &ma2 [i] [j]);
    }
  }

  for (int i=0; i<m; i++) {
    for (int j=0; j<q; j++) {
      mult[i][j] = 0;
    }
  }

  printf("\n\n\n");

  for (int i=0; i<m; i++){
    for (int j=0; j<p; j++){
      for (int k=0; k<n; k++){
        mult[i] [j] += ma1[i] [k] * ma2[k] [j];
      }
    }
  }

  for (int i=0; i<m; i++){
		for (int j=0; j<q; j++){
			printf ("\t%.1lf\t", mult[i][j]);
		}
		printf ("\n");
	}
  printf ("\n\n");
}
