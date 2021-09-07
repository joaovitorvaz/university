#include <assert.h>

#include "funcional_tests.h" 

using namespace std;

// Function for exponential functional test.
void exponentialFuncionalTest(){
    cout << "TEST 1 - Simple model with exponential equation" << endl;

    //Creates elements of the model
    System* pop1 = new SystemImpl("Population 1", 100);
    System* pop2 = new SystemImpl("Population 2", 0);
    ExponencialFlow* expFlow = new ExponencialFlow("Unlimited Growth", pop1, pop2);
    Model* expModel = new ModelImpl("Exponential Model", 0.0);
    
    //Building the model
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    //Making assertions for the unit test before execution
    assert(pop1->getName() == "Population 1");
    assert(pop2->getName() == "Population 2");
    assert(expFlow->getName() == "Unlimited Growth");
    assert(expModel->getName() == "Exponential Model");

    assert(abs(pop1->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);
    assert(abs(expModel->getTime() - 0.0) < 0.0001);

    //Executes the model
    expModel->execute(0, 100, 1);

    //Making assertions for the unit test after execution
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    assert(abs(expModel->getTime() - 100.0) < 0.0001);

    delete (expModel);
    cout << GREEN << "OK!"<< RESET << endl;
}

// Function for logistical functional test.
void logisticalFuncionalTest(){
    cout << "TEST 2 - Simple model with logistic equation" << endl;
    
    //Creates elements of the model
    System* p1 = new SystemImpl("Population 1", 100);
    System* p2 = new SystemImpl("Population 2", 10);
    LogisticFlow* logFlow = new LogisticFlow("Limited Growth", p1, p2);
    Model* logModel = new ModelImpl("Logistic Model", 0.0);
    
    //Building the model
    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);

    //Making assertions for the unit test before execution
    assert(p1->getName() == "Population 1");
    assert(p2->getName() == "Population 2");    
    assert(logFlow->getName() == "Limited Growth");
    assert(logModel->getName() == "Logistic Model");

    assert(abs(p1->getValue() - 100.0) < 0.0001);
    assert(abs(p2->getValue() - 10.0) < 0.0001);
    assert(abs(logModel->getTime() - 0.0) < 0.0001);   

    //Executes the model
    logModel->execute(0, 100, 1);

    //Making assertions for the unit test after execution
    assert(abs(p1->getValue() - 88.2167) < 0.0001);
    assert(abs(p2->getValue() - 21.7833) < 0.0001);
    assert(abs(logModel->getTime() - 100.0) < 0.0001); 

    delete(logModel);
    cout << GREEN << "OK!"<< RESET << endl;
}

// Function for complex functional test.
void complexFuncionalTest(){
    cout << "TEST 3 - Complex model" << endl;
    
    //Creates elements of the model
    System* q1 = new SystemImpl("Q1", 100);
    System* q2 = new SystemImpl("Q2", 0);
    System* q3 = new SystemImpl("Q3", 100);
    System* q4 = new SystemImpl("Q4", 0);
    System* q5 = new SystemImpl("Q5", 0);
    ComplexFlowF* comFlowF = new ComplexFlowF("Flow f", q1, q2);
    ComplexFlowT* comFlowT = new ComplexFlowT("Flow t", q2, q3);
    ComplexFlowU* comFlowU = new ComplexFlowU("Flow u", q3, q4);
    ComplexFlowV* comFlowV = new ComplexFlowV("Flow v", q4, q1);
    ComplexFlowG* comFlowG = new ComplexFlowG("Flow g", q1, q3);
    ComplexFlowR* comFlowR = new ComplexFlowR("Flow r", q2, q5);
    Model* comModel = new ModelImpl("Complex Model", 0.0);
    
    //Building the model
    comModel->add(q1);
    comModel->add(q2);
    comModel->add(q3);
    comModel->add(q4);
    comModel->add(q5);
    comModel->add(comFlowF);
    comModel->add(comFlowT);
    comModel->add(comFlowU);
    comModel->add(comFlowV);
    comModel->add(comFlowG);
    comModel->add(comFlowR);

    //Making assertions for the unit test before execution
    assert(q1->getName() == "Q1");
    assert(q2->getName() == "Q2");
    assert(q3->getName() == "Q3");
    assert(q4->getName() == "Q4");
    assert(q5->getName() == "Q5");
    assert(comFlowF->getName() == "Flow f");
    assert(comFlowT->getName() == "Flow t");
    assert(comFlowU->getName() == "Flow u");
    assert(comFlowV->getName() == "Flow v");
    assert(comFlowG->getName() == "Flow g");
    assert(comFlowR->getName() == "Flow r");
    assert(comModel->getName() == "Complex Model");

    assert(abs(q1->getValue() - 100.0) < 0.0001);
    assert(abs(q2->getValue() - 0.0) < 0.0001);
    assert(abs(q3->getValue() - 100.0) < 0.0001);
    assert(abs(q4->getValue() - 0.0) < 0.0001);
    assert(abs(q5->getValue() - 0.0) < 0.0001);
    assert(abs(comModel->getTime() - 0.0) < 0.0001);

    //Executes the model
    comModel->execute(0, 100, 1);

    //Making assertions for the unit test after execution
    assert(abs(q1->getValue() - 31.8513) < 0.0001);
    assert(abs(q2->getValue() - 18.4003) < 0.0001);
    assert(abs(q3->getValue() - 77.1143) < 0.0001);
    assert(abs(q4->getValue() - 56.1728) < 0.0001);
    assert(abs(q5->getValue() - 16.4612) < 0.0001);
    assert(abs(comModel->getTime() - 100.0) < 0.0001);

    delete(comModel);
    cout << GREEN << "OK!"<< RESET << endl;
}