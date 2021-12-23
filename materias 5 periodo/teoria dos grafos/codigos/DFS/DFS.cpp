#include "DFS.hpp"

Fork createFork(){
    Fork fork; 
    int  verticeOrigin, verticeDestiny, wheight;

    // Lendo e atribuindo dados do grafo
    cin >> fork.numVertices >> fork.numEdges >> fork.isDirected >> fork.startVertice;
      
    // Criando matriz e alocando memória dinâmicamente
    Edge **matriz;
    matriz = (Edge**) malloc(fork.numVertices * sizeof (Edge*));
    for(int i = 0; i < fork.numVertices; i++){
        matriz[i] = (Edge*) malloc(fork.numVertices * sizeof (Edge));
    }

    for(int i = 0; i < fork.numEdges; i++){
        // Lendo entrada
        cin >> verticeOrigin >> verticeDestiny >> wheight;

        matriz[verticeOrigin-1][verticeDestiny-1].connection = 1;
        matriz[verticeOrigin-1][verticeDestiny-1].weight = wheight;

        // Caso o grafo não seja direcionado, atribuímos também de forma contrária
        if(fork.isDirected == 0){
            matriz[verticeDestiny-1][verticeOrigin-1].connection = 1;
            matriz[verticeDestiny-1][verticeOrigin-1].weight = wheight;
        }
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

void DFS(Fork *fork, int numVertice){
    // Flag que registra uma visita, utilizada para auxiliar na última etapa do algoritmo
    int change = 0;

    // Inserindo o identificador do vértice que está sendo visitado
    fork->visitationOrder.push_back(numVertice+1);

    // Percorrendo as colunas da matriz equivalente à linha do vértice atual
    for(int j = 0; j < fork->numVertices; j++){

        // Verificando conexão e se já foi visitado
        if((fork->matriz[numVertice][j].connection == 1) && (fork->matriz[numVertice][j].visited == 0)){
            change++;
            // Percorrendo a coluna do vértice em questão e marcando todos eles como visitado, para que este vérice não seja mais analisado
            for(int v = 0; v < fork->numVertices; v++){
                if((fork->matriz[v][numVertice].visited == 0) && (fork->matriz[v][numVertice].connection == 1)) fork->matriz[v][numVertice].visited = 1;
            }
            // Chamada recursiva passando o primeiro vértice não visitado encontrado
            DFS(fork, j);
        }

        // Condição que faz com que na última iteração, caso o vértice atual não consiga visitar outros e este seja adjacente à vértices das chamadas anteriores, 
        // a coluna dele é por completa marcada como visitada, fazendo com que a recursão avance com exito, não o visitando novamente
        if(j == fork->numVertices-1 && change == 0){
            for(int v = 0; v < fork->numVertices; v++){
                if((fork->matriz[v][numVertice].visited == 0) && (fork->matriz[v][numVertice].connection == 1)) fork->matriz[v][numVertice].visited = 1;
            }
        }            
    }
}

void showVisitationOrder(Fork fork){
    for(int i = 0; i < fork.visitationOrder.size(); i++){
        cout << fork.visitationOrder[i] << endl;
    }
}