#include "unit_user.h" 

// Function for the User class' constructor unit test.
void unit_user_constructor(){
    std::cout << "TEST 1 - Default constructor of the User class without passing parameters" << std::endl;
    
    User* user = new UserHandle();

    delete user;

    std::cout << "OK!" << std::endl;
}

// Function for the UserHandle class' copy constructor unit test.
void unit_user_copy_constructor(){
    std::cout << "TEST 2 - Copy constructor of the UserHandle class" << std::endl;
    
    UserHandle* user1 = new UserHandle();
    User* user2 = new UserHandle(*user1);

    // The copy constructor instantiates a new UserHandle, but not a new UserBody
    assert(numHandleCreated == numBodyCreated+3);

    delete user1;
    delete user2;

    assert(numHandleDeleted == numBodyDeleted+3);

    std::cout << "OK!" << std::endl;
}

// Function for the User class' destructor unit test.
void unit_user_destructor(){
    std::cout << "TEST 3 - Default destructor of the User class" << std::endl;
    
    #ifndef __unix__
    MEMORYSTATUSEX memInfoBefore;
    memInfoBefore.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfoBefore);
    DWORDLONG virtualMemUsedBefore = memInfoBefore.ullTotalPageFile - memInfoBefore.ullAvailPageFile;

    User* user = new UserHandle();

    delete user;

    MEMORYSTATUSEX memInfoAfter;
    memInfoAfter.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfoAfter);
    DWORDLONG virtualMemUsedAfter = memInfoAfter.ullTotalPageFile - memInfoAfter.ullAvailPageFile;

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of User object.
    assert(virtualMemUsedBefore == virtualMemUsedAfter);
    #endif

    std::cout << "OK!" << std::endl;
}

// Function for the User class' method getNickname() unit test.
void unit_user_getNickname(Farm* f){
    std::cout << "TEST 4 - User class's getNickname() method" << std::endl;
    
    User* user = new UserHandle();

    // Making assertion to verify if the method returns the User class nickname and if it's
    // equal to the parameter previously passed. 
    assert(user->getNickname(f->getQuery(), "jo_silva") == QString::fromStdString("jo_silva"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method setNickname() unit test.
void unit_user_setNickname(Farm* f){
    std::cout << "TEST 5 - User class's setNickname() method" << std::endl;
    
    User* user = new UserHandle();
    user->setNickname(f->getQuery(), "jo_silva", "jo_silva20");

    // Making assertion to verify if the data of the nickname property has been altered.
    assert(user->getNickname(f->getQuery(), "jo_silva20") == QString::fromStdString("jo_silva20"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method getName() unit test.
void unit_user_getName(Farm* f){
    std::cout << "TEST 6 - User class's getName() method" << std::endl;
    
    User* user = new UserHandle();

    // Making assertion to verify if the method returns the User class name and if it's
    // equal to the parameter previously passed. 
    assert(user->getName(f->getQuery(), "jo_silva20") == QString::fromStdString("Joao Silva"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method setName() unit test.
void unit_user_setName(Farm* f){
    std::cout << "TEST 7 - User class's setName() method" << std::endl;
    
    User* user = new UserHandle();
    user->setName(f->getQuery(), "jo_silva20", "Joao Silva da Silva");

    // Making assertion to verify if the data of the name property has been altered.
    assert(user->getName(f->getQuery(), "jo_silva20") == QString::fromStdString("Joao Silva da Silva"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method getPassword() unit test.
void unit_user_getPassword(Farm* f){
    std::cout << "TEST 8 - User class's getPassword() method" << std::endl;
    
    User* user = new UserHandle();

    // Making assertion to verify if the method returns the User class password and if it's
    // equal to the parameter previously passed. 
    assert(user->getPassword(f->getQuery(), "jo_silva20") == QString::fromStdString("123"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method setPassword() unit test.
void unit_user_setPassword(Farm* f){
    std::cout << "TEST 9 - User class's setPassword() method" << std::endl;
    
    User* user = new UserHandle();
    user->setPassword(f->getQuery(), "jo_silva20", "4321");

    // Making assertion to verify if the data of the password property has been altered.
    assert(user->getPassword(f->getQuery(), "jo_silva20") == QString::fromStdString("4321"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method getDate() unit test.
void unit_user_getDate(Farm* f){
    std::cout << "TEST 10 - User class's getDate() method" << std::endl;
    
    User* user = new UserHandle();

    // Making assertion to verify if the method returns the User class date and if it's
    // equal to the parameter previously passed. 
    assert(user->getDate(f->getQuery(), "jo_silva20") == QString::fromStdString("01/01/2000"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method setDate() unit test.
void unit_user_setDate(Farm* f){
    std::cout << "TEST 11 - User class's setDate() method" << std::endl;
    
    User* user = new UserHandle();
    user->setDate(f->getQuery(), "jo_silva20", "01/03/2000");

    // Making assertion to verify if the data of the date property has been altered.
    assert(user->getDate(f->getQuery(), "jo_silva20") == QString::fromStdString("01/03/2000"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method getType() unit test.
void unit_user_getType(Farm* f){
    std::cout << "TEST 12 - User class's getType() method" << std::endl;
    
    User* user = new UserHandle();

    // Making assertion to verify if the method returns the User class type and if it's
    // equal to the parameter previously passed. 
    assert(user->getType(f->getQuery(), "jo_silva20") == QString::fromStdString("Administrador"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the User class' method setType() unit test.
void unit_user_setType(Farm* f){
    std::cout << "TEST 13 - User class's setType() method" << std::endl;
    
    User* user = new UserHandle();
    user->setType(f->getQuery(), "jo_silva20", "Funcionario");

    // Making assertion to verify if the data of the type property has been altered.
    assert(user->getType(f->getQuery(), "jo_silva20") == QString::fromStdString("Funcionario"));

    delete user;
    std::cout << "OK!" << std::endl;
}

// Function for the UserHandle class' assingment operator unit test.
void unit_user_assingmentOperator(){
    std::cout << "TEST 14 - UserHandle class assignment operator" << std::endl;
    
    UserHandle* user1 = new UserHandle();
    UserHandle* user2 = new UserHandle();
    *user2 = *user1;

    delete user1;
    delete user2;

    std::cout << "OK!" << std::endl;
}

// Function that runs all the unit tests of the User class.
void run_unit_tests_user(Farm* f){
    // Calling all the User class' unit test functions.
    // The number of handles and bodies created are 1 lower than the number of handles and bodies deleted
    // because of the Farm* f, created for testing purposes.

    unit_user_constructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_copy_constructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_destructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    // Creating a user in the test database before proceding with the tests
    f->createUser("jo_silva", "Joao Silva", "123", "01/01/2000", "Administrador");
    
    unit_user_getNickname(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_setNickname(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_getName(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_setName(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_getPassword(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_setPassword(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_getDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_setDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_getType(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_setType(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_user_assingmentOperator();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    // Deleting the created user from the test database
    f->queryExec("delete from users where nickname='jo_silva20'");
}
