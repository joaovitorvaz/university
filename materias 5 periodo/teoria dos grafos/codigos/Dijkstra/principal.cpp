#include "dijkstra.hpp"

int main(){
    Fork fork = createFork();
    dijkstra(&fork, fork.startVertice);
    showWays(fork);    
    return 0;
}