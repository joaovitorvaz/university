#include "BFS.hpp"

int main(){
    Fork fork = CreateFork();
    BFS(&fork, fork.startVertice);
    showVisitationOrder(fork);
    return 0;
}