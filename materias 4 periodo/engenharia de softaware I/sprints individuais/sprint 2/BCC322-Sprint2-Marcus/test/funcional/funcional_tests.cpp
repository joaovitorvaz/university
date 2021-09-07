#include <iostream>

#include "funcional_tests.h" 
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"

using namespace std;

// Function for exponential functional test.
void exponentialFuncionalTest(){
    cout << "TESTE 4 - modelo simples com equacao exponencial" << endl;

    //Creates elements of the model
    System* pop1 = new System("Populacao 1", 100);
    System* pop2 = new System("Populacao 2", 0);
    ExponencialFlow* expFlow = new ExponencialFlow("Crescimento ilimitado", pop1, pop2);
    Model* expModel = new Model("Modelo Exponencial", 0.0);
    
    //Building the model
    expModel->add(pop1);
    expModel->add(pop2);
    expModel->add(expFlow);

    //Executes the model
    expModel->execute(0, 100, 1);

    delete (expModel);
    cout << "OK" << endl;
}

// Function for logistical functional test.
void logisticalFuncionalTest(){
    cout << "TESTE 5 - modelo simples com equacao logistica" << endl;
    
    //Creates elements of the model
    System* p1 = new System("Populacao 1", 100);
    System* p2 = new System("Populacao 2", 10);
    LogisticFlow* logFlow = new LogisticFlow("Crescimento limitado", p1, p2);
    Model* logModel = new Model("Modelo Logistico", 0.0);
    
    //Building the model
    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);

    //Executes the model
    logModel->execute(0, 100, 1);

    delete(logModel);
    cout << "OK" << endl;
}

// Function for complex functional test.
void complexFuncionalTest(){
    cout << "TESTE 6 - modelo complexo" << endl;
    
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

    //Executes the model
    comModel->execute(0, 100, 1);

    delete(comModel);
    cout << "OK" << endl;
}