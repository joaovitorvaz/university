#include "unit_farm.h"

void unit_farm_createCattle(Farm* f){
    std::cout << "TEST 1 - Farm class' createCattle() method" << std::endl;

    f->createCattle(3, "Angus", "02/01/2000", "01/01/2000", 1, 2, 50.0, 500.0);
    QString earring = f->getCattleEarring(3);

    // Making assertion to verify if the cattle was created.
    assert(earring == QString::fromStdString("3"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_createTransaction(Farm* f){
    std::cout << "TEST 2 - Farm class' createTransaction() method" << std::endl;

    f->createTransaction(20, 2000.0, "Venda de Gado", "01/01/2000", 5);
    QString number = f->getTransactionNumber(20);

    // Making assertion to verify if the transaction was created.
    assert(number == QString::fromStdString("20"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_createUser(Farm* f){
    std::cout << "TEST 3 - Farm class' createUser() method" << std::endl;

    f->createUser("jo_silva", "Joao Silva", "123", "01/01/2000", "Administrador");
    QString nickname = f->getUserNickname("jo_silva");

    // Making assertion to verify if the User was created.
    assert(nickname == QString::fromStdString("jo_silva"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getQuery(Farm* f){
    std::cout << "TEST 4 - Farm class' getQuery() method" << std::endl;

    QSqlQuery* query = NULL;
    query = f->getQuery();

    // Making assertion to verify if the query returned isn't NULL.
    assert(query != NULL);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setQuery(Farm* f){
    std::cout << "TEST 5 - Farm class' setQuery() method" << std::endl;

    QSqlQuery* query = f->getQuery();

    // Making assertion to verify if the query passed to the farm's constructor is the same as the one returned
    // by the method.
    assert(query != NULL);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_queryExec(Farm* f){
    std::cout << "TEST 6 - Farm class' queryExec() method" << std::endl;

    bool response = f->queryExec("select * from cattle where earring=3");

    // Making assertion to verify if the method was executed by the query.
    assert(response == 1);

    std::cout << "OK!" << std::endl;
}

void unit_farm_queryNext(Farm* f){
    std::cout << "TEST 7 - Farm class' queryNext() method" << std::endl;

    int count = 0;
    while(f->queryNext()){
        count++;
    }

    // Making assertion to verify if the method was executed by the query.
    assert(count > 0);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_queryFirst(Farm* f){
    std::cout << "TEST 8 - Farm class' queryFirst() method" << std::endl;

    bool response = f->queryFirst();

    // Making assertion to verify if the method was executed by the query.
    assert(response == 1);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_queryValue(Farm* f){
    std::cout << "TEST 9 - Farm class' queryValue() method" << std::endl;

    QString earring = f->queryValue(1);

    // Making assertion to verify if the method was executed by the query.
    assert(earring == QString::fromStdString("3"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleEarring(Farm* f){
    std::cout << "TEST 10 - Farm class' getCattleEarring() method" << std::endl;

    QString earring = f->getCattleEarring(3);

    // Making assertion to verify if the earring was returned correctly.
    assert(earring == QString::fromStdString("3"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleEarring(Farm* f){
    std::cout << "TEST 11 - Farm class' setCattleEarring() method" << std::endl;

    f->setCattleEarring(3, 4);
    QString earring = f->getCattleEarring(4);

    // Making assertion to verify if the earring was modified.
    assert(earring == QString::fromStdString("4"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleBreed(Farm* f){
    std::cout << "TEST 12 - Farm class' getCattleBreed() method" << std::endl;

    QString breed = f->getCattleBreed(4);

    // Making assertion to verify if the breed was returned correctly.
    assert(breed == QString::fromStdString("Angus"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleBreed(Farm* f){
    std::cout << "TEST 13 - Farm class' setCattleBreed() method" << std::endl;

    f->setCattleBreed(4, "Brangus");
    QString breed = f->getCattleBreed(4);

    // Making assertion to verify if the breed was modified.
    assert(breed == QString::fromStdString("Brangus"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleAcquisitionDate(Farm* f){
    std::cout << "TEST 14 - Farm class' setCattleAcquisitionDate() method" << std::endl;

    QString acquisition_date = f->getCattleAcquisitionDate(4);

    // Making assertion to verify if the acquisition date was returned correctly.
    assert(acquisition_date == QString::fromStdString("02/01/2000"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleAcquisitionDate(Farm* f){
    std::cout << "TEST 15 - Farm class' getCattleAcquisitionDate() method" << std::endl;

    f->setCattleAcquisitionDate(4, "02/03/2000");
    QString acquisition_date = f->getCattleAcquisitionDate(4);

    // Making assertion to verify if the acquisition date was modified.
    assert(acquisition_date == QString::fromStdString("02/03/2000"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleBirthDate(Farm* f){
    std::cout << "TEST 16 - Farm class' getCattleBirthDate() method" << std::endl;

    QString birth_date = f->getCattleBirthDate(4);

    // Making assertion to verify if the birth date was returned correctly.
    assert(birth_date == QString::fromStdString("01/01/2000"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleBirthDate(Farm* f){
    std::cout << "TEST 17 - Farm class' setCattleBirthDate() method" << std::endl;

    f->setCattleBirthDate(4, "01/03/2000");
    QString birth_date = f->getCattleBirthDate(4);

    // Making assertion to verify if the birth date was modified.
    assert(birth_date == QString::fromStdString("01/03/2000"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleFather(Farm* f){
    std::cout << "TEST 18 - Farm class' getCattleFather() method" << std::endl;

    QString father = f->getCattleFather(4);

    // Making assertion to verify if the father's earring was returned correctly.
    assert(father == QString::fromStdString("1"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleFather(Farm* f){
    std::cout << "TEST 19 - Farm class' setCattleFather() method" << std::endl;

    f->setCattleFather(4, 5);
    QString father = f->getCattleFather(4);

    // Making assertion to verify if the father's earring was modified.
    assert(father == QString::fromStdString("5"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleMother(Farm* f){
    std::cout << "TEST 20 - Farm class' getCattleMother() method" << std::endl;

    QString mother = f->getCattleMother(4);

    // Making assertion to verify if the mother's earring was returned correctly.
    assert(mother == QString::fromStdString("2"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleMother(Farm* f){
    std::cout << "TEST 21 - Farm class' setCattleMother() method" << std::endl;

    f->setCattleMother(4, 6);
    QString mother = f->getCattleMother(4);

    // Making assertion to verify if the mother's earring was modified.
    assert(mother == QString::fromStdString("6"));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleWeight(Farm* f){
    std::cout << "TEST 22 - Farm class' getCattleWeight() method" << std::endl;

    double weight = f->getCattleWeight(4).toDouble();

    // Making assertion to verify if the weight was returned correctly.
    assert(fabs(weight - 50.0) < 0.0001);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleWeight(Farm* f){
    std::cout << "TEST 23 - Farm class' setCattleWeight() method" << std::endl;

    f->setCattleWeight(4, 80.0);
    double weight = f->getCattleWeight(4).toDouble();

    // Making assertion to verify if the weight was modified.
    assert(fabs(weight - 80.0) < 0.0001);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getCattleValue(Farm* f){
    std::cout << "TEST 24 - Farm class' getCattleValue() method" << std::endl;

    double value = f->getCattleValue(4).toDouble();

    // Making assertion to verify if the value was returned correctly.
    assert(fabs(value - 500.0) < 0.0001);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_setCattleValue(Farm* f){
    std::cout << "TEST 25 - Farm class' setCattleValue() method" << std::endl;

    f->setCattleValue(4, 800.0);
    double value = f->getCattleValue(4).toDouble();

    // Making assertion to verify if the value was modified.
    assert(fabs(value - 800.0) < 0.0001);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getTransactionNumber(Farm* f){
    std::cout << "TEST 26 - Farm class' getTransactionNumber() method" << std::endl;

    QString number = f->getTransactionNumber(20);

    // Making assertion to verify if the number was returned correctly.
    assert(number == QString::fromStdString("20"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setTransactionNumber(Farm* f){
    std::cout << "TEST 27 - Farm class' setTransactionNumber() method" << std::endl;

    f->setTransactionNumber(20, 21);
    QString number = f->getTransactionNumber(21);

    // Making assertion to verify if the number was modified.
    assert(number == QString::fromStdString("21"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getTransactionValue(Farm* f){
    std::cout << "TEST 28 - Farm class' getTransactionValue() method" << std::endl;

    double value = f->getTransactionValue(21).toDouble();

    // Making assertion to verify if the value was returned correctly.
    assert(fabs(value - 2000.0) < 0.0001);

    std::cout << "OK!" << std::endl;
}

void unit_farm_setTransactionValue(Farm* f){
    std::cout << "TEST 29 - Farm class' setTransactionValue() method" << std::endl;

    f->setTransactionValue(21, 2500.0);
    double value = f->getTransactionValue(21).toDouble();

    // Making assertion to verify if the value was modified.
    assert(fabs(value - 2500.0) < 0.0001);

    std::cout << "OK!" << std::endl;
}

void unit_farm_getTransactionDescription(Farm* f){
    std::cout << "TEST 30 - Farm class' getTransactionDescription() method" << std::endl;

    QString description = f->getTransactionDescription(21);

    // Making assertion to verify if the description was returned correctly.
    assert(description == QString::fromStdString("Venda de Gado"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setTransactionDescription(Farm* f){
    std::cout << "TEST 31 - Farm class' setTransactionDescription() method" << std::endl;

    f->setTransactionDescription(21, "Compra de Gado");
    QString description = f->getTransactionDescription(21);

    // Making assertion to verify if the description was modified.
    assert(description == QString::fromStdString("Compra de Gado"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getTransactionDate(Farm* f){
    std::cout << "TEST 32 - Farm class' getTransactionDate() method" << std::endl;

    QString date = f->getTransactionDate(21);

    // Making assertion to verify if the date was returned correctly.
    assert(date == QString::fromStdString("01/01/2000"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setTransactionDate(Farm* f){
    std::cout << "TEST 33 - Farm class' setTransactionDate() method" << std::endl;

    f->setTransactionDate(21, "01/03/2000");
    QString date = f->getTransactionDate(21);

    // Making assertion to verify if the date was modified.
    assert(date == QString::fromStdString("01/03/2000"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getTransactionCattleEarring(Farm* f){
    std::cout << "TEST 34 - Farm class' getTransactionCattleEarring() method" << std::endl;

    QString cattle_earring = f->getTransactionCattleEarring(21);

    // Making assertion to verify if the cattle earring was returned correctly.
    assert(cattle_earring == QString::fromStdString("5"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setTransactionCattleEarring(Farm* f){
    std::cout << "TEST 35 - Farm class' setTransactionCattleEarring() method" << std::endl;

    f->setTransactionCattleEarring(21, 6);
    QString cattle_earring = f->getTransactionCattleEarring(21);

    // Making assertion to verify if the cattle earring was modified.
    assert(cattle_earring == QString::fromStdString("6"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getUserNickname(Farm* f){
    std::cout << "TEST 36 - Farm class's getUserNickame() method" << std::endl;
    
    QString nickname = f->getUserNickname("jo_silva");

    // Making assertion to verify if the method returns the User class nickname and if it's
    // equal to the parameter previously passed. 
    assert(nickname == QString::fromStdString("jo_silva"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setUserNickname(Farm* f){
    std::cout << "TEST 37 - Farm class's setUserNickame() method" << std::endl;
    
    f->setUserNickname("jo_silva", "jo_silva20");
    QString nickname = f->getUserNickname("jo_silva20");

    // Making assertion to verify if the data of the nickname property has been altered.
    assert(nickname == QString::fromStdString("jo_silva20"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getUserName(Farm* f){
    std::cout << "TEST 38 - Farm class's getUserName() method" << std::endl;
    
    QString name = f->getUserName("jo_silva20");

    // Making assertion to verify if the method returns the User class name and if it's
    // equal to the parameter previously passed. 
    assert(name == QString::fromStdString("Joao Silva"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setUserName(Farm* f){
    std::cout << "TEST 39 - Farm class's setUserName() method" << std::endl;
    
    f->setUserName("jo_silva20", "Joao Silva da Silva");
    QString name = f->getUserName("jo_silva20");

    // Making assertion to verify if the data of the name property has been altered.
    assert(name == QString::fromStdString("Joao Silva da Silva"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getUserPassword(Farm* f){
    std::cout << "TEST 40 - Farm class's getUserPassword() method" << std::endl;
    
    QString password = f->getUserPassword("jo_silva20");

    // Making assertion to verify if the method returns the User class password and if it's
    // equal to the parameter previously passed. 
    assert(password == QString::fromStdString("123"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setUserPassword(Farm* f){
    std::cout << "TEST 41 - Farm class's setUserPassword() method" << std::endl;
    
    f->setUserPassword("jo_silva20", "4321");
    QString password = f->getUserPassword("jo_silva20");

    // Making assertion to verify if the data of the password property has been altered.
    assert(password == QString::fromStdString("4321"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getUserDate(Farm* f){
    std::cout << "TEST 42 - Farm class's getUserDate() method" << std::endl;
    
    QString date = f->getUserDate("jo_silva20");

    // Making assertion to verify if the method returns the User class date and if it's
    // equal to the parameter previously passed. 
    assert(date == QString::fromStdString("01/01/2000"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setUserDate(Farm* f){
    std::cout << "TEST 43 - Farm class's setUserDate() method" << std::endl;
    
    f->setUserDate("jo_silva20", "01/03/2000");
    QString date = f->getUserDate("jo_silva20");

    // Making assertion to verify if the data of the date property has been altered.
    assert(date == QString::fromStdString("01/03/2000"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getUserType(Farm* f){
    std::cout << "TEST 44 - Farm class's getUserType() method" << std::endl;
    
    QString type = f->getUserType("jo_silva20");

    // Making assertion to verify if the method returns the User class type and if it's
    // equal to the parameter previously passed. 
    assert(type == QString::fromStdString("Administrador"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_setUserType(Farm* f){
    std::cout << "TEST 45 - Farm class's setUserType() method" << std::endl;
    
    f->setUserType("jo_silva20", "Funcionario");
    QString type = f->getUserType("jo_silva20");

    // Making assertion to verify if the data of the type property has been altered.
    assert(type == QString::fromStdString("Funcionario"));

    std::cout << "OK!" << std::endl;
}

void unit_farm_getLastEarringAvailable(Farm* f){
    std::cout << "TEST 46 - Farm class' getLastEarringAvailable() method" << std::endl;

    int last = f->getLastEarringAvailable();

    // Making assertion to verify if the last earring available from the cattle table was returned correctly.
    assert(last == 5);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_getLastNumberAvailable(Farm* f){
    std::cout << "TEST 47 - Farm class' getLastNumberAvailable() method" << std::endl;

    int last = f->getLastNumberAvailable();

    // Making assertion to verify if the last number available from the financial table was returned correctly.
    assert(last == 22);
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_deleteCattle(Farm* f){
    std::cout << "TEST 48 - Farm class' deleteCattle() method" << std::endl;

    f->deleteCattle(4);
    QString earring = f->getCattleEarring(4);

    // Making assertion to verify if the cattle was deleted.
    assert(earring == QString(""));
    
    std::cout << "OK!" << std::endl;
}

void unit_farm_deleteTransaction(Farm* f){
    std::cout << "TEST 49 - Farm class' deleteTransaction() method" << std::endl;

    f->deleteTransaction(21);
    QString number = f->getTransactionNumber(21);

    // Making assertion to verify if the transaction was deleted.
    assert(number == QString(""));
   
    std::cout << "OK!" << std::endl;
}

void unit_farm_deleteUser(Farm* f){
    std::cout << "TEST 50 - Farm class' deleteUser() method" << std::endl;

    f->deleteUser("jo_silva20");
    QString nickname = f->getUserNickname("jo_silva20");

    // Making assertion to verify if the User was deleted.
    assert(nickname == QString(""));
   
    std::cout << "OK!" << std::endl;
}

// Function to run all the Farm class' unit tests.
void run_unit_tests_farm(Farm* f){
    
    // Calling all the Farm class' unit test functions.
    unit_farm_createCattle(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_createTransaction(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_createUser(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getQuery(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setQuery(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_queryExec(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_queryNext(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_queryFirst(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_queryValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleBreed(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleBreed(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleAcquisitionDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleAcquisitionDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleBirthDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleBirthDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleFather(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleFather(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleMother(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleMother(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleWeight(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleWeight(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getCattleValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setCattleValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getTransactionNumber(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setTransactionNumber(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getTransactionValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setTransactionValue(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getTransactionDescription(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setTransactionDescription(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getTransactionDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setTransactionDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getTransactionCattleEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_setTransactionCattleEarring(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getUserNickname(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_setUserNickname(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_getUserName(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_setUserName(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_getUserPassword(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_setUserPassword(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_getUserDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_setUserDate(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_getUserType(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);
    
    unit_farm_setUserType(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getLastEarringAvailable(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_getLastNumberAvailable(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_deleteCattle(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_deleteTransaction(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

    unit_farm_deleteUser(f);
    assert(numHandleCreated == numHandleDeleted+1);
    assert(numBodyCreated == numBodyDeleted+1);

}
