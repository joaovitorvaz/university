#include "floydwarshall.hpp"

int main(){    
    Fork fork = createFork();
    floydWarshall(&fork);
    showMatriz(fork);
    freeMemory(&fork);
    
    return 0;
}