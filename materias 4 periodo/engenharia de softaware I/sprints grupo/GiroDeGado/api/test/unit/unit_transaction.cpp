#include "unit_transaction.h" 

// Function for Transaction class's constructor unit test.
void unit_transaction_constructor(){
    std::cout << "TEST 1 - Default constructor of the Transaction class without passing parameters" << std::endl;
    
    Transaction* transaction = new TransactionHandle();

    delete transaction;

    std::cout << "OK!" << std::endl;
}

// Function for TransactionHandle class's copy constructor unit test.
void unit_transaction_copy_constructor(){
    std::cout << "TEST 2 - Copy constructor of the TransactionHandle class" << std::endl;
    
    TransactionHandle* transaction1 = new TransactionHandle();
    Transaction* transaction2 = new TransactionHandle(*transaction1);

    // The copy constructor instantiates a new TransactionHandle, but not a new TransactionBody
    assert(numHandleCreated == numBodyCreated+2);

    delete transaction1;
    delete transaction2;

    assert(numHandleDeleted == numBodyDeleted+2);

    std::cout << "OK!" << std::endl;
}

// Function for the Transaction class' destructor unit test.
void unit_transaction_destructor(){
    std::cout << "TEST 3 - Default destructor of the Transaction class" << std::endl;

    #ifndef __unix__
    MEMORYSTATUSEX memInfoBefore;
    memInfoBefore.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfoBefore);
    DWORDLONG virtualMemUsedBefore = memInfoBefore.ullTotalPageFile - memInfoBefore.ullAvailPageFile;

    Transaction* transaction = new TransactionHandle();

    delete transaction;

    MEMORYSTATUSEX memInfoAfter;
    memInfoAfter.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfoAfter);
    DWORDLONG virtualMemUsedAfter = memInfoAfter.ullTotalPageFile - memInfoAfter.ullAvailPageFile;

    // Making assertion to verify if the memory usage after the creation and deletion
    // is the same as before the creation of Transaction object.
    assert(virtualMemUsedBefore == virtualMemUsedAfter);
    #endif

    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method getNumber() unit test.
