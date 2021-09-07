#include "../api/includes/farm.h"
#include "./entity/loginscreen.h"

#include <QApplication>
#include <QtSql>
#include <QFileInfo>
#include <iostream>

int main(int argc, char* argv[])
{
    QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");

    QSqlQuery q;
    Farm* f = Farm::getFarm(&q);

    //Path dinamico do banco oficial
    QString path_ofc = QDir::currentPath();
    path_ofc = path_ofc + QString("/../../gui/bd_giro.db");
    std::cout << path_ofc.toStdString() << std::endl;

    bancoDeDados.setDatabaseName(path_ofc);
    bancoDeDados.open();

    QApplication a(argc, argv);
    LoginScreen w(nullptr,f);
    w.show();
    return a.exec();

    delete f;

    return 0;
}
