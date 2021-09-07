#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "./unit_system.h"
#include "./unit_model.h"
#include "./unit_tests.h"

int main(){
    cout << "\n========== Testes unitarios da Classe System ===========\n" << endl;
    run_unit_tests_system();
    cout << "\n=========== Testes unitarios da Classe Flow ============\n" << endl;
    run_unit_tests_flow();
    cout << "\n=========== Testes unitarios da Classe Model ===========\n"<< endl;
    run_unit_tests_model();
    cout << "\n========= Testes unitarios de Funcoes Globais ==========\n"<< endl;
    run_unit_tests_globals();
    cout << "\n========================================================\n" << endl;

    return 0;
}

#endif