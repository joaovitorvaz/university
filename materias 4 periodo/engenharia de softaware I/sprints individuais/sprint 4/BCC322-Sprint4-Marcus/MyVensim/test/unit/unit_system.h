#ifndef UNIT_SYSTEM
#define UNIT_SYSTEM

#include "../../src/systemImpl.h"
#include "./utils/mem_usage.h"

#define RESET "\033[0m"  /* Escape sequence to reset color output to default. */
#define GREEN "\033[32m" /* Escape sequence to a green color output. */

//! Unit tests 
/**
* Creation of the unit tests for the System class.
*/
class UnitSystem{
    public:
        UnitSystem(){}
        ~UnitSystem(){}
        
        /*!
        Function prototype for the System class' copy constructor unit test.
        */
        void unit_system_copy_constructor();

        /*!
        Function prototype for the System class' assingment operator unit test.
        */
        void unit_system_assingmentOperator();
};

/*!
  Function prototype for the System class' constructor unit test.
*/
void unit_system_constructor();

/*!
  Function prototype for the System class' destructor unit test.
*/
void unit_system_destructor();

/*!
  Function prototype for the System class' method getName() unit test.
*/
void unit_system_getName();

/*!
  Function prototype for the System class' method setName() unit test.
*/
void unit_system_setName();

/*!
  Function prototype for the System class' method getValue() unit test.
*/
void unit_system_getValue();

/*!
  Function prototype for the System class' method setValue() unit test.
*/
void unit_system_setValue();

/*!
  Function prototype for the System class' "+" operator unit test.
*/
void unit_system_sumOperator();

/*!
  Function prototype for the System class' "-" operator unit test.
*/
void unit_system_minusOperator();

/*!
  Function prototype for the System class' "*" operator unit test.
*/
void unit_system_timesOperator();

/*!
  Function prototype for the System class' "/" operator unit test.
*/
void unit_system_divisionOperator();

/*!
  Function prototype for the function that runs all the unit tests of the System class.
*/
void run_unit_tests_system();

#endif