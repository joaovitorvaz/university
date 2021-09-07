/*!
 \file unit_cattle.h
 \brief This file contains the unit tests of the Cattle class for the GiroDeGado software.
*/

#ifndef UNIT_CATTLE
#define UNIT_CATTLE

#ifndef __unix__
#include <windows.h>
#endif

#include <assert.h>
#include <math.h>
#include "../../includes/cattleImpl.h"
#include "../../includes/farm.h"

//! Unit tests 
/**
* Creation of the unit tests for the Cattle class.
*/

/*!
  Function prototype for the Cattle class' constructor unit test.
*/
void unit_cattle_constructor();

/*!
  Function prototype for the CattleHandle class' copy constructor unit test.
*/
void unit_cattle_copy_constructor();

/*!
  Function prototype for the Cattle class' destructor unit test.
*/
void unit_cattle_destructor();

/*!
  Function prototype for the Cattle class' method getEarring() unit test.
*/
void unit_cattle_getEarring(Farm* f);

/*!
  Function prototype for the Cattle class' method setEarring() unit test.
*/
void unit_cattle_setEarring(Farm* f);

/*!
  Function prototype for the Cattle class' method getBreed() unit test.
*/
void unit_cattle_getBreed(Farm* f);

/*!
  Function prototype for the Cattle class' method setBreed() unit test.
*/
void unit_cattle_setBreed(Farm* f);

/*!
  Function prototype for the Cattle class' method getAcquisitionDate() unit test.
*/
void unit_cattle_getAcquisitionDate(Farm* f);

/*!
  Function prototype for the Cattle class' method setAcquisitionDate() unit test.
*/
void unit_cattle_setAcquisitionDate(Farm* f);

/*!
  Function prototype for the Cattle class' method getBirthDate() unit test.
*/
void unit_cattle_getBirthDate(Farm* f);

/*!
  Function prototype for the Cattle class' method setBirthDate() unit test.
*/
void unit_cattle_setBirthDate(Farm* f);

/*!
  Function prototype for the Cattle class' method getFather() unit test.
*/
void unit_cattle_getFather(Farm* f);

/*!
  Function prototype for the Cattle class' method setFather() unit test.
*/
void unit_cattle_setFather(Farm* f);

/*!
  Function prototype for the Cattle class' method getMother() unit test.
*/
void unit_cattle_getMother(Farm* f);

/*!
  Function prototype for the Cattle class' method setMother() unit test.
*/
void unit_cattle_setMother(Farm* f);

/*!
  Function prototype for the Cattle class' method getWeight() unit test.
*/
void unit_cattle_getWeight(Farm* f);

/*!
  Function prototype for the Cattle class' method setWeight() unit test.
*/
void unit_cattle_setWeight(Farm* f);

/*!
  Function prototype for the Cattle class' method getValue() unit test.
*/
void unit_cattle_getValue(Farm* f);

/*!
  Function prototype for the Cattle class' method setValue() unit test.
*/
void unit_cattle_setValue(Farm* f);

/*!
  Function prototype for the CattleHandle class' assingment operator unit test.
*/
void unit_cattle_assingmentOperator();

/*!
  Function prototype for the function that runs all the unit tests of the Cattle class.
*/
void run_unit_tests_cattle(Farm* f);

#endif
