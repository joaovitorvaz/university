#include "bellmanford.hpp"

void bellmanFord(Fork *fork, int *error){
    int change;
    Fork oldFork;

    for(int i = 0; i < fork->numVertices; i++){        
        change = 0;
        // Criando uma cópia do grafo visando uma comparação futura
        oldFork = *fork;

        dijkstra(fork);
        change = hasChange(oldFork, *fork);

        // Verificando a existência de ciclos de custo negativo
        if((i == fork->numVertices-1) && (change == 1)) *error = 1;
        // Verificando se não houveram mudanças para finalizar o programa com antecedência
        else if(change == 0) i = fork->numVertices;
        else clearClosedAndVisited(fork);
    }  
}

// Função para averiguar se houveram alterações no grafo
int hasChange(Fork oldFork, Fork actualFork){    
    for(int i = 0; i < actualFork.numVertices; i++){
        if((oldFork.vertices[i].dt != actualFork.vertices[i].dt) 
        || (oldFork.vertices[i].hot != actualFork.vertices[i].hot)) return 1;
    } 
    
    return 0;
}

// Função para resetar os atributos "visited" e "closed"
void clearClosedAndVisited(Fork *fork){
    list<Edge>::iterator it;

    for(int i = 0; i < fork->numVertices; i++){
        fork->vertices[i].closed = 0;
        for(it = fork->vertices[i].edgesReach.begin(); it != fork->vertices[i].edgesReach.end(); ++it){
            it->visited = 0;
        }
    }  
}