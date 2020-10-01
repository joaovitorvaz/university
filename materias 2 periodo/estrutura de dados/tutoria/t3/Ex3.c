#include <stdio.h>
int pesquisa(int k, int n);

int main()
{
	int k;
	long int n=762021192;
	printf ("Numero que deseja procurar: ");
	scanf ("%d", &k);
	int cont = pesquisa(k, n);
	printf ("\nO numero %d foi encontra %d vezes\n", k, cont);

	return 0;
}

int pesquisa(int k, int n) {
	if (n == 0) {
		return 0;
	}
	else if ((n % 10) == k) {
		return 1+pesquisa(k, n/10);
	}
	return pesquisa(k, n/10);
}
