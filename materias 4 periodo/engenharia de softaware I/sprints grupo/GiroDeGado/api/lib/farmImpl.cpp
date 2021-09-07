#include "../includes/farmImpl.h"

Farm* FarmBody::farm_ = NULL;

Farm* Farm::getFarm(QSqlQuery* query){
    return FarmHandle::getFarm(query);
}

Farm* FarmBody::getFarm(QSqlQuery* query){
    if (farm_ == NULL){
        farm_ = new FarmHandle(query);
    }
    return farm_;
}

FarmBody::FarmBody(QSqlQuery* query){
    setQuery(query);
}

FarmBody::~FarmBody(){}

void FarmBody::setQuery(QSqlQuery* query){
    query_ = query;
}

QSqlQuery* FarmBody::getQuery() const{
    return query_;
}

bool FarmBody::queryExec(QString command){
    return query_->exec(command);
}

bool FarmBody::queryNext(){
    return query_->next();
}

bool FarmBody::queryFirst(){
    return query_->first();
}

QString FarmBody::queryValue(int pos){
    return query_->value(pos).toString();
}

void FarmBody::createCattle(int earring, std::string breed, std::string acquisition_date, std::string birth_date,
                            int father, int mother, double weight, double value){
    query_->prepare("insert into cattle (earring, breed, acquisition_date, birth_date, father, mother, weight, value)"
                   "values (:earring, :breed, :acquisition_date, :birth_date, :father, :mother, :weight, :value)");
    query_->bindValue(":earring", earring);
    query_->bindValue(":breed", QString::fromStdString(breed));
    query_->bindValue(":acquisition_date", QString::fromStdString(acquisition_date));
    query_->bindValue(":birth_date", QString::fromStdString(birth_date));
    query_->bindValue(":father", father);
    query_->bindValue(":mother", mother);
    query_->bindValue(":weight", weight);
    query_->bindValue(":value", value);
    query_->exec();
}

void FarmBody::createTransaction(int number, double value, std::string description,
                                 std::string date, int cattle_earring){
    query_->prepare("insert into financial (number, value, description, date, cattle_earring)"
                   "values (:number, :value, :description, :date, :cattle_earring)");
    query_->bindValue(":number", number);
    query_->bindValue(":value", value);
    query_->bindValue(":description", QString::fromStdString(description));
    query_->bindValue(":date", QString::fromStdString(date));
    query_->bindValue(":cattle_earring", cattle_earring);
    query_->exec();
}

void FarmBody::createUser(std::string nickname, std::string name, std::string password,
                          std::string birth_date, std::string type){
    query_->prepare("insert into users (nickname, name, password, birth_date, type)"
                   "values (:nickname, :name, :password, :birth_date, :type)");
    query_->bindValue(":nickname", QString::fromStdString(nickname));
    query_->bindValue(":name", QString::fromStdString(name));
    query_->bindValue(":password", QString::fromStdString(password));
    query_->bindValue(":birth_date", QString::fromStdString(birth_date));
    query_->bindValue(":type", QString::fromStdString(type));
    query_->exec();
}

void FarmBody::deleteCattle(int cattle_earring){
    QString earring = QString::number(cattle_earring);

    query_->exec("delete from cattle where earring="+earring);
}

void FarmBody::deleteTransaction(int transaction_number){
    QString number = QString::number(transaction_number);

    query_->exec("delete from financial where number="+number);
}

void FarmBody::deleteUser(std::string user_nickname){
    QString nickname = QString::fromStdString(user_nickname);

    query_->exec("delete from users where nickname='"+nickname+"'");
}

void FarmBody::setCattleEarring(int actual_cattle_earring, int new_cattle_earring){
    QString actual_earring = QString::number(actual_cattle_earring);
    QString new_earring = QString::number(new_cattle_earring);

    query_->exec("update cattle set earring="+new_earring+" where earring="+actual_earring);
}

