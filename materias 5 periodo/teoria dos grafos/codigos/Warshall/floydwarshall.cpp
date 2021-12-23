#include "floydwarshall.hpp"

Fork createFork(){
    Fork fork;
    int  verticeOrigin, verticeDestiny, wheight;

    // Lendo e atribuindo dados do grafo
    cin >> fork.numVertices >> fork.numEdges;
      
    // Criando matriz e alocando memória dinâmicamente
    Edge **matriz;
    matriz = (Edge**) malloc(fork.numVertices * sizeof (Edge*));
    for(int i = 0; i < fork.numVertices; i++){
        matriz[i] = (Edge*) malloc(fork.numVertices * sizeof (Edge));
        for(int j = 0; j < fork.numVertices; j++){
            // Atribuindo valores iniciais
            if(i == j) matriz[i][j].weight = 0;
            else matriz[i][j].weight = INFINITE;
        }
    }

    for(int i = 0; i < fork.numEdges; i++){
        // Lendo entrada
        cin >> verticeOrigin >> verticeDestiny >> wheight;

        matriz[verticeOrigin-1][verticeDestiny-1].connection = 1;
        matriz[verticeOrigin-1][verticeDestiny-1].weight = wheight;
    }

    fork.matriz = matriz;

    return fork;
}

// Desalocando matriz
void freeMemory(Fork *fork){
    for(int i = 0; i < fork->numVertices; i++){
        free(fork->matriz[i]);
    }
    free(fork->matriz);
}

void floydWarshall(Fork *fork){
    // i - Origem do caminho
    // j - Destino do caminho
    // k - Intermediário

    // Laço triplo avaliando todos os caminhos passando por todos os intermediários

    for(int k = 0; k < fork->numVertices; k++){ 
        for(int i = 0; i < fork->numVertices; i++){     
            for(int j = 0; j < fork->numVertices; j++){  
                // Checando se o intermediário é válido
                if((fork->matriz[i][k].weight != INFINITE) && (fork->matriz[k][j].weight != INFINITE)){
                    // Se o caminho de i para j for maior do que o de i para k + k para j, o valor é atualizado
                    if(fork->matriz[i][j].weight > fork->matriz[i][k].weight + fork->matriz[k][j].weight){
                        fork->matriz[i][j].weight = fork->matriz[i][k].weight + fork->matriz[k][j].weight;
                    }
                }                    
            }     
        }         
    }
}

void showMatriz(Fork fork){
    for(int i = 0; i < fork.numVertices; i++){
        for(int j = 0; j < fork.numVertices; j++){
            if(fork.matriz[i][j].weight == INFINITE) cout << "- ";
            else cout << fork.matriz[i][j].weight << " ";
        }
        cout << endl;
    }
}