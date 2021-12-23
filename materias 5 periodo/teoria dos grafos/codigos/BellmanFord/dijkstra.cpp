#include "dijkstra.hpp"

Fork createFork(){
    Fork fork;
    int verticeOrigin, verticeDestiny, weight;

    // Lendo e atribuindo dados do grafo
    cin >> fork.numVertices >> fork.numEdges >> fork.isDirected >> fork.startVertice;

    // Criando array de vértices com tamanho definido
    vector<Vertice> vertices(fork.numVertices);
    // Atribuindo valor de DT igual a 0 ao vértice que será visitado inicialmente
    vertices[fork.startVertice-1].dt = 0;
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
        vertices[verticeOrigin-1].edgesReach.push_back(auxEdge);
        vertices[verticeDestiny-1].edgesComeTo.push_back(auxEdge);
        
        // Caso o grafo não seja direcionado, atribuímos a aresta no vértice contrário
        if(fork.isDirected == 0){
            auxEdge.verticeOrigin = verticeDestiny;
            auxEdge.verticeDestiny = verticeOrigin;

            vertices[verticeDestiny-1].edgesReach.push_back(auxEdge);
            vertices[verticeOrigin-1].edgesComeTo.push_back(auxEdge);
        }
    }

    // Ordenando a lista de arestas de cada um dos vértices de acordo com o id do vértice de destino (operador sobregarregado)
    for(int i = 0; i < fork.numVertices; i++){
        vertices[i].edgesReach.sort();
        vertices[i].edgesComeTo.sort();
    }

    fork.vertices = vertices;

    return fork;
}

void dijkstra(Fork *fork){
    list<Edge>::iterator it;

    // Percorrendo cada um dos vértices do grafo de forma linear
    for(int i = 0; i < fork->numVertices; i++){

        // Percorrendo todos os vértices que alcançam o vértice em questão através de sua lista de arestas
        for(it = fork->vertices[i].edgesComeTo.begin(); it != fork->vertices[i].edgesComeTo.end(); ++it){

            // Caso o DT do vértice atual seja maior que o DT do vértice que aponta para ele + o peso da aresta os conectam, uma atualização é feita
            if(fork->vertices[i].dt > fork->vertices[it->verticeOrigin-1].dt + it->weight){                
                it->visited = 1;
                fork->vertices[i].dt = fork->vertices[it->verticeOrigin-1].dt + it->weight;
                fork->vertices[i].hot = fork->vertices[it->verticeOrigin-1].id;
            }                       
        }

        // Fechando o vértice atual
        fork->vertices[i].closed = 1;
    }
}

void showWays(Fork fork){
    vector<int> way;
    for(int i = 0; i < fork.numVertices; i++){
        if(i == fork.startVertice-1) continue;
        else {
            way.clear();

            cout << fork.vertices[i].id << " (" << fork.vertices[i].dt << "):";

            // Percorrendo o caminho do HOT da forma inversa
            way.push_back(fork.vertices[i].id);
            while(way.back() != fork.startVertice){                
                way.push_back(fork.vertices[way.back()-1].hot);
            }
            // Exibindo o caminho de forma ajustada à lógica acima
            for(int j = way.size()-1; j >= 0; j--){
                cout << " " << way[j];
            }   

            cout << endl;
        }        
    }
}