QString FarmBody::getCattleEarring(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(1).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setCattleBreed(int cattle_earring, std::string cattle_breed){
    QString earring = QString::number(cattle_earring);
    QString breed = QString::fromStdString(cattle_breed);

    query_->exec("update cattle set breed='"+breed+"' where earring="+earring);
}

QString FarmBody::getCattleBreed(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(2).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setCattleAcquisitionDate(int cattle_earring, std::string cattle_acquisition_date){
    QString earring = QString::number(cattle_earring);
    QString acquisition_date = QString::fromStdString(cattle_acquisition_date);

    query_->exec("update cattle set acquisition_date='"+acquisition_date+"' where earring="+earring);
}

QString FarmBody::getCattleAcquisitionDate(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(3).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setCattleBirthDate(int cattle_earring, std::string cattle_birth_date){
    QString earring = QString::number(cattle_earring);
    QString birth_date = QString::fromStdString(cattle_birth_date);

    query_->exec("update cattle set birth_date='"+birth_date+"' where earring="+earring);
}

QString FarmBody::getCattleBirthDate(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(4).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setCattleFather(int cattle_earring, int cattle_father){
    QString earring = QString::number(cattle_earring);
    QString father = QString::number(cattle_father);

    query_->exec("update cattle set father="+father+" where earring="+earring);
}

QString FarmBody::getCattleFather(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(5).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setCattleMother(int cattle_earring, int cattle_mother){
    QString earring = QString::number(cattle_earring);
    QString mother = QString::number(cattle_mother);

    query_->exec("update cattle set mother="+mother+" where earring="+earring);
}

QString FarmBody::getCattleMother(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(6).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setCattleWeight(int cattle_earring, double cattle_weight){
    QString earring = QString::number(cattle_earring);
    QString weight = QString::number(cattle_weight);

    query_->exec("update cattle set weight="+weight+" where earring="+earring);
}

QString FarmBody::getCattleWeight(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(7).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setCattleValue(int cattle_earring, double cattle_value){
    QString earring = QString::number(cattle_earring);
    QString value = QString::number(cattle_value);

    query_->exec("update cattle set value="+value+" where earring="+earring);
}

void FarmBody::setTransactionNumber(int actual_transaction_number, int new_transaction_number){
    QString actual_number = QString::number(actual_transaction_number);
    QString new_number = QString::number(new_transaction_number);

    query_->exec("update financial set number="+new_number+" where number="+actual_number);
}

QString FarmBody::getTransactionNumber(int transaction_number) const{
    QString number = QString::number(transaction_number);

    query_->exec("select * from financial where number="+number);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(1).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setTransactionValue(int transaction_number, double transaction_value){
    QString number = QString::number(transaction_number);
    QString value = QString::number(transaction_value);

    query_->exec("update financial set value="+value+" where number="+number);
}

QString FarmBody::getTransactionValue(int transaction_number) const{
    QString number = QString::number(transaction_number);

    query_->exec("select * from financial where number="+number);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(3).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setTransactionDescription(int transaction_number, std::string transaction_description){
    QString number = QString::number(transaction_number);
    QString description = QString::fromStdString(transaction_description);

    query_->exec("update financial set description='"+description+"' where number="+number);
}

QString FarmBody::getTransactionDescription(int transaction_number) const{
    QString number = QString::number(transaction_number);

    query_->exec("select * from financial where number="+number);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(5).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setTransactionDate(int transaction_number, std::string transaction_date){
    QString number = QString::number(transaction_number);
    QString date = QString::fromStdString(transaction_date);

    query_->exec("update financial set date='"+date+"' where number="+number);
}

QString FarmBody::getTransactionDate(int transaction_number) const{
    QString number = QString::number(transaction_number);

    query_->exec("select * from financial where number="+number);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(2).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setTransactionCattleEarring(int transaction_number, int transaction_cattle_earring){
    QString number = QString::number(transaction_number);
    QString cattle_earring = QString::number(transaction_cattle_earring);

    query_->exec("update financial set cattle_earring="+cattle_earring+" where number="+number);
}

QString FarmBody::getTransactionCattleEarring(int transaction_number) const{
    QString number = QString::number(transaction_number);

    query_->exec("select * from financial where number="+number);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(4).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

QString FarmBody::getCattleValue(int cattle_earring) const{
    QString earring = QString::number(cattle_earring);

    query_->exec("select * from cattle where earring="+earring);
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(8).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setUserNickname(std::string actual_user_nickname, std::string new_user_nickname){
    QString actual_nickname = QString::fromStdString(actual_user_nickname);
    QString new_nickname = QString::fromStdString(new_user_nickname);

    query_->exec("update users set nickname='"+new_nickname+"' where nickname='"+actual_nickname+"'");
}

QString FarmBody::getUserNickname(std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query_->exec("select * from users where nickname='"+nickname+"'");
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(1).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setUserName(std::string user_nickname, std::string user_name){
    QString nickname = QString::fromStdString(user_nickname);
    QString name = QString::fromStdString(user_name);

    query_->exec("update users set name='"+name+"' where nickname='"+nickname+"'");
}

QString FarmBody::getUserName(std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query_->exec("select * from users where nickname='"+nickname+"'");
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(2).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setUserPassword(std::string user_nickname, std::string user_password){
    QString nickname = QString::fromStdString(user_nickname);
    QString password = QString::fromStdString(user_password);

    query_->exec("update users set password='"+password+"' where nickname='"+nickname+"'");
}

QString FarmBody::getUserPassword(std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query_->exec("select * from users where nickname='"+nickname+"'");
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(3).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setUserDate(std::string user_nickname, std::string user_date){
    QString nickname = QString::fromStdString(user_nickname);
    QString date = QString::fromStdString(user_date);

    query_->exec("update users set birth_date='"+date+"' where nickname='"+nickname+"'");
}

QString FarmBody::getUserDate(std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query_->exec("select * from users where nickname='"+nickname+"'");
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(4).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

void FarmBody::setUserType(std::string user_nickname, std::string user_type){
    QString nickname = QString::fromStdString(user_nickname);
    QString type = QString::fromStdString(user_type);
    
    query_->exec("update users set type='"+type+"' where nickname='"+nickname+"'");
}

QString FarmBody::getUserType(std::string user_nickname) const{
    QString nickname = QString::fromStdString(user_nickname);

    query_->exec("select * from users where nickname='"+nickname+"'");
    int count = 0;
    while(query_->next()){
        count++;
    }
    if(count > 0){
        query_->first();
        return query_->value(5).toString();
    }
    else{
        QString empty("");
        return empty;
    }
}

int FarmBody::getLastEarringAvailable(){
    query_->exec("select max(earring) from cattle");
    query_->first();
    QString earring_str= query_->value(0).toString();
    int earring = 0;
    if(earring_str != "")
        earring = earring_str.toInt();
    earring++;

    return earring;
}

int FarmBody::getLastNumberAvailable(){
    query_->exec("select max(number) from financial");
    query_->first();
    QString number_str= query_->value(0).toString();
    int number = 0;
    if(number_str != "")
        number = number_str.toInt();
    number++;

    return number;
}
