#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include <assert.h>
#include "./unit_system.h"
#include "./unit_flow.h"
#include "./unit_model.h"
#include "./unit_tests.h"

#define DEBUGING
#ifdef DEBUGING
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;
#endif

int main(){

    cout << "\nTestes unitarios de System." << endl;
    run_unit_tests_system();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);
    
    cout << "\nTestes unitarios de Flow." << endl;
    run_unit_tests_flow();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    cout << "\nTestes unitarios de Model."<< endl;
    run_unit_tests_model();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    cout << "\nTestes unitarios das Funcoes Globais."<< endl;
    run_unit_tests_globals();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    return 0;
}

#endif