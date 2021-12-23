#include "bellmanford.hpp"

int main(){
    Fork fork = createFork();
    int hasError = 0;
    bellmanFord(&fork, &hasError);
    if(hasError == 0) showWays(fork);   
    else cout << "ERRO: CICLO DE CUSTO NEGATIVO!" << endl;
    return 0;
}