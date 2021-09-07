#include <assert.h>

#include "unit_model.h"

#include "../../src/include/systemImpl.h"

using namespace std;

// Function for Model class's constructor unit test.
void unit_model_constructor(){
    cout << "TEST 1 - Default constructor of the Model class without passing parameters" << endl;

    Model* model1 = Model::createModel();

    // Making assertion to verify if the name property was initialized with the default data.
    assert(model1->getName() == "");
    // Making assertion to verify if the time property was initialized with the default data.
    assert(model1->getTime() == 0.0);

    cout << GREEN << "OK!" << RESET << endl;
    cout << "TEST 2 - Default constructor of the Model class with passing parameters" << endl;

    Model* model2 = Model::createModel("Test Model", 1.0);
    System* sys1 = model2->createSystem("System 1", 0.0);
    System* sys2 = model2->createSystem("System 2", 0.0);

    vector<System*> systems;
    systems.push_back(sys1);
    systems.push_back(sys2);
    
    Flow* flow = model2->createFlow<ExponencialFlow>("Test Flow", sys1, sys2);

    vector<Flow*> flows;
    flows.push_back(flow);
    
    // Making assertion to verify if the name property was initialized with the parameter specified.
    assert(model2->getName() == "Test Model");
    // Making assertion to verify if the time property was initialized with the parameter specified.
    assert(model2->getTime() == 1.0);
    // Making assertion to verify if the Flow object was added to the Model's flows parameter.
    assert((*(model2->beginFlows()))->getName() == "Test Flow");    
   
    int counter = 0;    
    for (auto sys = model2->beginSystems(); sys != model2->endSystems(); ++sys){
        // Making assertion to verify if the systems were added to the systems property.
        assert((*sys)->getName() == systems[counter]->getName());
        counter++;
    }

    counter = 0;    
    for (auto fl = model2->beginFlows(); fl != model2->endFlows(); ++fl){
        // Making assertion to verify if the flows were added to the flows property.
        assert((*fl)->getName() == flows[counter]->getName());
        counter++;
    }

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' destructor unit test.
void unit_model_destructor(){
    cout << "TEST 3 - Default destructor of the Model class" << endl;
    
    double vmBefore, vmAfter, rss;

    // Getting the memory usage previous to the creation of a model.
    memory_usage(vmBefore, rss);
    
    Model* model = Model::createModel("Exponential Model", 0.0);
    System* sys1 = model->createSystem("System 1", 0.0);
    System* sys2 = model->createSystem("System 2", 0.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Unlimited Growth", sys1, sys2);

    delete model;

    // Getting the memory usage after the creation and destruction of a Flow object.
    memory_usage(vmAfter, rss);

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of Model object.
    assert(vmBefore == vmAfter);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getName() method unit test.
void unit_model_getName(){
    cout << "TEST 4 - Model class' getName() method" << endl;
    
    Model* model = Model::createModel("Test Model", 0.0);
    
    // Making assertion to verify if the method returns the Model class name and if it's
    // equal to the parameter previously passed.
    assert(model->getName() == "Test Model");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setName() method unit test.
void unit_model_setName(){
    cout << "TEST 5 - Model class' setName() method" << endl;

    Model* model = Model::createModel("Test", 0.0);
    model->setName("Test Model");
    
    // Making assertion to verify if the data of the name property has been altered.
    assert(model->getName() == "Test Model");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getTime() method unit test.
void unit_model_getTime(){
    cout << "TEST 6 - Model class' getTime() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);

    // Making assertion to verify if the method returns the Model class time and if it's
    // equal to the parameter previously passed.
    assert(model->getTime() == 1.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setTime() method unit test.
void unit_model_setTime(){
    cout << "TEST 7 - Model class' setTime() method" << endl;

    Model* model = Model::createModel("Test Model", 0.0);
    model->setTime(1.0);

    // Making assertion to verify if the data of the time property has been altered.
    assert(model->getTime() == 1.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' incrementTime() method unit test.
void unit_model_incrementTime(){
    cout << "TEST 8 - Model class' incrementTime() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    model->incrementTime(1.0);
    
    // Making assertion to verify if the data of the time property has been incremented.
    assert(model->getTime() == 2.0);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' addSystem() method unit test.
void UnitModel::unit_model_addSystem(){
    cout << "TEST 9 - Model class' addSystem() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = new SystemImpl("System 1", 0.0);

    model->add(system);

    // Making assertion to verify if the system has been added to the systems property.
    assert((*(model->beginSystems()))->getName() == system->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' removeSystem() method unit test.
void unit_model_removeSystem(){
    cout << "TEST 10 - Model class' removeSystem() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = model->createSystem("System 1", 0.0);

    model->remove(system);
    
    // Making assertion to verify if the system has been removed from the systems property.
    assert(model->beginSystems() == model->endSystems());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' addFlow() method unit test.
void UnitModel::unit_model_addFlow(){
    cout << "TEST 11 - Model class' addFlow() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    ExponencialFlow* flow = new ExponencialFlow("Flow 1");

    model->add(flow);
    
    // Making assertion to verify if the flow has been added to the flows property.
    assert((*(model->beginFlows()))->getName() == flow->getName());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' removeFlow() method unit test.
void unit_model_removeFlow(){
    cout << "TEST 12 - Model class' removeFlow() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Test Flow");
    
    model->remove(flow);

    // Making assertion to verify if the system has been removed from the systems property.
    assert(model->beginFlows() == model->endFlows());

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getSource() method unit test.
void unit_model_getSource(){
    cout << "TEST 13 - Model class' getSource() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = model->createSystem("Test System", 0.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Test Flow", system);

    // Making assertion to verify if the method returns the added flow's source system and if it's
    // equal to the parameter previously passed. 
    assert(model->getSource(flow)->getName() == "Test System");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setSource() method unit test.
void unit_model_setSource(){
    cout << "TEST 14 - Model class' setSource() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = model->createSystem("Test System", 0.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Test Flow");
    model->setSource(flow, system);

    // Making assertion to verify if the data of the added flow's source system has been altered.
    assert(model->getSource(flow)->getName() == "Test System");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' clearSource() method unit test.
void unit_model_clearSource(){
    cout << "TEST 15 - Model class' clearSource() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = model->createSystem("Test System", 0.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Test Flow", system);
    model->clearSource(flow);

    // Making assertion to verify if the data of the added flow's source system has been altered.
    assert(model->getSource(flow) == NULL);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' getTarget() method unit test.
void unit_model_getTarget(){
    cout << "TEST 16 - Model class' getTarget() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = model->createSystem("Test System", 0.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Test Flow", NULL, system);

    // Making assertion to verify if the method returns the added flow's target system and if it's
    // equal to the parameter previously passed. 
    assert(model->getTarget(flow)->getName() == "Test System");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' setTarget() method unit test.
void unit_model_setTarget(){
    cout << "TEST 17 - Model class' setTarget() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = model->createSystem("Test System", 0.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Test Flow");
    model->setTarget(flow, system);

    // Making assertion to verify if the data of the added flow's target system has been altered.
    assert(model->getTarget(flow)->getName() == "Test System");

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' clearTarget() method unit test.
void unit_model_clearTarget(){
    cout << "TEST 18 - Model class' clearTarget() method" << endl;

    Model* model = Model::createModel("Test Model", 1.0);
    System* system = model->createSystem("Test System", 0.0);
    Flow* flow = model->createFlow<ExponencialFlow>("Test Flow", NULL, system);
    model->clearTarget(flow);

    // Making assertion to verify if the data of the added flow's target system has been altered.
    assert(model->getTarget(flow) == NULL);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function for the Model class' execute() method unit test.
void unit_model_execute(){
    cout << "TEST 19 - Model class' execute() method" << endl;
    
    Model* expModel = Model::createModel("Exponential Model", 0.0);
    System* pop1 = expModel->createSystem("Population 1", 100.0);
    System* pop2 = expModel->createSystem("Population 2", 0.0);
    Flow* expFlow = expModel->createFlow<ExponencialFlow>("Unlimited Growth", pop1, pop2);

    // Making assertions for the unit test before execution
    assert(pop1->getName() == "Population 1");
    assert(pop2->getName() == "Population 2");
    assert(expFlow->getName() == "Unlimited Growth");
    assert(expModel->getName() == "Exponential Model");

    assert(abs(pop1->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);
    assert(abs(expModel->getTime() - 0.0) < 0.0001);

    expModel->execute(0, 100, 1);

    // Making assertions for the unit test after execution
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    assert(abs(expModel->getTime() - 100.0) < 0.0001);

    cout << GREEN << "OK!" << RESET << endl;
}

// Function to run all the Model class' unit tests.
void run_unit_tests_model(){
    UnitModel* unit_model = new UnitModel();
    
    // Calling all the Model class' unit test functions.
    unit_model_constructor();
    unit_model_destructor();
    unit_model_getName();
    unit_model_setName();
    unit_model_getTime();
    unit_model_setTime();
    unit_model_incrementTime();
    unit_model->unit_model_addSystem();
    unit_model_removeSystem();
    unit_model->unit_model_addFlow();
    unit_model_removeFlow();
    unit_model_getSource();
    unit_model_setSource();
    unit_model_clearSource();
    unit_model_getTarget();
    unit_model_setTarget();
    unit_model_clearTarget();
    unit_model_execute();
}