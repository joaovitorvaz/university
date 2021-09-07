#include <iostream>
#include <cstdlib>
#include <assert.h>

#include "unit_tests.h" 
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"

using namespace std;

// Function for exponential unit test.
void exponentialUnitTest(){
    cout << "TESTE 1 - modelo simples com equacao exponencial" << endl;
    
    //Creates elements of the model
    System* pop1 = new System("Populacao 1", 100.0);
    System* pop2 = new System("Populacao 2", 0.0);
    ExponencialFlow* expFlow = new ExponencialFlow("Crescimento ilimitado", pop1, pop2);
    Model* expModel = new Model("Modelo Exponencial", 0.0);
    
    // Building the model
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    // Making assertions for the unit test before execution
    assert(pop1->getName() == "Populacao 1");
    assert(pop2->getName() == "Populacao 2");
    assert(expFlow->getName() == "Crescimento ilimitado");
    assert(expModel->getName() == "Modelo Exponencial");

    assert(abs(pop1->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);
    assert(abs(expModel->getTime() - 0.0) < 0.0001);

    // Executes the model
    expModel->execute(0, 100, 1);

    // //Making assertions for the unit test after execution
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    assert(abs(expModel->getTime() - 100.0) < 0.0001);

    delete(expModel);
    cout << "OK" << endl;
}

// Function for logistical unit test.
void logisticalUnitTest(){
    cout << "TESTE 2 - modelo simples com equacao logistica" << endl;
    
    //Creates elements of the model
    System* p1 = new System("Populacao 1", 100);
    System* p2 = new System("Populacao 2", 10);
    LogisticFlow* logFlow = new LogisticFlow("Crescimento limitado", p1, p2);
    Model* logModel = new Model("Modelo Logistico", 0.0);
    
    //Building the model
    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);

    //Making assertions for the unit test before execution
    assert(p1->getName() == "Populacao 1");
    assert(p2->getName() == "Populacao 2");    
    assert(logFlow->getName() == "Crescimento limitado");
    assert(logModel->getName() == "Modelo Logistico");

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
    cout << "OK" << endl;
}

// Function for complex unit test.
void complexUnitTest(){
    cout << "TESTE 3 - modelo complexo" << endl;
    
    //Creates elements of the model
    System* q1 = new System("Q1", 100);
    System* q2 = new System("Q2", 0);
    System* q3 = new System("Q3", 100);
    System* q4 = new System("Q4", 0);
    System* q5 = new System("Q5", 0);
    ComplexFlowF* comFlowF = new ComplexFlowF("Fluxo f", q1, q2);
    ComplexFlowT* comFlowT = new ComplexFlowT("Fluxo t", q2, q3);
    ComplexFlowU* comFlowU = new ComplexFlowU("Fluxo u", q3, q4);
    ComplexFlowV* comFlowV = new ComplexFlowV("Fluxo v", q4, q1);
    ComplexFlowG* comFlowG = new ComplexFlowG("Fluxo g", q1, q3);
    ComplexFlowR* comFlowR = new ComplexFlowR("Fluxo r", q2, q5);
    Model* comModel = new Model("Modelo Complexo", 0.0);
    
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
    assert(comFlowF->getName() == "Fluxo f");
    assert(comFlowT->getName() == "Fluxo t");
    assert(comFlowU->getName() == "Fluxo u");
    assert(comFlowV->getName() == "Fluxo v");
    assert(comFlowG->getName() == "Fluxo g");
    assert(comFlowR->getName() == "Fluxo r");
    assert(comModel->getName() == "Modelo Complexo");

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
    cout << "OK" << endl;
}