#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "dijkstra.hpp"

void bellmanFord(Fork *fork, int *error);
int hasChange(Fork oldFork, Fork actualFork);
void clearClosedAndVisited(Fork *fork);

#endif