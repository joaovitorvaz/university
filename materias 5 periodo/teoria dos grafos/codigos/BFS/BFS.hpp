#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;
using std::vector;
using std::list;

struct Edge{    
    int verticeOrigin = -1;
    int verticeDestiny = -1;
    int weight = 1;
    int visited = 0;

    bool operator <(Edge const &e) const { 
        return verticeDestiny < e.verticeDestiny; 
    }
};

struct Vertice{
    int id = -1;
    int visited = 0;

    list<Edge> edges;
};

struct Fork{
    int numVertices = 0;
    int numEdges = 0;
    int isDirected = 0;
    int startVertice = 0;

    vector<Vertice> vertices;
    vector<int> visitationOrder;
};

Fork CreateFork();
void BFS(Fork *fork, int numVertice);
void showFork(Fork fork);
void showVisitationOrder(Fork fork);

#endif