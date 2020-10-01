#include<stdio.h>
#include<stdlib.h>

char **criarMatriz(void);
void imprimirMatriz(char **matriz);
void caminho(char ***matriz, int x, int y);


int main(){
	char **mat = criarMatriz();
	int x=0, y=0;
	imprimirMatriz(mat);
	caminho(&mat, x, y);

	return 0;
}

char **criarMatriz(void){
	char **matriz = malloc(5 *sizeof(char*));
	for(int i=0; i<5; i++){
		matriz[i]=malloc(5 *sizeof(char));
		for(int j=0; j<5; j++)
			matriz[i][j] = '1';
	}
	matriz[0][4] = 'x';
	matriz[1][0] = 'x';
	matriz[1][4] = 'x';
	matriz[2][1] = 'x';
	matriz[2][2] = 'x';
	matriz[2][4] = 'x';
	matriz[3][0] = 'x';
	matriz[3][4] = 'x';
	matriz[4][0] = 'x';
	matriz[4][1] = 'x';
	return matriz;
}

void imprimirMatriz(char **matriz){
	printf("Labirinto\n\n");
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			printf(" %c ", matriz[i][j]);
		printf("\n");
	}
	printf("\n\n");

}

void caminho(char ***matriz, int x, int y){

	if(x==4 && y==4){
		(*matriz)[x][y] = 'O';
		imprimirMatriz(*matriz);
		printf("Concluido...\n");
		exit(0);
	}
	if(x>4 || x<0 || y>4 || y<0 || (*matriz)[x][y] == 'x')
		return;
	else
		(*matriz)[x][y] = 'O';

	imprimirMatriz(*matriz);
	caminho(matriz, x, y + 1);
	caminho(matriz, x + 1, y);
	caminho(matriz, x, y - 1);
	caminho(matriz, x -1, y);


}
