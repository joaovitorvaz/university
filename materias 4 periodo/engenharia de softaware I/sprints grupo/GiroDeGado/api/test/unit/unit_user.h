/*!
 \file unit_user.h
 \brief This file contains the unit tests of the User class for the GiroDeGado software.
*/

#ifndef UNIT_USER
#define UNIT_USER

#ifndef __unix__
#include <windows.h>
#endif

#include <assert.h>
#include <math.h>
#include "../../includes/userImpl.h"
#include "../../includes/farm.h"

//! Unit tests 
/**
* Creation of the unit tests for the User class.
*/

/*!
  Function prototype for the User class' constructor unit test.
*/
void unit_user_constructor();

/*!
  Function prototype for the UserHandle class' copy constructor unit test.
*/
void unit_user_copy_constructor();

/*!
  Function prototype for the User class' destructor unit test.
*/
void unit_user_destructor();

/*!
  Function prototype for the User class' method getNickname() unit test.
*/
void unit_user_getNickname(Farm* f);

/*!
  Function prototype for the User class' method setNickname() unit test.
*/
void unit_user_setNickname(Farm* f);

/*!
  Function prototype for the User class' method getName() unit test.
*/
void unit_user_getName(Farm* f);

/*!
  Function prototype for the User class' method setName() unit test.
*/
void unit_user_setName(Farm* f);

/*!
  Function prototype for the User class' method getPassword() unit test.
*/
void unit_user_getPassword(Farm* f);

/*!
  Function prototype for the User class' method setPassword() unit test.
*/
void unit_user_setPassword(Farm* f);

/*!
  Function prototype for the User class' method getDate() unit test.
*/
void unit_user_getDate(Farm* f);

/*!
  Function prototype for the User class' method setDate() unit test.
*/
void unit_user_setDate(Farm* f);

/*!
  Function prototype for the User class' method getType() unit test.
*/
void unit_user_getType(Farm* f);

/*!
  Function prototype for the User class' method setType() unit test.
*/
void unit_user_setType(Farm* f);

/*!
  Function prototype for the UserHandle class' assingment operator unit test.
*/
void unit_user_assingmentOperator();

/*!
  Function prototype for the function that runs all the unit tests of the User class.
*/
void run_unit_tests_user(Farm* f);

#endif
