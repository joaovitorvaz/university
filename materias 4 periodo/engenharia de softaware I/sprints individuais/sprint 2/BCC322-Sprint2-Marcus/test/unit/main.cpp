#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_tests.h"

#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

int main(){

    exponentialUnitTest();
    logisticalUnitTest();
    complexUnitTest();

    return 0;
}

#endif