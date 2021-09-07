#include <assert.h>

#include "unit_tests.h"

#include "../../src/include/systemImpl.h"

using namespace std;

// Function for System class' "+" global operator unit test.
void unit_test_global_sumOperator(){
    System* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 1 - System class sum global operator: ";
    assert((20.0 + (*sys)) == 30);

    delete sys;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "-" global operator unit test.
void unit_test_global_minusOperator(){
    System* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 2 - System class subtraction global operator: ";
    assert((20.0 - (*sys)) == 10);

    delete sys;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "*" global operator unit test.
void unit_test_global_timesOperator(){
    System* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 3 - System class multiplication global operator: ";
    assert((20.0 * (*sys)) == 200);

    delete sys;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "/" global operator unit test.
void unit_test_global_divisionOperator(){
    System* sys = new SystemHandle("Population", 10.0);

    cout << "TEST 4 - System class division global operator: ";
    assert((20.0 / (*sys)) == 2);

    delete sys;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "/" global operator unit test.
void unit_test_handlebody(){
    cout << "TEST 5 - HandleBody: " << endl << endl;   

    {
        SystemHandle sys1 ("Population 1", 10.0);
        SystemHandle sys2 ("Population 2", 10.0);

        sys1 = sys2;

        cout << "Created handles: "  << numHandleCreated << endl;
        cout << "Deleted handles: "  << numHandleDeleted << endl;
        cout << "Created bodies: "  << numBodyCreated << endl;
        cout << "Deleted bodies: "  << numBodyDeleted << endl;

        assert(numHandleCreated == numHandleDeleted+2); 
        assert(numBodyCreated == numBodyDeleted+1);
    }

    cout << endl << GREEN << "OK" << RESET << endl;
}

// Function to run all the global unit tests.
void run_unit_tests_globals(){
    unit_test_global_sumOperator();
    unit_test_global_minusOperator();
    unit_test_global_timesOperator();
    unit_test_global_divisionOperator();
    unit_test_handlebody();
}