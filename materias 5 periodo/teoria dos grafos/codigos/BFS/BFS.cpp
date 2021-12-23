#include "BFS.hpp"

Fork CreateFork(){
    Fork fork;
    int verticeOrigin, verticeDestiny, weight;

    // Lendo e atribuindo dados do grafo
    cin >> fork.numVertices >> fork.numEdges >> fork.isDirected >> fork.startVertice;

    // Criando array de vértices com tamanho definido
    vector<Vertice> vertices(fork.numVertices); 
    // Atribuindo valores aos identificadores de cada vértice
    for(int i = 0; i< fork.numVertices; i++){
        vertices[i].id = i+1;
    }

    Edge auxEdge;
    for(int i = 0; i < fork.numEdges; i++){
        // Lendo entrada
        cin >> verticeOrigin >> verticeDestiny >> weight;

        auxEdge.verticeOrigin = verticeOrigin;
        auxEdge.verticeDestiny = verticeDestiny;
        auxEdge.weight = weight;

        // Adicionando aresta adjacente ao vértice em questão
        vertices[verticeOrigin-1].edges.push_back(auxEdge);

        // Caso o grafo não seja direcionado, atribuímos a aresta no vértice contrário
        if(fork.isDirected == 0){
            auxEdge.verticeOrigin = verticeDestiny;
            auxEdge.verticeDestiny = verticeOrigin;
            vertices[verticeDestiny-1].edges.push_back(auxEdge);
        }
    }

    // Ordenando a lista de arestas de cada um dos vértices de acordo com o id do vértice de destino (operador sobregarregado)
    for(int i = 0; i < fork.numVertices; i++){
        vertices[i].edges.sort();
    }

    fork.vertices = vertices;

    return fork;
}

void BFS(Fork *fork, int numVertice){
    int actualId;
    queue<Vertice> Q;
    list<Edge>::iterator it;

    // Marcando o vértice inicial como visitado e o inserindo na fila
    fork->vertices[numVertice-1].visited = 1;
    Q.push(fork->vertices[numVertice-1]);

    while(!Q.empty()){

        // Obtendo o identificador do primeiro vértice da fila
        actualId = Q.front().id-1;
        // Removendo o primeiro vértice da fila
        Q.pop();

        // Inserindo o identificador do vértice que está sendo visitado
        fork->visitationOrder.push_back(fork->vertices[actualId].id);

        // Percorrendo todos os vértices que o vértice em questão alcança através de sua lista de arestas
        for(it = fork->vertices[actualId].edges.begin(); it != fork->vertices[actualId].edges.end(); ++it){

            // Caso o vértice ainda não esteja visitado, o marcamos junto a aresta como visitado e o inserimos na fila de visitação
            if(fork->vertices[it->verticeDestiny-1].visited == 0){
                it->visited = 1;
                fork->vertices[it->verticeDestiny-1].visited = 1;                
                Q.push(fork->vertices[it->verticeDestiny-1]);
            }

            // Caso já visitado, marcamos a aresta como visitada            
            else {
                if(it->visited == 0){
                    it->visited = 1;
                }
            }
        }
    }
}

void showVisitationOrder(Fork fork){
    for(int i = 0; i < fork.visitationOrder.size(); i++){
        cout << fork.visitationOrder[i] << endl;
    }
}