#include "functional_tests.h" 

// Function for the functional test for creating, editing, reading and deleting a cattle.
void functional_cattle(Farm* f){
    std::cout << "TEST 1 - Creating, editing, reading and deleting a cattle" << std::endl;

    // Creating a cattle
    f->createCattle(3, "Angus", "02/01/2000", "01/01/2000", 1, 2, 50.0, 500.0);

    // Editing a cattle
    f->setCattleEarring(3, 4);
    f->setCattleBreed(4, "Brangus");
    f->setCattleAcquisitionDate(4, "02/03/2000");
    f->setCattleBirthDate(4, "01/03/2000");
    f->setCattleFather(4, 5);
    f->setCattleMother(4, 6);
    f->setCattleWeight(4, 100.0);
    f->setCattleValue(4, 1000.0);

    // Reading data from a cattle
    int earring = f->getCattleEarring(4).toInt();
    QString breed = f->getCattleBreed(4);
    QString acquisition_date = f->getCattleAcquisitionDate(4);
    QString birth_date = f->getCattleBirthDate(4);
    int father = f->getCattleFather(4).toInt();
    int mother = f->getCattleMother(4).toInt();
    double weight = f->getCattleWeight(4).toDouble();
    double value = f->getCattleValue(4).toDouble();

    assert(earring == 4);
    assert(breed == "Brangus");
    assert(acquisition_date == "02/03/2000");
    assert(birth_date == "01/03/2000");
    assert(father == 5);
    assert(mother == 6);
    assert(fabs(weight - 100.0) < 0.0001);
    assert(fabs(value - 1000.0) < 0.0001);

    // Deleting a cattle
    f->deleteCattle(4);

    QString earring_2 = f->getCattleEarring(4);
    assert(earring_2 == "");

    std::cout << "OK!" << std::endl;
}

// Function for the functional test for creating, editing, reading and deleting a transaction.
void functional_transaction(Farm* f){
    std::cout << "TEST 2 - Creating, editing, reading and deleting a transaction" << std::endl;

    // Creating a transaction
    f->createTransaction(20, 2000.0, "Venda de Gado", "01/01/2000", 5);

    // Editing a transaction
    f->setTransactionNumber(20, 21);
    f->setTransactionValue(21, 2500.0);
    f->setTransactionDescription(21, "Compra de Gado");
    f->setTransactionDate(21, "01/03/2000");
    f->setTransactionCattleEarring(21, 6);

    // Reading data from a transaction
    int number = f->getTransactionNumber(21).toInt();
    double value = f->getTransactionValue(21).toDouble();
    QString description = f->getTransactionDescription(21);
    QString date = f->getTransactionDate(21);
    int cattle_earring = f->getTransactionCattleEarring(21).toInt();

    assert(number == 21);
    assert(fabs(value - 2500.0) < 0.0001);
    assert(description == "Compra de Gado");
    assert(date == "01/03/2000");
    assert(cattle_earring == 6);

    // Deleting a transaction
    f->deleteTransaction(21);

    QString number_2 = f->getTransactionNumber(21);
    assert(number_2 == "");

    std::cout << "OK!" << std::endl;
}

// Function for the user test for creating, editing, reading and deleting a transaction.
void functional_user(Farm* f){
    std::cout << "TEST 3 - Creating, editing, reading and deleting a user" << std::endl;

    // Creating a user
    f->createUser("jo_silva","Joao","123","01/01/2000","Funcionario");

    // Editing a transaction
    f->setUserNickname("jo_silva", "jo_silva20");
    f->setUserName("jo_silva20", "Joao Silva");
    f->setUserPassword("jo_silva20", "1234");
    f->setUserDate("jo_silva20", "01/03/2000");
    f->setUserType("jo_silva20", "Administrador");

    // Reading data from a transaction
    QString nickname = f->getUserNickname("jo_silva20");
    QString name = f->getUserName("jo_silva20");
    QString password = f->getUserPassword("jo_silva20");
    QString date = f->getUserDate("jo_silva20");
    QString type = f->getUserType("jo_silva20");

    assert(nickname == "jo_silva20");
    assert(name == "Joao Silva");
    assert(password == "1234");
    assert(date == "01/03/2000");
    assert(type == "Administrador");

    // Deleting a transaction
    f->deleteUser("jo_silva20");

    QString nickname_2 = f->getUserNickname("jo_silva20");
    assert(nickname_2 == "");

    std::cout << "OK!" << std::endl;
}

// Function for the function that runs all the functional tests.
void run_functional_tests(Farm* f){
    // Calling all the functional test functions.
    // The number of handles and bodies created are 1 lower than the number of handles and bodies deleted
    // because of the Farm* f, created for testing purposes.

    functional_cattle(f);

    functional_transaction(f);

    functional_user(f);

}
