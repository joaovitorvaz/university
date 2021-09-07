/*!
 \file unit_transaction.h
 \brief This file contains the unit tests of the Transaction class for the GiroDeGado software.
*/

#ifndef UNIT_TRANSACTION
#define UNIT_TRANSACTION

#ifndef __unix__
#include <windows.h>
#endif

#include <assert.h>
#include <math.h>
#include "../../includes/transactionImpl.h"
#include "../../includes/farm.h"

//! Unit tests 
/**
* Creation of the unit tests for the Transaction class.
*/

/*!
  Function prototype for the Transaction class' constructor unit test.
*/
void unit_transaction_constructor();

/*!
  Function prototype for the TransactionHandle class' copy constructor unit test.
*/
void unit_transaction_copy_constructor();

/*!
  Function prototype for the Transaction class' destructor unit test.
*/
void unit_transaction_destructor();

/*!
  Function prototype for the Transaction class' method getNumber() unit test.
*/
void unit_transaction_getNumber(Farm* f);

/*!
  Function prototype for the Transaction class' method setNumber() unit test.
*/
void unit_transaction_setNumber(Farm* f);

/*!
  Function prototype for the Transaction class' method getValue() unit test.
*/
void unit_transaction_getValue(Farm* f);

/*!
  Function prototype for the Transaction class' method setValue() unit test.
*/
void unit_transaction_setValue(Farm* f);

/*!
  Function prototype for the Transaction class' method getDescription() unit test.
*/
void unit_transaction_getDescription(Farm* f);

/*!
  Function prototype for the Transaction class' method setDescription() unit test.
*/
void unit_transaction_setDescription(Farm* f);

/*!
  Function prototype for the Transaction class' method getDate() unit test.
*/
void unit_transaction_getDate(Farm* f);

/*!
  Function prototype for the Transaction class' method setDate() unit test.
*/
void unit_transaction_setDate(Farm* f);

/*!
  Function prototype for the Transaction class' method getCattleEarring() unit test.
*/
void unit_transaction_getCattleEarring(Farm* f);

/*!
  Function prototype for the Transaction class' method setCattleEarring() unit test.
*/
void unit_transaction_setCattleEarring(Farm* f);

/*!
  Function prototype for the TransactionHandle class' assingment operator unit test.
*/
void unit_transaction_assingmentOperator();

/*!
  Function prototype for the function that runs all the unit tests of the Transaction class.
*/
void run_unit_tests_transaction(Farm* f);

#endif