void unit_transaction_getNumber(Farm* f){
    std::cout << "TEST 4 - Transaction class's getNumber() method" << std::endl;
    
    Transaction* transaction = new TransactionHandle();

    // Making assertion to verify if the method returns the Transaction class number and if it's
    // equal to the parameter previously passed. 
    assert(transaction->getNumber(f->getQuery(), 20) == QString::fromStdString("20"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method setNumber() unit test.
void unit_transaction_setNumber(Farm* f){
    std::cout << "TEST 5 - Transaction class's setNumber() method" << std::endl;
    
    Transaction* transaction = new TransactionHandle();
    transaction->setNumber(f->getQuery(), 20, 21);

    // Making assertion to verify if the data of the number property has been altered.
    assert(transaction->getNumber(f->getQuery(), 21) == QString::fromStdString("21"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method getValue() unit test.
void unit_transaction_getValue(Farm* f){
    std::cout << "TEST 6 - Transaction class's getValue() method" << std::endl;

    Transaction* transaction = new TransactionHandle();

    // Making assertion to verify if the method returns the Transaction class value and if it's
    // equal to the parameter previously passed.
    double value = transaction->getValue(f->getQuery(), 21).toDouble();
    assert(fabs(value - 2000.0) < 0.0001);

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method setValue() unit test.
void unit_transaction_setValue(Farm* f){
    std::cout << "TEST 7 - Transaction class's setValue() method" << std::endl;

    Transaction* transaction = new TransactionHandle();
    transaction->setValue(f->getQuery(), 21, 2500.0);
    
    // Making assertion to verify if the data of the value property has been altered.
    double value = transaction->getValue(f->getQuery(), 21).toDouble();
    assert(fabs(value - 2500.0) < 0.0001);

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method getDescription() unit test.
void unit_transaction_getDescription(Farm* f){
    std::cout << "TEST 8 - Transaction class's getDescription() method" << std::endl;

    Transaction* transaction = new TransactionHandle();

    // Making assertion to verify if the method returns the Transaction class description and if it's
    // equal to the parameter previously passed.
    assert(transaction->getDescription(f->getQuery(), 21) == QString::fromStdString("Venda de Gado"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method setDescription() unit test.
void unit_transaction_setDescription(Farm* f){
    std::cout << "TEST 9 - Transaction class's setDescription() method" << std::endl;

    Transaction* transaction = new TransactionHandle();
    transaction->setDescription(f->getQuery(), 21, "Compra de Gado");
    
    // Making assertion to verify if the data of the description property has been altered.
    assert(transaction->getDescription(f->getQuery(), 21) == QString::fromStdString("Compra de Gado"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method getDate() unit test.
void unit_transaction_getDate(Farm* f){
    std::cout << "TEST 10 - Transaction class's getDate() method" << std::endl;

    Transaction* transaction = new TransactionHandle();

    // Making assertion to verify if the method returns the Transaction class Date and if it's
    // equal to the parameter previously passed.
    assert(transaction->getDate(f->getQuery(), 21) == QString::fromStdString("01/01/2000"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method setDate() unit test.
void unit_transaction_setDate(Farm* f){
    std::cout << "TEST 11 - Transaction class's setDate() method" << std::endl;

    Transaction* transaction = new TransactionHandle();
    transaction->setDate(f->getQuery(), 21, "01/03/2000");
    
    // Making assertion to verify if the data of the Date property has been altered.
    assert(transaction->getDate(f->getQuery(), 21) == QString::fromStdString("01/03/2000"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method getCattleEarring() unit test.
void unit_transaction_getCattleEarring(Farm* f){
    std::cout << "TEST 12 - Transaction class's getCattleEarring() method" << std::endl;

    Transaction* transaction = new TransactionHandle();

    // Making assertion to verify if the method returns the Transaction class CattleEarring and if it's
    // equal to the parameter previously passed.
    assert(transaction->getCattleEarring(f->getQuery(), 21) == QString::fromStdString("5"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for Transaction class' method setCattleEarring() unit test.
void unit_transaction_setCattleEarring(Farm* f){
    std::cout << "TEST 13 - Transaction class's setCattleEarring() method" << std::endl;

    Transaction* transaction = new TransactionHandle();
    transaction->setCattleEarring(f->getQuery(), 21, 6);
    
    // Making assertion to verify if the data of the CattleEarring property has been altered.
    assert(transaction->getCattleEarring(f->getQuery(), 21) == QString::fromStdString("6"));

    delete transaction;
    std::cout << "OK!" << std::endl;
}

// Function for TransactionHandle class' assingment operator unit test.
void unit_transaction_assingmentOperator(){
    std::cout << "TEST 14 - TransactionHandle class assignment operator" << std::endl;
    
    TransactionHandle* transaction1 = new TransactionHandle();
    TransactionHandle* transaction2 = new TransactionHandle();
    *transaction2 = *transaction1;

    delete transaction1;
    delete transaction2;

    std::cout << "OK!" << std::endl;
}

// Function to run all the Transaction class' unit tests.
void run_unit_tests_transaction(Farm* f){

    // Calling all the Transaction class' unit test functions.
    // The number of handles and bodies created are 1 lower than the number of handles and bodies deleted
    // because of the Farm* f, created for testing purposes.

    unit_transaction_constructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_copy_constructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_destructor();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    // Creating a transaction in the test database before proceding with the tests
    f->createTransaction(20, 2000.0, "Venda de Gado", "01/01/2000", 5);

    unit_transaction_getNumber(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_setNumber(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_getDescription(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_setDescription(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_getValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_setValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_getDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_setDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_getCattleEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_setCattleEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_transaction_assingmentOperator();
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    // Deleting the created transaction from the test database
    f->queryExec("delete from financial where number=21");
}
