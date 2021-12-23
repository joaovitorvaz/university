#include "DFS.hpp"

int main(){    
    Fork fork = createFork();
    DFS(&fork, fork.startVertice-1);
    showVisitationOrder(fork);
    freeMemory(&fork);    

    return 0;
}