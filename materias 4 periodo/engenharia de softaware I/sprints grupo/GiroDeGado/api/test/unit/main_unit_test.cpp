#include "./main_unit_test.h"
#include "./unit_cattle.h"
#include "./unit_transaction.h"
#include "./unit_user.h"

#include <QtSql/QtSql>

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
    int numHandleDeleted = 0;
    int numBodyCreated = 0;
    int numBodyDeleted = 0;
#endif

int main_unit_test(Farm* f){
    // The number of handles and bodies created are 1 lower than the number of handles and bodies deleted
    // because of the Farm* f, created for testing purposes.

    std::cout << "\n========== Testes unitarios da Classe Cattle ===========\n" << std::endl;
    run_unit_tests_cattle(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    std::cout << "\n========== Testes unitarios da Classe Transaction ===========\n" << std::endl;
    run_unit_tests_transaction(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    std::cout << "\n========== Testes unitarios da Classe User ===========\n" << std::endl;
    run_unit_tests_user(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    std::cout << "\n========== Testes unitarios da Classe Farm ===========\n" << std::endl;
    run_unit_tests_farm(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    return 0;
}
