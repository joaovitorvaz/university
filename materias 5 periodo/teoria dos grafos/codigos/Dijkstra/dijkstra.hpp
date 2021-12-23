#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

#define INFINITE 999999

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
    int closed = 0;

    int dt = INFINITE;
    int hot = 0;

    list<Edge> edges;

    bool operator <(Vertice const &v) const {
        if(dt == v.dt) return id < v.id;
        else return dt < v.dt;
    }

    bool operator ==(Vertice const &v) const {
        return id == v.id;
    }
};

// Struct para auxiliar na ordenação decrescente da priority_queue (Criada para aumentar o desempenho do código)
struct Comparator{
    bool operator ()(Vertice const &v1, Vertice const &v2) const {
        if(v1.dt == v2.dt) return v1.id > v2.id;
        else return v1.dt > v2.dt;        
    }
};

struct Fork{
    int numVertices = 0;
    int numEdges = 0;
    int isDirected = 0;
    int startVertice = 0;

    vector<Vertice> vertices;
};

Fork createFork();
void dijkstra(Fork *fork, int numVertice);
void showWays(Fork fork);

#endif