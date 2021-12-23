#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include <iostream>
#include <vector>
#include <algorithm>

#define INFINITE 999999

using namespace std;
using std::vector;

struct Edge{
    int connection = 0;
    int weight = INFINITE;
};

struct Fork{
    int numVertices = 0;
    int numEdges = 0;

    Edge **matriz;
};

Fork createFork();
void freeMemory(Fork *fork);
void floydWarshall(Fork *fork);
void showMatriz(Fork fork);

#endif