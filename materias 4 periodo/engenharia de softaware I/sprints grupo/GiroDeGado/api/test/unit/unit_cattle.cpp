#include "unit_cattle.h" 

// Function for Cattle class's constructor unit test.
void unit_cattle_constructor(){
    std::cout << "TEST 1 - Default constructor of the Cattle class without passing parameters" << std::endl;
    
    Cattle* cattle = new CattleHandle();

    delete cattle;

    std::cout << "OK!" << std::endl;
}

// Function for CattleHandle class's copy constructor unit test.
void unit_cattle_copy_constructor(){
    std::cout << "TEST 2 - Copy constructor of the CattleHandle class" << std::endl;
    
    CattleHandle* cattle1 = new CattleHandle();
    Cattle* cattle2 = new CattleHandle(*cattle1);

    // The copy constructor instantiates a new CattleHandle, but not a new CattleBody
    assert(numHandleCreated == numBodyCreated+1);

    delete cattle1;
    delete cattle2;

    assert(numHandleDeleted == numBodyDeleted+1);

    std::cout << "OK!" << std::endl;
}

// Function for the Cattle class' destructor unit test.
void unit_cattle_destructor(){
    std::cout << "TEST 3 - Default destructor of the Cattle class" << std::endl;

    #ifndef __unix__
    MEMORYSTATUSEX memInfoBefore;
    memInfoBefore.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfoBefore);
    DWORDLONG virtualMemUsedBefore = memInfoBefore.ullTotalPageFile - memInfoBefore.ullAvailPageFile;

    Cattle* cattle = new CattleHandle();

    delete cattle;

    MEMORYSTATUSEX memInfoAfter;
    memInfoAfter.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfoAfter);
    DWORDLONG virtualMemUsedAfter = memInfoAfter.ullTotalPageFile - memInfoAfter.ullAvailPageFile;

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of Cattle object.
    assert(virtualMemUsedBefore == virtualMemUsedAfter);
    #endif

    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getEarring() unit test.
