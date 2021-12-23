#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

struct Edge{
    int connection = 0;
    int visited = 0;
    int weight = 1;
};

struct Fork{
    int numVertices = 0;
    int numEdges = 0;
    int isDirected = 0;
    int startVertice = 0;

    Edge **matriz;
    vector<int> visitationOrder;
};

Fork createFork();
void freeMemory(Fork *fork);
void DFS(Fork *fork, int numVertice);
void showVisitationOrder(Fork fork);

#endif