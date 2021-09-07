#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include <assert.h>
#include "funcional_tests.h"

#define DEBUGING
#ifdef DEBUGING
int numHandleCreated = 0;
int numHandleDeleted = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;
#endif

int main(){
    cout << "\nTeste funcional exponencial." << endl;
    exponentialFuncionalTest();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    cout << "\nTeste funcional logistico." << endl;
    logisticalFuncionalTest();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    cout << "\nTeste funcional complexo." << endl;
    complexFuncionalTest();
    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);

    return 0;
}

#endif