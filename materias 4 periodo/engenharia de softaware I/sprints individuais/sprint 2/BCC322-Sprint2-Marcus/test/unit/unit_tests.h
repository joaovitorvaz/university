#ifndef UNIT_TEST
#define UNIT_TEST

#include <iostream>
#include "../../src/system.h"
#include "../../src/flow.h"

using namespace std;

//! Unit tests
/**
* Implementation of the unit tests for the Flow, System and Model classes.
*/

/*!
  Function prototype for exponential flow unit test.
*/
void exponentialUnitTest();

/*!
  Function prototype for logistical flow unit test.
*/
void logisticalUnitTest();

/*!
  Function prototype for the complex flows unit tests.
*/
void complexUnitTest();

//! Class ExponencialFlow
/**
* This Class represents a flow with limitless growth, and is used in the Exponencial Model test.
*/
class ExponencialFlow : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ExponencialFlow Class.
            \param name the name of the ExponencialFlow Class.
            \param source a pointer to the source system of the ExponencialFlow Class.
            \param target a pointer to the target system of the ExponencialFlow Class.
        */
        ExponencialFlow(string name, System* source, System* target): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the exponencial model.                        
        */
        virtual double execute(){
            return (0.01 * getSource()->getValue());
        }
};

//! Class LogisticFlow
/**
* This Class represents a flow with limited growth, and is used in the Logistic Model test.
*/
class LogisticFlow : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the LogisticFlow Class.
            \param name the name of the LogisticFlow Class.
            \param source a pointer to the source system of the LogisticFlow Class.
            \param target a pointer to the target system of the LogisticFlow Class.
        */
        LogisticFlow(string name, System* source, System* target): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the logistic model.                        
        */
        virtual double execute(){
            return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / 70);
        }
};

//! Class ComplexFlowF
/**
* This Class represents a flow with limitless growth, and is used in the Complex Model test.
*/
class ComplexFlowF : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ComplexFlowF Class.
            \param name the name of the ComplexFlowF Class.
            \param source a pointer to the source system of the ComplexFlowF Class.
            \param target a pointer to the target system of the ComplexFlowF Class.
        */
        ComplexFlowF(string name, System* source, System* target): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the complex model.                        
        */
        virtual double execute(){
            return 0.01 * getSource()->getValue();
        }
};

//! Class ComplexFlowT
/**
*  This Class represents a flow with limitless growth, and is used in the Complex Model test.
*/
class ComplexFlowT : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ComplexFlowT Class.
            \param name the name of the ComplexFlowT Class.
            \param source a pointer to the source system of the ComplexFlowT Class.
            \param target a pointer to the target system of the ComplexFlowT Class.
        */
        ComplexFlowT(string name, System* source, System* target): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the complex model.                        
        */
        virtual double execute(){
            return 0.01 * getSource()->getValue();
        }
};

//! Class ComplexFlowU
/**
* This Class represents a flow with limitless growth, and is used in the Complex Model test.
*/
class ComplexFlowU : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ComplexFlowU Class.
            \param name the name of the ComplexFlowU Class.
            \param source a pointer to the source system of the ComplexFlowU Class.
            \param target a pointer to the target system of the ComplexFlowU Class.
        */
        ComplexFlowU(string name, System* source, System* target): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the complex model.                        
        */
        virtual double execute(){
            return 0.01 * getSource()->getValue();
        }
};

//! Class ComplexFlowV
/**
* This Class represents a flow with limitless growth, and is used in the Complex Model test.
*/
class ComplexFlowV : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ComplexFlowV Class.
            \param name the name of the ComplexFlowV Class.
            \param source a pointer to the source system of the ComplexFlowV Class.
            \param target a pointer to the target system of the ComplexFlowV Class.
        */
        ComplexFlowV(string name, System* source, System* target): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the complex model.                        
        */
        virtual double execute(){
            return 0.01 * getSource()->getValue();
        }
};

//! Class ComplexFlowG
/**
* This Class represents a flow with limitless growth, and is used in the Complex Model test.
*/
class ComplexFlowG : public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ComplexFlowG Class.
            \param name the name of the ComplexFlowG Class.
            \param source a pointer to the source system of the ComplexFlowG Class.
            \param target a pointer to the target system of the ComplexFlowG Class.
        */
        ComplexFlowG(string name, System* source, System* target): Flow(name, source, target){}
        
        /*!
            A method created by the user, that contains an equation that will be executed by the complex model.                        
        */
        virtual double execute(){
            return 0.01 * getSource()->getValue();
        }
};

//! Class ComplexFlowR
/**
* This Class represents a flow with limitless growth, and is used in the Complex Model test.
*/     
class ComplexFlowR: public Flow{
    public:
        /*!
            This is a more elaborated constructor for the ComplexFlowR Class.
            \param name the name of the ComplexFlowR Class.
            \param source a pointer to the source system of the ComplexFlowR Class.
            \param target a pointer to the target system of the ComplexFlowR Class.
        */
        ComplexFlowR(string name, System* source, System* target): Flow(name, source, target){}

        /*!
            A method created by the user, that contains an equation that will be executed by the complex model.                        
        */
        virtual double execute(){
            return 0.01 * getSource()->getValue();
        }
};

#endif