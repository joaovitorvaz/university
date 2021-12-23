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

void dijkstra(Fork *fork, int numVertice){
    int actualId;
    priority_queue<Vertice, vector<Vertice>, Comparator> Q;
    list<Edge>::iterator it;

    // inserindo o vértice inicial na fila
    Q.push(fork->vertices[numVertice-1]);

    while(!Q.empty()){

        // Obtendo o identificador do primeiro vértice da fila
        actualId = Q.top().id-1;
        // Removendo o primeiro vértice da fila
        Q.pop();

        // Caso o vértice já esteja fechado o pulamos
        if(fork->vertices[actualId].closed == 1) continue;

        // Percorrendo todos os vértices que o vértice em questão alcança através de sua lista de arestas
        for(it = fork->vertices[actualId].edges.begin(); it != fork->vertices[actualId].edges.end(); ++it){

            // Caso o DT do vértice que a aresta atual aponta seja maior que o DT do vértice atual + o peso da aresta os conectam, uma atualização é feita
            if(fork->vertices[it->verticeDestiny-1].dt > fork->vertices[actualId].dt + it->weight){                
                fork->vertices[it->verticeDestiny-1].dt = fork->vertices[actualId].dt + it->weight;
                fork->vertices[it->verticeDestiny-1].hot = fork->vertices[actualId].id;
            }

            // Caso o vértice ainda não esteja visitado, o marcamos junto a aresta como visitado e o inserimos na fila de visitação
            if(fork->vertices[it->verticeDestiny-1].closed == 0){
                it->visited = 1;         
                Q.push(fork->vertices[it->verticeDestiny-1]);
            } 

            // Caso já visitado, marcamos a aresta como visitada     
            else {
                if(it->visited == 0){
                    it->visited = 1;
                }
            }            
        }

        fork->vertices[actualId].closed = 1;
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