void unit_cattle_getEarring(Farm* f){
    std::cout << "TEST 4 - Cattle class' getEarring() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class earring and if it's
    // equal to the parameter previously passed.
    assert(cattle->getEarring(f->getQuery(), 3) == QString::fromStdString("3"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setEarring() unit test.
void unit_cattle_setEarring(Farm* f){
    std::cout << "TEST 5 - Cattle class' setEarring() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();
    cattle->setEarring(f->getQuery(), 3, 4);

    // Making assertion to verify if the data of the earring property has been altered.
    assert(cattle->getEarring(f->getQuery(), 4) == QString::fromStdString("4"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getBreed() unit test.
void unit_cattle_getBreed(Farm* f){
    std::cout << "TEST 6 - Cattle class' getBreed() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class breed and if it's
    // equal to the parameter previously passed. 
    assert(cattle->getBreed(f->getQuery(), 4) == QString::fromStdString("Angus"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setBreed() unit test.
void unit_cattle_setBreed(Farm* f){
    std::cout << "TEST 7 - Cattle class' setBreed() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();
    cattle->setBreed(f->getQuery(), 4, "Brangus");

    // Making assertion to verify if the data of the breed property has been altered.
    assert(cattle->getBreed(f->getQuery(), 4) == QString::fromStdString("Brangus"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getAcquisitionDate() unit test.
void unit_cattle_getAcquisitionDate(Farm* f){
    std::cout << "TEST 8 - Cattle class's getAcquisitionDate() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class acquisition date and if it's
    // equal to the parameter previously passed. 
    assert(cattle->getAcquisitionDate(f->getQuery(), 4) == QString::fromStdString("02/01/2000"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setAcquisitionDate() unit test.
void unit_cattle_setAcquisitionDate(Farm* f){
    std::cout << "TEST 9 - Cattle class's setAcquisitionDate() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();
    cattle->setAcquisitionDate(f->getQuery(), 4, "02/03/2000");

    // Making assertion to verify if the data of the acquisition date property has been altered.
    assert(cattle->getAcquisitionDate(f->getQuery(), 4) == QString::fromStdString("02/03/2000"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getBirthDate() unit test.
void unit_cattle_getBirthDate(Farm* f){
    std::cout << "TEST 10 - Cattle class's getBirthDate() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class birth date and if it's
    // equal to the parameter previously passed. 
    assert(cattle->getBirthDate(f->getQuery(), 4) == QString::fromStdString("01/01/2000"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setBirthDate() unit test.
void unit_cattle_setBirthDate(Farm* f){
    std::cout << "TEST 11 - Cattle class's setBirthDate() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();
    cattle->setBirthDate(f->getQuery(), 4, "01/03/2000");

    // Making assertion to verify if the data of the birth date property has been altered.
    assert(cattle->getBirthDate(f->getQuery(), 4) == QString::fromStdString("01/03/2000"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getFather() unit test.
void unit_cattle_getFather(Farm* f){
    std::cout << "TEST 12 - Cattle class's getFather() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class father and if it's
    // equal to the parameter previously passed. 
    assert(cattle->getFather(f->getQuery(), 4) == QString::fromStdString("1"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setFather() unit test.
void unit_cattle_setFather(Farm* f){
    std::cout << "TEST 13 - Cattle class's setFather() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();
    cattle->setFather(f->getQuery(), 4, 5);

    // Making assertion to verify if the data of the father property has been altered.
    assert(cattle->getFather(f->getQuery(), 4) == QString::fromStdString("5"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getMother() unit test.
void unit_cattle_getMother(Farm* f){
    std::cout << "TEST 14 - Cattle class's getMother() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class mother and if it's
    // equal to the parameter previously passed. 
    assert(cattle->getMother(f->getQuery(), 4) == QString::fromStdString("2"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setMother() unit test.
void unit_cattle_setMother(Farm* f){
    std::cout << "TEST 15 - Cattle class's setMother() method" << std::endl;
    
    Cattle* cattle = new CattleHandle();
    cattle->setMother(f->getQuery(), 4, 6);

    // Making assertion to verify if the data of the mother property has been altered.
    assert(cattle->getMother(f->getQuery(), 4) == QString::fromStdString("6"));

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getWeight() unit test.
void unit_cattle_getWeight(Farm* f){
    std::cout << "TEST 16 - Cattle class's getWeight() method" << std::endl;

    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class weight and if it's
    // equal to the parameter previously passed.
    double weight = cattle->getWeight(f->getQuery(), 4).toDouble();
    assert(fabs(weight - 50.0) < 0.0001);

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setWeight() unit test.
void unit_cattle_setWeight(Farm* f){
    std::cout << "TEST 17 - Cattle class's setWeight() method" << std::endl;

    Cattle* cattle = new CattleHandle();
    cattle->setWeight(f->getQuery(), 4, 80.0);
    
    // Making assertion to verify if the data of the weight property has been altered.
    double weight = cattle->getWeight(f->getQuery(), 4).toDouble();
    assert(fabs(weight - 80.0) < 0.0001);

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method getValue() unit test.
void unit_cattle_getValue(Farm* f){
    std::cout << "TEST 18 - Cattle class's getValue() method" << std::endl;

    Cattle* cattle = new CattleHandle();

    // Making assertion to verify if the method returns the Cattle class value and if it's
    // equal to the parameter previously passed.
    double value = cattle->getValue(f->getQuery(), 4).toDouble();
    assert(fabs(value - 500.0) < 0.0001);

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for Cattle class' method setValue() unit test.
void unit_cattle_setValue(Farm* f){
    std::cout << "TEST 19 - Cattle class's setValue() method" << std::endl;

    Cattle* cattle = new CattleHandle();
    cattle->setValue(f->getQuery(), 4, 800.0);
    
    // Making assertion to verify if the data of the value property has been altered.
    double value = cattle->getValue(f->getQuery(), 4).toDouble();
    assert(fabs(value - 800.0) < 0.0001);

    delete cattle;
    std::cout << "OK!" << std::endl;
}

// Function for CattleHandle class' assingment operator unit test.
void unit_cattle_assingmentOperator(){
    std::cout << "TEST 20 - CattleHandle class assignment operator" << std::endl;
    
    CattleHandle* cattle1 = new CattleHandle();
    CattleHandle* cattle2 = new CattleHandle();
    *cattle2 = *cattle1;

    delete cattle1;
    delete cattle2;

    std::cout << "OK!" << std::endl;
}

// Function to run all the Cattle class' unit tests.
void run_unit_tests_cattle(Farm* f){

    // Calling all the Cattle class' unit test functions.
    // The number of handles and bodies created are 1 lower than the number of handles and bodies deleted
    // because of the Farm* f, created for testing purposes.

    unit_cattle_constructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_copy_constructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_destructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    // Creating a cattle in the test database before proceding with the tests
    f->createCattle(3, "Angus", "02/01/2000", "01/01/2000", 1, 2, 50.0, 500.0);

    unit_cattle_getEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_getBreed(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setBreed(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_getAcquisitionDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setAcquisitionDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_getBirthDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setBirthDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_getFather(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setFather(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_getMother(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setMother(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_getWeight(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setWeight(f);
    assert(numHandleCreated== numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_getValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_setValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_cattle_assingmentOperator();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    // Deleting the created cattle from the test database
    f->queryExec("delete from cattle where earring=4");
}
