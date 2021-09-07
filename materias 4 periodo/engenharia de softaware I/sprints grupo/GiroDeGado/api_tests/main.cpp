#include "../api/test/unit/main_unit_test.h"
#include "../api/test/functional/main_functional_test.h"

#include <QApplication>
#include <QtSql>
#include <QFileInfo>

#define UNIT_TEST 1
#define FUNCTIONAL_TEST 1

int main(int argc, char* argv[])
{
    QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");

    QSqlQuery q;
    Farm* f = Farm::getFarm(&q);

    // Execution of the unit tests of Cattle, Transaction, User and Farm classes
    if(UNIT_TEST){
        //Dynamic path of the data bank for tests
        QString path_test = QDir::currentPath();
        path_test = path_test + QString("/../../api_tests/bd_giro_tests.db");

        bancoDeDados.setDatabaseName(path_test);
        bancoDeDados.open();

        main_unit_test(f);

        bancoDeDados.close();
    }

    // Execution of the functional tests
    if(FUNCTIONAL_TEST){
        //Dynamic path of the data bank for tests
        QString path_test = QDir::currentPath();
        path_test = path_test + QString("/../../api_tests/bd_giro_tests.db");

        bancoDeDados.setDatabaseName(path_test);
        bancoDeDados.open();

        main_functional_test(f);

        bancoDeDados.close();
    }

    delete f;

    return 0;
}
