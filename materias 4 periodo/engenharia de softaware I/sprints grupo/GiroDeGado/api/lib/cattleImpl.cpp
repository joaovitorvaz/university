#include "../includes/cattleImpl.h"

CattleBody::CattleBody(){}

CattleBody::~CattleBody(){}

void CattleBody::setEarring(QSqlQuery* query, int actual_cattle_earring, int new_cattle_earring){
    QString actual_earring = QString::number(actual_cattle_earring);
    QString new_earring = QString::number(new_cattle_earring);

    query->exec("update cattle set earring="+new_earring+" where earring="+actual_earring);
}

QString CattleBody::getEarring(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(1).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void CattleBody::setBreed(QSqlQuery* query, int cattle_earring, std::string cattle_breed){
    QString earring = QString::number(cattle_earring);
    QString breed = QString::fromStdString(cattle_breed);

    query->exec("update cattle set breed='"+breed+"' where earring="+earring);
}

QString CattleBody::getBreed(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(2).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void CattleBody::setAcquisitionDate(QSqlQuery* query, int cattle_earring, std::string cattle_acquisition_date){
    QString earring = QString::number(cattle_earring);
    QString acquisition_date = QString::fromStdString(cattle_acquisition_date);

    query->exec("update cattle set acquisition_date='"+acquisition_date+"' where earring="+earring);
}

QString CattleBody::getAcquisitionDate(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(3).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void CattleBody::setBirthDate(QSqlQuery* query, int cattle_earring, std::string cattle_birth_date){
    QString earring = QString::number(cattle_earring);
    QString birth_date = QString::fromStdString(cattle_birth_date);

    query->exec("update cattle set birth_date='"+birth_date+"' where earring="+earring);
}

QString CattleBody::getBirthDate(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(4).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void CattleBody::setFather(QSqlQuery* query, int cattle_earring, int cattle_father){
    QString earring = QString::number(cattle_earring);
    QString father = QString::number(cattle_father);

    query->exec("update cattle set father="+father+" where earring="+earring);
}

QString CattleBody::getFather(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(5).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void CattleBody::setMother(QSqlQuery* query, int cattle_earring, int cattle_mother){
    QString earring = QString::number(cattle_earring);
    QString mother = QString::number(cattle_mother);

    query->exec("update cattle set mother="+mother+" where earring="+earring);
}

QString CattleBody::getMother(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(6).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void CattleBody::setWeight(QSqlQuery* query, int cattle_earring, double cattle_weight){
    QString earring = QString::number(cattle_earring);
    QString weight = QString::number(cattle_weight);

    query->exec("update cattle set weight="+weight+" where earring="+earring);
}

QString CattleBody::getWeight(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(7).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void CattleBody::setValue(QSqlQuery* query, int cattle_earring, double cattle_value){
    QString earring = QString::number(cattle_earring);
    QString value = QString::number(cattle_value);

    query->exec("update cattle set value="+value+" where earring="+earring);
}

QString CattleBody::getValue(QSqlQuery* query, int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query->next()){
        count++;
    }
    if(count > 0){
        query->first();
        return query->value(8).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}