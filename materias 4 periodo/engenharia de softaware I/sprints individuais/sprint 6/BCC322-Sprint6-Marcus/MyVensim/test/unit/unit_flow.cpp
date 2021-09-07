#include <assert.h>

#include "unit_flow.h"

#include "../../src/include/systemImpl.h"

// Function for flow's constructor unit test.
void unit_flow_constructor() {
    cout << "TEST 1 - Default constructor of the Flow class without passing parameters: ";

    Flow* flow1 = new FlowHandle<ExponencialFlow>();
    
    // Making assertion to verify if the name property was initialized with the default data.
    assert(flow1->getName() == "");
    // Making assertion to verify if there isn't a source system in this flow.
    assert(flow1->getSource() == NULL);
    // Making assertion to verify if there isn't a target system in this flow.
    assert(flow1->getTarget() == NULL);

    delete flow1;
    cout << GREEN << "OK" << RESET << endl;
    cout << "TEST 2 - Default constructor of the Flow class with passing parameters: ";

    System* source = new SystemHandle("Test System 1", 5.0);
    System* target = new SystemHandle("Test System 2", 10.0);

    Flow* flow2 = new FlowHandle<ExponencialFlow>("Flow 2", source, target);
    
    // Making assertion to verify if the name property was initialized with the parameter specified.
    assert(flow2->getName() == "Flow 2");
    // Making assertion to verify if there's a source system in this flow.
    assert(flow2->getSource() == source);
    // Making assertion to verify if there's a target system in this flow.
    assert(flow2->getTarget() == target);

    delete source;
    delete target;
    delete flow2;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for FlowHandle class's copy constructor unit test.
void unit_flow_copy_constructor() { 
    cout << "TEST 3 - Copy constructor of the FlowHandle class: ";

    System* sys1 = new SystemHandle("Sys 1", 5.0);
    System* sys2 = new SystemHandle("Sys 2", 6.0);

    FlowHandle<ExponencialFlow>* flow1 = new FlowHandle<ExponencialFlow>("Flow 1");
    Flow* flow2 = new FlowHandle<ExponencialFlow>(*flow1); 

    flow1->setName("Original Flow 1");
    flow1->setSource(sys1);
    flow1->setTarget(sys2);
    
    // Making assertion to verify if the name property was copied.
    assert(flow2->getName() == "Original Flow 1");
    // Making assertion to verify if there isn't a source system in this flow.
    assert(flow2->getSource() == sys1); 
    // Making assertion to verify if there isn't a target system in this flow.
    assert(flow2->getTarget() == sys2);
    // Making assertion to verify if both handles are pointing at the same body by comparing the number of
    // handles and bodies deleted so far.
    assert(numHandleDeleted == numBodyDeleted-1);

    delete sys1;
    delete sys2;
    delete flow1;
    delete flow2;
    cout << GREEN << "OK" << RESET << endl;
} 

// Function for the Flow class' destructor unit test.
void unit_flow_destructor() {
    cout << "TEST 4 - Default destructor of the Flow class: ";

    double vmBefore, vmAfter, rss;

    // Getting the memory usage previous to the creation of a flow.
    memory_usage(vmBefore, rss);
  
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow");
    delete flow;

    // Getting the memory usage after the creation and destruction of a Flow object.
    memory_usage(vmAfter, rss);

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of Flow object.
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK" << RESET << endl;
}

// Function for Flow class' method getName() unit test.
void unit_flow_getName() {
    cout << "TEST 5 - Flow class' getName() method: ";
    
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow 1");

    // Making assertion to verify if the method returns the Flow class name and if it's
    // equal to the parameter previously passed. 
    assert(flow->getName() == "Flow 1");
    
    delete flow;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for Flow class' method setName() unit test.
void unit_flow_setName() {
    cout << "TEST 6 - Flow class' setName() method: ";

    Flow* flow = new FlowHandle<ExponencialFlow>();
    flow->setName("Test Flow");

    // Making assertion to verify if the data of the name property has been altered.
    assert(flow->getName() == "Test Flow");

    delete flow;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for Flow class' method getSource() unit test.
void unit_flow_getSource(){
    cout << "TEST 7 - Flow class' getSource() method: ";
    
    System* system = new SystemHandle("Test System");
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow 1", system);

    // Making assertion to verify if the method returns the Flow class source system and if it's
    // equal to the parameter previously passed. 
    assert(flow->getSource()->getName() == "Test System");
    
    delete system;
    delete flow;
    cout << GREEN << "OK" << RESET << endl;  
}

// Function for Flow class' method setSource() unit test.
void unit_flow_setSource(){
    cout << "TEST 8 - Flow class' setSource() method: ";
    
    System* system = new SystemHandle("Test System");
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow 1");
    flow->setSource(system);

    // Making assertion to verify if the data of the source system property has been altered.
    assert(flow->getSource()->getName() == "Test System");
    
    delete system;
    delete flow;
    cout << GREEN << "OK" << RESET << endl;  
}

// Function for Flow class' method clearSource() unit test.
void unit_flow_clearSource(){
    cout << "TEST 9 - Flow class' clearSource() method: ";
    
    System* system = new SystemHandle("Test System");
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow 1",system);
    flow->clearSource();

    // Making assertion to verify if the data of the source system property has been altered.
    assert(flow->getSource() == NULL);
    
    delete system;
    delete flow;
    cout << GREEN << "OK" << RESET << endl;  
}

// Function for Flow class' method getTarget() unit test.
void unit_flow_getTarget(){
    cout << "TEST 10 - Flow class' getTarget() method: ";
    
    System* system = new SystemHandle("Test System"); 
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow 1",NULL,system);    

    // Making assertion to verify if the method returns the Flow class target system and if it's
    // equal to the parameter previously passed. 
    assert(flow->getTarget()->getName() == "Test System");
    
    delete system;
    delete flow;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for Flow class' method setTarget() unit test.
void unit_flow_setTarget(){
    cout << "TEST 11 - Flow class' setTarget() method: ";
    
    System* system = new SystemHandle("Test System");
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow 1");
    flow->setTarget(system);

    // Making assertion to verify if the data of the target system property has been altered.
    assert(flow->getTarget()->getName() == "Test System");
    
    delete system;
    delete flow;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for Flow class' method clearTarget() unit test.
void unit_flow_clearTarget(){
    cout << "TEST 12 - Flow class' clearTarget() method: ";
    
    System* system = new SystemHandle("Test System");
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow", NULL, system); 
    flow->clearTarget();

    // Making assertion to verify if the data of the target system property has been altered.
    assert(flow->getTarget() == NULL);
    
    delete system;
    delete flow;
    cout << GREEN << "OK" << RESET << endl;  
}

//Function for FlowHandle class' assingment operator unit test.
void unit_flow_assingmentOperator(){
    cout << "TEST 13 - FlowHandle class' assignment operator: ";
    
    System* sys1 = new SystemHandle("Sys 1", 5.0);
    System* sys2 = new SystemHandle("Sys 2", 6.0);

    FlowHandle<ExponencialFlow>* flow1 = new FlowHandle<ExponencialFlow>("Flow 1");
    FlowHandle<ExponencialFlow>* flow2 = new FlowHandle<ExponencialFlow>();
    *flow2 = *flow1;
    
    flow1->setName("Original Flow 1");
    flow1->setSource(sys1);
    flow1->setTarget(sys2);
        
    // Making assertion to verify if the name property was assigned.
    assert(flow2->getName() == "Original Flow 1");
    // Making assertion to verify if the source system property was assigned.
    assert(flow2->getSource() == sys1);
    // Making assertion to verify if the target system property was assigned.
    assert(flow2->getTarget() == sys2);
    // Making assertion to verify if both handles are pointing at the same body by comparing the number of
    // handles and bodies deleted so far.
    assert(numHandleDeleted == numBodyDeleted-1);
    
    delete sys1;
    delete sys2;
    delete flow1;
    delete flow2;
    cout << GREEN << "OK" << RESET << endl;
}

// Function for Flow class' execute method unit test.
void unit_flow_execute(){
    cout << "TEST 14 - Flow class' execute() method: ";
    
    System* system1 = new SystemHandle("Test System 1", 10.0);
    System* system2 = new SystemHandle("Test System 2", 0.0);
    Flow* flow = new FlowHandle<ExponencialFlow>("Flow", system1, system2);
    system2->setValue(flow->execute());
    
    // Making assertion to verify if the execute method has been completed successfully.
    assert(abs(flow->getTarget()->getValue() - 0.1) < 0.01);
    
    delete system1;
    delete system2;
    delete flow;
    cout << GREEN << "OK" << RESET << endl;
}

// Function to run all the Flow class' unit tests.
void run_unit_tests_flow() {

    // Calling all the Flow class' unit test functions.
    unit_flow_constructor();  
    unit_flow_copy_constructor();
    unit_flow_destructor(); 
    unit_flow_getName();
    unit_flow_setName();
    unit_flow_getSource();
    unit_flow_setSource();
    unit_flow_clearSource();
    unit_flow_getTarget();
    unit_flow_setTarget();
    unit_flow_clearTarget();
    unit_flow_assingmentOperator();
    unit_flow_execute();

}