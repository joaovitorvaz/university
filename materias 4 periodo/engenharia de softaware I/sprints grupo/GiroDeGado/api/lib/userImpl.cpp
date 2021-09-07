#include "../includes/userImpl.h"

UserBody::UserBody(){}

UserBody::~UserBody(){}

void UserBody::setNickname(QSqlQuery* query, std::string actual_user_nickname, std::string new_user_nickname){
    QString actual_nickname = QString::fromStdString(actual_user_nickname);
    QString new_nickname = QString::fromStdString(new_user_nickname);

    query->exec("update users set nickname='"+new_nickname+"' where nickname='"+actual_nickname+"'");
}

QString UserBody::getNickname(QSqlQuery* query, std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query->exec("select * from users where nickname='"+nickname+"'");
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

void UserBody::setName(QSqlQuery* query, std::string user_nickname, std::string user_name){
    QString nickname = QString::fromStdString(user_nickname);
    QString name = QString::fromStdString(user_name);

    query->exec("update users set name='"+name+"' where nickname='"+nickname+"'");
}

QString UserBody::getName(QSqlQuery* query, std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query->exec("select * from users where nickname='"+nickname+"'");
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

void UserBody::setPassword(QSqlQuery* query, std::string user_nickname, std::string user_password){
    QString nickname = QString::fromStdString(user_nickname);
    QString password = QString::fromStdString(user_password);

    query->exec("update users set password='"+password+"' where nickname='"+nickname+"'");
}

QString UserBody::getPassword(QSqlQuery* query, std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query->exec("select * from users where nickname='"+nickname+"'");
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

void UserBody::setDate(QSqlQuery* query, std::string user_nickname, std::string user_date){
    QString nickname = QString::fromStdString(user_nickname);
    QString date = QString::fromStdString(user_date);

    query->exec("update users set birth_date='"+date+"' where nickname='"+nickname+"'");
}

QString UserBody::getDate(QSqlQuery* query, std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query->exec("select * from users where nickname='"+nickname+"'");
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

void UserBody::setType(QSqlQuery* query, std::string user_nickname, std::string user_type){
    QString nickname = QString::fromStdString(user_nickname);
    QString type = QString::fromStdString(user_type);
    
    query->exec("update users set type='"+type+"' where nickname='"+nickname+"'");
}

QString UserBody::getType(QSqlQuery* query, std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query->exec("select * from users where nickname='"+nickname+"'");
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
