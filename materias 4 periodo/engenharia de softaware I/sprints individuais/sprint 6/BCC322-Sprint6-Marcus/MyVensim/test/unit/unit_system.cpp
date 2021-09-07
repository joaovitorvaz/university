#include <assert.h>

#include "unit_system.h"

#include "../../src/include/systemImpl.h"

using namespace std;

// Function for System class's constructor unit test.
void unit_system_constructor(){
    cout << "TEST 1 - Default constructor of the System class without passing parameters: ";
    
    System* system1 = new SystemHandle();
    // Making assertion to verify if the name property was initialized with the default data.
    assert(system1->getName() == "");
    // Making assertion to verify if the value property was initialized with the default data. 
    assert(system1->getValue() == 0.0);

    delete system1;
    cout << GREEN << "OK" << RESET << endl;

    cout << "TEST 2 - Default constructor of the System class with passing parameters: "; 
    
    System* system2 = new SystemHandle("Test System", 10.0);
    // Making assertion to verify if the name property was initialized with the parameter specified.
    assert(system2->getName() == "Test System");
    // Making assertion to verify if the value property was initialized with the parameter specified. 
    assert(system2->getValue() == 10.0);

    delete system2;
    cout << GREEN << "OK"<< RESET << endl;
}

// Function for SystemHandle class's copy constructor unit test.
void unit_system_copy_constructor(){
    cout << "TEST 3 - Copy constructor of the SystemHandle class: ";
    
    SystemHandle* system1 = new SystemHandle("Test System", 10.0);
    System* system2 = new SystemHandle(*system1);
    system1->setName("Original Test System");
    system1->setValue(100.0);

    // Making assertion to verify if the name property was copied.
    assert(system2->getName() == "Original Test System");
    // Making assertion to verify if the value property was copied.
    assert(system2->getValue() == 100.0);
    // Making assertion to verify if both handles are pointing at the same body by comparing the number of
    // handles and bodies deleted so far.
    assert(numHandleDeleted == numBodyDeleted-1);

    delete system1;
    delete system2;

    cout << GREEN << "OK" << RESET << endl;
}

// Function for the System class' destructor unit test.
void unit_system_destructor(){
    cout << "TEST 4 - Default destructor of the System class: ";
    
    double vmBefore, vmAfter, rss;

    // Getting the memory usage previous to the creation of a system.
    memory_usage(vmBefore, rss);
    
    System* system = new SystemHandle("Test System", 10.0);
    delete system;

    // Getting the memory usage after the creation and destruction of a System object.
    memory_usage(vmAfter, rss);

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of System object.
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' method getName() unit test.
void unit_system_getName(){
    cout << "TEST 5 - System class's getName() method: ";
    
    System* system = new SystemHandle("Test System", 10.0);

    // Making assertion to verify if the method returns the System class name and if it's
    // equal to the parameter previously passed. 
    assert(system->getName() == "Test System");

    delete system;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' method setName() unit test.
void unit_system_setName(){
    cout << "TEST 6 - System class's setName() method: ";
    
    System* system = new SystemHandle("Test System", 10.0);
    system->setName("Altered Name");

    // Making assertion to verify if the data of the name property has been altered.
    assert(system->getName() == "Altered Name");

    delete system;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' method getValue() unit test.
void unit_system_getValue(){
    cout << "TEST 7 - System class's getValue() method: ";

    System* system = new SystemHandle("Test System", 10.0);

    // Making assertion to verify if the method returns the System class value and if it's
    // equal to the parameter previously passed.
    assert(system->getValue() == 10.0);

    delete system;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' method setValue() unit test.
void unit_system_setValue(){
    cout << "TEST 8 - System class's setValue() method: ";

    System* system = new SystemHandle("Test System", 10.0);
    system->setValue(20.0);
    
    // Making assertion to verify if the data of the value property has been altered.
    assert(system->getValue() == 20.0);

    delete system;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for SystemHandle class' assingment operator unit test.
void unit_system_assingmentOperator(){
    cout << "TEST 9 - SystemHandle class assignment operator: ";
    
    SystemHandle* system1 = new SystemHandle("Test System", 10.0);
    SystemHandle* system2 = new SystemHandle();
    *system2 = *system1;

    system1->setName("Original Test System");
    system1->setValue(100.0);

    // Making assertion to verify if the name property was assigned.
    assert(system2->getName() == "Original Test System");
    // Making assertion to verify if the value property was assigned.
    assert(system2->getValue() == 100.0);
    // Making assertion to verify if both handles are pointing at the same body by comparing the number of
    // handles and bodies deleted so far.
    assert(numHandleDeleted == numBodyDeleted-1);

    delete system1;
    delete system2;

    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "+" operator unit test.
void unit_system_sumOperator(){
    System* sys1 = new SystemHandle("Population 1", 100.0);
    System* sys2 = new SystemHandle("Population 2", 10.0);

    cout << "TEST 10 - System class sum operator: ";
    assert(((*sys1) + (*sys2)) == 110);
    assert(((*sys1) + 20.0) == 120);

    delete sys1;
    delete sys2;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "-" operator unit test.
void unit_system_minusOperator(){
    System* sys1 = new SystemHandle("Population 1", 100.0);
    System* sys2 = new SystemHandle("Population 2", 10.0);

    cout << "TEST 11 - System class subtraction operator: ";
    assert(((*sys1) - (*sys2)) == 90);
    assert(((*sys1) - 20.0) == 80);

    delete sys1;
    delete sys2;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "*" operator unit test.
void unit_system_timesOperator(){
    System* sys1 = new SystemHandle("Population 1", 100.0);
    System* sys2 = new SystemHandle("Population 2", 10.0);

    cout << "TEST 12 - System class multiplication operator: ";
    assert(((*sys1) * (*sys2)) == 1000);
    assert(((*sys1) * 20.0) == 2000);

    delete sys1;
    delete sys2;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for System class' "/" operator unit test.
void unit_system_divisionOperator(){
    System* sys1 = new SystemHandle("Population 1", 100.0);
    System* sys2 = new SystemHandle("Population 2", 10.0);

    cout << "TEST 13 - System class division operator: ";
    assert(((*sys1) / (*sys2)) == 10);
    assert(((*sys1) / 20.0) == 5);

    delete sys1;
    delete sys2;
    cout << GREEN << "OK" << RESET << endl;
}

// Function to run all the System class' unit tests.
void run_unit_tests_system(){

    // Calling all the System class' unit test functions.
    unit_system_constructor();
    unit_system_copy_constructor();
    unit_system_destructor();
    unit_system_getName();
    unit_system_setName();
    unit_system_getValue();
    unit_system_setValue();
    unit_system_assingmentOperator();
    unit_system_sumOperator();
    unit_system_minusOperator();
    unit_system_timesOperator();
    unit_system_divisionOperator();

}