#include "test/unit/home_unit_test.cpp"
#include "test/unit/cattle_management_unit_test.cpp"
#include "test/unit/cattle_register_unit_test.cpp"
#include "test/unit/cattle_buy_unit_test.cpp"
#include "test/unit/cattle_birth_unit_test.cpp"
#include "test/unit/cattle_consult_unit_test.cpp"
#include "test/unit/cattle_edit_unit_test.cpp"
#include "test/unit/cattle_remove_unit_test.cpp"
#include "test/unit/financial_management_unit_test.cpp"
#include "test/unit/financial_record_unit_test.cpp"
#include "test/unit/financial_consult_unit_test.cpp"
#include "test/unit/financial_remove_unit_test.cpp"
#include "test/unit/login_unit_test.cpp"
#include "test/unit/user_management_unit_test.cpp"
#include "test/unit/signup_unit_test.cpp"
#include "test/unit/user_consult_unit_test.cpp"
#include "test/unit/user_edit_unit_test.cpp"
#include "test/unit/user_remove_unit_test.cpp"
#include "test/unit/report_unit_test.cpp"

#include <QtSql/QtSql>
#include <QApplication>

int main(int argc, char *argv[])
{
    QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");

    QSqlQuery q;
    Farm* f = Farm::getFarm(&q);

    //Path dinamico do banco de testes
    QString path_test = QDir::currentPath();
    path_test = path_test + QString("/../../gui_tests/bd_giro_tests.db");
    bancoDeDados.setDatabaseName(path_test);
    bancoDeDados.open();

    f->queryExec("delete from cattle");
    f->queryExec("delete from financial");
    f->queryExec("delete from users");

    f->createUser("admin", "ADM", "123", "04/08/1999", "Administrador");

    QApplication a(argc, argv);

    //Teste para a tela Login
    TestLoginScreenGUI login(nullptr, f);
    QTest::qExec(&login);

    //Teste para a tela Home
    TestHomeScreenGUI home(nullptr,f);
    QTest::qExec(&home);

    //Teste para a tela de Gerencia de Gado
    TestCattleManagementScreenGUI manag(nullptr,f);
    QTest::qExec(&manag);

    //Teste para a tela de Registro de Gado
    TestCattleRegisterScreenGUI reg(nullptr,f);
    QTest::qExec(&reg);

    //Teste para a tela de Compra de Gado
    TestCattleBuyScreenGUI buy(nullptr,f);
    QTest::qExec(&buy);

    //Teste para a tela de Parto de Gado
    TestCattleBuyScreenGUI birth(nullptr,f);
    QTest::qExec(&birth);

    //Teste para a tela de Consulta de Gado
    TestCattleConsultScreenGUI consult(nullptr,f);
    QTest::qExec(&consult);

    //Teste para a tela de Edicao de Gado
    TestCattleEditScreenGUI edit(nullptr,f);
    QTest::qExec(&edit);

    //Teste para a tela de Exclusao de Gado
    TestCattleRemoveScreenGUI remove(nullptr,f);
    QTest::qExec(&remove);

    //Teste unitário da tela de Gerencia Financeira
    TestFinancialManagementScreenGUI finanManag(nullptr,f);
    QTest::qExec(&finanManag);

    //Teste unitário da tela de Registro Financeiro
    TestFinancialRecordScreenGUI finanReg(nullptr,f);
    QTest::qExec(&finanReg);

    //Teste unitário da tela de Consulta Financeira
    TestFinancialConsultScreenGUI finanConsu(nullptr,f);
    QTest::qExec(&finanConsu);

    //Teste unitário da tela de Exclusao Financeira
    TestFinancialRemoveScreenGUI finanRemo(nullptr,f);
    QTest::qExec(&finanRemo);

    //Teste unitário da tela de Relatorio
    TestReportScreenGUI report(nullptr,f);
    QTest::qExec(&report);

    //Teste unitário da tela de Gerencia de Usuarios
    TestUserManagementScreenGUI userManag(nullptr,f);
    QTest::qExec(&userManag);

    //Teste unitário da tela de Cadastro de Usuarios
    TestSignUpScreenGUI userSignUp(nullptr,f);
    QTest::qExec(&userSignUp);

    //Teste unitário da tela de Consulta de Usuarios
    TestUserConsultScreenGUI userConsu(nullptr,f);
    QTest::qExec(&userConsu);

    //Teste para a tela de Edicao de Usuarios
    TestUserEditScreenGUI userEdit(nullptr,f);
    QTest::qExec(&userEdit);

    //Teste unitário da tela de Exclusao de Usuarios
    TestUserRemoveScreenGUI userRemo(nullptr,f);
    QTest::qExec(&userRemo);

    f->queryExec("delete from cattle");
    f->queryExec("delete from financial");
    f->queryExec("delete from users");

    bancoDeDados.close();

    return 0;
}
