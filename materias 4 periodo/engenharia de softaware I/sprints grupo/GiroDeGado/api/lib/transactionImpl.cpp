#include "../includes/transactionImpl.h"

TransactionBody::TransactionBody(){}

TransactionBody::~TransactionBody(){}

void TransactionBody::setNumber(QSqlQuery* query, int actual_transaction_number, int new_transaction_number){
    QString actual_number = QString::number(actual_transaction_number);
    QString new_number = QString::number(new_transaction_number);

    query->exec("update financial set number="+new_number+" where number="+actual_number);
}

QString TransactionBody::getNumber(QSqlQuery* query, int transaction_number) const{
    QString number = QString::number(transaction_number);

    query->exec("select * from financial where number="+number);
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

void TransactionBody::setValue(QSqlQuery* query, int transaction_number, double transaction_value){
    QString number = QString::number(transaction_number);
    QString value = QString::number(transaction_value);

    query->exec("update financial set value="+value+" where number="+number);
}

QString TransactionBody::getValue(QSqlQuery* query, int transaction_number) const{
    QString number = QString::number(transaction_number);

    query->exec("select * from financial where number="+number);
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

void TransactionBody::setDescription(QSqlQuery* query, int transaction_number, std::string transaction_description){
    QString number = QString::number(transaction_number);
    QString description = QString::fromStdString(transaction_description);

    query->exec("update financial set description='"+description+"' where number="+number);
}

QString TransactionBody::getDescription(QSqlQuery* query, int transaction_number) const{
    QString number = QString::number(transaction_number);

    query->exec("select * from financial where number="+number);
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

void TransactionBody::setDate(QSqlQuery* query, int transaction_number, std::string transaction_date){
    QString number = QString::number(transaction_number);
    QString date = QString::fromStdString(transaction_date);

    query->exec("update financial set date='"+date+"' where number="+number);
}

QString TransactionBody::getDate(QSqlQuery* query, int transaction_number) const{
    QString number = QString::number(transaction_number);

    query->exec("select * from financial where number="+number);
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

void TransactionBody::setCattleEarring(QSqlQuery* query, int transaction_number, int transaction_cattle_earring){
    QString number = QString::number(transaction_number);
    QString cattle_earring = QString::number(transaction_cattle_earring);

    query->exec("update financial set cattle_earring="+cattle_earring+" where number="+number);
}

QString TransactionBody::getCattleEarring(QSqlQuery* query, int transaction_number) const{
    QString number = QString::number(transaction_number);

    query->exec("select * from financial where number="+number);
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
