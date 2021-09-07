/*!
 \file farmImpl.h
 \brief This file contains the handle/body of a Farm for the GiroDeGado software.
*/

#ifndef FARMIMPL_H
#define FARMIMPL_H

#include "./farm.h"
#include "../includes/transactionImpl.h"
#include "../includes/cattleImpl.h"
#include "./handlebody.h"
#include "lib_global.h"

/** 
 * \brief
 * This Class represents the body of a Handle/Body idiom of a Farm for the GiroDeGado software.
*/
class LIB_EXPORT FarmBody : public Body{

    protected:
        static Farm* farm_; /*!< The singleton farm. */
        QSqlQuery* query_; /*!< The query of the GiroDeGado's database. */

    private:
        // No copy allowed

        /*!
            This is the copy constructor for the FarmBody Class.
            \param farm the FarmBody that is going to be cloned.
        */
        FarmBody (const FarmBody& farm);

        /*!
            This is the overloaded assignment operator for the FarmBody Class.
            \param farm the FarmHandle that is going to be cloned.
        */
        FarmBody& operator=(const FarmBody& farm);

    public:
        /*!
            This is the default constructor for the FarmBody Class.
            \param query the query of a database.
            \return FarmBody - a FarmBody Class object.
        */
        FarmBody(QSqlQuery* query = NULL);

        /*!
            This is the default destructor for the FarmBody Class.
        */
        virtual ~FarmBody();

        /*!
            Returns the singleton Farm.
            \param query the query of a database.
            \return Farm* - the pointer to the singleton Farm.
        */
        static Farm* getFarm(QSqlQuery* query = NULL);

        /*!
            Sets the query attribute in the Farm Class.
            \param query the query of a database.
        */
        void setQuery(QSqlQuery* query);

        /*!
            Returns the query attribute in the Farm Class.
            \return QSqlQuery* - the content query attribute.  
        */
        QSqlQuery* getQuery() const;

        /*!
            Executes the exec() method of the query.
            \param command the command that will be executed by the query.
            \return bool - if the method was successful or not. 
        */
        bool queryExec(QString command);

        /*!
            Executes the next() method of the query.
            \return bool - if the method was successful or not. 
        */
        bool queryNext();

        /*!
            Executes the first() method of the query.
            \return bool - if the method was successful or not. 
        */
        bool queryFirst();

        /*!
            Executes the value(pos).toString() methods of the query.
            \param pos the position of the field in the current record.
            \return QString - the value of the field in the current record, converted to a QString. 
        */
        QString queryValue(int pos);
        
        /*!
            Creates a cattle and adds it to the database.
            \param earring the earring of the Cattle.
            \param breed the breed of the Cattle.
            \param acquisition_date the acquisition date of the Cattle.
            \param birth_date the birth date of the Cattle.
            \param father the father's earring of the Cattle.
            \param mother the mother's earring of the Cattle.
            \param weight the weight of the Cattle.
            \param value the value of the Cattle.
        */
        void createCattle(int earring = 0, std::string breed = "", std::string acquisition_date = "",
                          std::string birth_date = "", int father = 0, int mother = 0, double weight = 0.0,
                          double value = 0.0);
        
        /*!
            Creates a transaction and adds it to the database.
            \param id the id of the Transaction.
            \param value the value of the Transaction.
            \param description the description of the Transaction.
            \param date the date of the Transaction.
            \param cattle_earring the cattle's earring of the Transaction.
        */
        void createTransaction(int number = 0, double value = 0.0, std::string description = "",
                               std::string date = "", int cattle_earring = 0);
        
        /*!
            Creates a user and adds it to the database.
            \param nickname the nickname of the User.
            \param name the name of the User.
            \param password the password of the User.
            \param birth_date the birth_date of the User.
            \param type the type of the User.
        */
        void createUser(std::string nickname = "", std::string name = "", std::string password = "",
                                std::string birth_date = "", std::string type = "");

        /*!
            Creates a Farm and returns it's pointer.
            \return Farm - a Farm Class object.
        */
        static Farm* createFarm(QSqlQuery* query = NULL);

        /*!        
           Deletes a cattle from the database.
           \param cattle_earring earring of the cattle that will be deleted.
        */ 
        void deleteCattle(int cattle_earring);
      
        /*!
           Deletes a transaction from the database.
           \param transaction_number number of the transaction that will be deleted.
        */
        void deleteTransaction(int transaction_number);

        /*!
           Deletes a user from the database.
           \param user_nickname nickname of the user that will be deleted.
        */
        void deleteUser(std::string user_nickname);

        /*!
            Sets the earring of a registered Cattle in the database.
            \param actual_cattle_earring the earring of the Cattle.
            \param new_cattle_earring which will be set to the Cattle.
        */
        void setCattleEarring(int actual_cattle_earring, int new_cattle_earring);

        /*!
            Returns the earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content earring attribute.  
        */
        QString getCattleEarring(int cattle_earring) const;
        
        /*!
            Sets the breed of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_breed which will be set to the Cattle.
        */
        void setCattleBreed(int cattle_earring, std::string cattle_breed);

        /*!
            Returns the breed of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content Breed attribute.  
        */
        QString getCattleBreed(int cattle_earring) const;

        /*!
            Sets the acquisition date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_acquisition_date which will be set to the Cattle.
        */
        void setCattleAcquisitionDate(int cattle_earring, std::string cattle_acquisition_date);

        /*!
            Returns the acquisition date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content acquisition date attribute.  
        */
        QString getCattleAcquisitionDate(int cattle_earring) const;

        /*!
            Sets the birth date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_birth_date which will be set to the Cattle.
        */
        void setCattleBirthDate(int cattle_earring, std::string cattle_birth_date);

        /*!
            Returns the birth date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content birth date attribute.  
        */
        QString getCattleBirthDate(int cattle_earring) const;

        /*!
            Sets the father's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_father which will be set to the Cattle.
        */
        void setCattleFather(int cattle_earring, int cattle_father);

        /*!
            Returns the father's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content father attribute.  
        */
        QString getCattleFather(int cattle_earring) const;

        /*!
            Sets the mother's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_mother which will be set to the Cattle.
        */
        void setCattleMother(int cattle_earring, int cattle_mother);

        /*!
            Returns the mother's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content mother attribute.  
        */
        QString getCattleMother(int cattle_earring) const;

        /*!
            Sets the weight of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_weight which will be set to the Cattle.
        */
        void setCattleWeight(int cattle_earring, double cattle_weight);

        /*!
            Returns the weight of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content weight attribute.  
        */
        QString getCattleWeight(int cattle_earring) const;

        /*!
            Sets the value of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_value which will be set to the Cattle.
        */
        void setCattleValue(int cattle_earring, double cattle_value);

        /*!
            Returns the value of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content value attribute.  
        */
        QString getCattleValue(int cattle_earring) const;

        /*!
            Sets the number of a registered Transaction in the database.
            \param actual_transaction_number the number of the Transaction.
            \param new_transaction_number which will be set to the Transaction.
        */
        void setTransactionNumber(int actual_transaction_number, int new_transaction_number);

        /*!
            Returns the number of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content number attribute.
        */
        QString getTransactionNumber(int transaction_number) const;

        /*!
            Sets the value of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_value which will be set to the Transaction.
        */
        void setTransactionValue(int transaction_number, double transaction_value);

        /*!
            Returns the value of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content value attribute.  
        */
        QString getTransactionValue(int transaction_number) const;
        
        /*!
            Sets the description of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_description which will be set to the Transaction.
        */
        void setTransactionDescription(int transaction_number, std::string transaction_description);

        /*!
            Returns the description of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content description attribute.  
        */
        QString getTransactionDescription(int transaction_number) const;

        /*!
            Sets the date of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_date which will be set to the Transaction.
        */
        void setTransactionDate(int transaction_number, std::string transaction_date);

        /*!
            Returns the date of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content date attribute.  
        */
        QString getTransactionDate(int transaction_number) const;

        /*!
            Sets the cattle earring of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_cattle_earring which will be set to the Transaction.
        */
        void setTransactionCattleEarring(int transaction_number, int transaction_cattle_earring);

        /*!
            Returns the cattle earring of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content cattle earring attribute.  
        */
        QString getTransactionCattleEarring(int transaction_number) const;

        /*!
            Sets the nickname of a registered User in the database.
            \param actual_user_nickname the nickname of the current User.
            \param new_user_nickname which will be set to the current User.
        */
        void setUserNickname(std::string actual_user_nickname, std::string new_user_nickname);

        /*!
            Returns the nickname of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \return QString - the content nickname attribute.  
        */
        QString getUserNickname(std::string user_nickname) const;

        /*!
            Sets the name of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_name which will be set to the current User.
        */
        void setUserName(std::string user_nickname, std::string user_name);

        /*!
            Returns the name of a registered User in the database.
            \param user_nickname the name of the current User.
            \return QString - the content name attribute.  
        */
        QString getUserName(std::string user_nickname) const;

        /*!
            Sets the password of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_password which will be set to the current User.
        */
        void setUserPassword(std::string user_nickname, std::string user_password);

        /*!
            Returns the password of a registered User in the database.
            \param user_nickname the password of the current User.
            \return QString - the content password attribute.  
        */
        QString getUserPassword(std::string user_nickname) const;

        /*!
            Sets the date of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_date which will be set to the current User.
        */
        void setUserDate(std::string user_nickname, std::string user_date);

        /*!
            Returns the date of a registered User in the database.
            \param user_nickname the date of the current User.
            \return QString - the content date attribute.  
        */
        QString getUserDate(std::string user_nickname) const;

        /*!
            Sets the type of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_type which will be set to the current User.
        */
        void setUserType(std::string user_nickname, std::string user_type);

        /*!
            Returns the type of a registered User in the database.
            \param user_nickname the type of the current User.
            \return QString - the content type attribute.  
        */
        QString getUserType(std::string user_nickname) const;

        /*!
            Returns the last available earring on the cattle table from the database.
            \return int - the last available earring on the cattle table from the database.
        */
        int getLastEarringAvailable();

        /*!
            Returns the last available number on the financial table from the database.
            \return int - the last available number on the financial table from the database.
        */
        int getLastNumberAvailable();

};

/** 
 * \brief
 * This Class represents the handle of a Handle/Body idiom of a Farm for the GiroDeGado software implemented in this code.
*/
class LIB_EXPORT FarmHandle : public Handle<FarmBody>, public Farm{

    protected:

        /*!
            This is the default constructor for the FarmHandle Class.
            \param query the query of a database.
            \return FarmHandle - a FarmHandle Class object.
        */
        FarmHandle(QSqlQuery* query = NULL){
            pImpl_->setQuery(query);
        };

        // No copy allowed

        /*!
            This is the copy constructor for the FarmHandle Class.
            \param farm the FarmHandle that is going to be cloned.
        */
        FarmHandle(FarmHandle& farm) = delete;

        /*!
            This is the overloaded assignment operator for the FarmHandle Class.
            \param farm the FarmHandle that is going to be cloned.
        */
        FarmHandle& operator=(const FarmHandle& farm) = delete;

    public:
        friend class FarmBody;

        /*!
            This is the default destructor for the FarmHandle Class.
        */
        virtual ~FarmHandle(){};

        /*!
            Returns the singleton Farm.
            \param query the query of a database.
            \return Farm* - the pointer to the singleton Farm.
        */
        static Farm* getFarm(QSqlQuery* query = NULL){
            return FarmBody::getFarm(query);
        }

        /*!
            Sets the query attribute in the Farm Class.
            \param query the query of a database.
        */
        void setQuery(QSqlQuery* query){
            pImpl_->setQuery(query);
        }

        /*!
            Returns the query attribute in the Farm Class.
            \return QSqlQuery* - the content query attribute.  
        */
        QSqlQuery* getQuery() const{
            return pImpl_->getQuery();
        }

        /*!
            Executes the exec() method of the query.
            \param command the command that will be executed by the query.
            \return bool - if the method was successful or not. 
        */
        bool queryExec(QString command){
            return pImpl_->queryExec(command);
        }

        /*!
            Executes the next() method of the query.
            \return bool - if the method was successful or not. 
        */
        bool queryNext(){
            return pImpl_->queryNext();
        }

        /*!
            Executes the first() method of the query.
            \return bool - if the method was successful or not. 
        */
        bool queryFirst(){
            return pImpl_->queryFirst();
        }

        /*!
            Executes the value(pos).toString() methods of the query.
            \param pos the position of the field in the current record.
            \return QString - the value of the field in the current record, converted to a QString. 
        */
        QString queryValue(int pos){
            return pImpl_->queryValue(pos);
        }
        
        /*!
            Calls the createCattle() method implemented in the FarmBody Class.
            \param earring the earring of the Cattle.
            \param breed the breed of the Cattle.
            \param acquisition_date the acquisition date of the Cattle.
            \param birth_date the birth date of the Cattle.
            \param father the father's earring of the Cattle.
            \param mother the mother's earring of the Cattle.
            \param weight the weight of the Cattle.
            \param value the value of the Cattle.
        */
        void createCattle(int earring = 0, std::string breed = "", std::string acquisition_date = "",
                          std::string birth_date = "", int father = 0, int mother = 0, double weight = 0.0,
                          double value = 0.0){
            pImpl_->createCattle(earring, breed, acquisition_date, birth_date, father, mother, weight, value);
        }
        
        /*!
            Calls the createTransaction() method implemented in the FarmBody Class.
            \param id the id of the Transaction.
            \param value the value of the Transaction.
            \param description the description of the Transaction.
            \param date the date of the Transaction.
            \param cattle_earring the cattle's earring of the Transaction.
        */
        void createTransaction(int number = 0, double value = 0.0, std::string description = "",
                               std::string date = "", int cattle_earring = 0){
            pImpl_->createTransaction(number, value, description, date, cattle_earring);
        }

        /*!
            Calls the createUser() method implemented in the FarmBody Class.
            \param nickname the nickname of the User.
            \param name the name of the User.
            \param password the password of the User.
            \param birth_date the birth_date of the User.
            \param type the type of the User.
        */
        void createUser(std::string nickname = "", std::string name = "", std::string password = "",
                        std::string birth_date = "", std::string type = ""){
            pImpl_->createUser(nickname, name, password, birth_date, type);
        }

        /*!
            Calls the createFarm() method implemented in the FarmBody Class.
            \return Farm - a Farm Class object.
        */
        static Farm* createFarm(QSqlQuery* query = NULL){
            return FarmBody::createFarm(query);
        }

        /*!        
           Calls the deleteCattle() method implemented in the FarmBody Class.
           \param cattle_earring earring of the cattle that will be deleted.
        */ 
        void deleteCattle(int cattle_earring){
            pImpl_->deleteCattle(cattle_earring);
        }
      
        /*!
           Calls the deleteTransaction() method implemented in the FarmBody Class.
           \param transaction_number number of the transaction that will be deleted.
        */
        void deleteTransaction(int transaction_number){
            pImpl_->deleteTransaction(transaction_number);
        }

        /*!
           Calls the deleteUser() method implemented in the FarmBody Class.
           \param user_nickname nickname of the user that will be deleted.
        */
        void deleteUser(std::string user_nickname){
            pImpl_->deleteUser(user_nickname);
        }

        /*!
            Calls the setCattleEarring() method implemented in the FarmBody Class.
            \param actual_cattle_earring the earring of the Cattle.
            \param new_cattle_earring which will be set to the Cattle.
        */
        void setCattleEarring(int actual_cattle_earring, int new_cattle_earring){
            pImpl_->setCattleEarring(actual_cattle_earring, new_cattle_earring);
        }

        /*!
            Calls the getCattleEarring() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content earring attribute.  
        */
        QString getCattleEarring(int cattle_earring) const{
            return pImpl_->getCattleEarring(cattle_earring);
        }
        
        /*!
            Calls the setCattleBreed() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \param cattle_breed which will be set to the Cattle.
        */
        void setCattleBreed(int cattle_earring, std::string cattle_breed){
            pImpl_->setCattleBreed(cattle_earring, cattle_breed);
        }

        /*!
            Calls the getCattleBreed() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content Breed attribute.  
        */
        QString getCattleBreed(int cattle_earring) const{
            return pImpl_->getCattleBreed(cattle_earring);
        }

        /*!
            Calls the setCattleAcquisitionDate() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \param cattle_acquisition_date which will be set to the Cattle.
        */
        void setCattleAcquisitionDate(int cattle_earring, std::string cattle_acquisition_date){
            pImpl_->setCattleAcquisitionDate(cattle_earring, cattle_acquisition_date);
        }

        /*!
            Calls the getCattleAcquisitionDate() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content acquisition date attribute.  
        */
        QString getCattleAcquisitionDate(int cattle_earring) const{
            return pImpl_->getCattleAcquisitionDate(cattle_earring);
        }

        /*!
            Calls the setCattleBirthDate() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \param cattle_birth_date which will be set to the Cattle.
        */
        void setCattleBirthDate(int cattle_earring, std::string cattle_birth_date){
            pImpl_->setCattleBirthDate(cattle_earring, cattle_birth_date);
        }

        /*!
            Calls the getCattleBirthDate() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content birth date attribute.  
        */
        QString getCattleBirthDate(int cattle_earring) const{
            return pImpl_->getCattleBirthDate(cattle_earring);
        }

        /*!
            Calls the setCattleFather() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \param cattle_father which will be set to the Cattle.
        */
        void setCattleFather(int cattle_earring, int cattle_father){
            pImpl_->setCattleFather(cattle_earring, cattle_father);
        }

        /*!
            Calls the getCattleFather() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content father attribute.  
        */
        QString getCattleFather(int cattle_earring) const{
            return pImpl_->getCattleFather(cattle_earring);
        }

        /*!
            Calls the setCattleMother() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \param cattle_mother which will be set to the Cattle.
        */
        void setCattleMother(int cattle_earring, int cattle_mother){
            pImpl_->setCattleMother(cattle_earring, cattle_mother);
        }

        /*!
            Calls the getCattleMother() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content mother attribute.  
        */
        QString getCattleMother(int cattle_earring) const{
            return pImpl_->getCattleMother(cattle_earring);
        }

        /*!
            Calls the setCattleWeight() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \param cattle_weight which will be set to the Cattle.
        */
        void setCattleWeight(int cattle_earring, double cattle_weight){
            pImpl_->setCattleWeight(cattle_earring, cattle_weight);
        }

        /*!
            Calls the getCattleWeight() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content weight attribute.  
        */
        QString getCattleWeight(int cattle_earring) const{
            return pImpl_->getCattleWeight(cattle_earring);
        }

        /*!
            Calls the setCattleValue() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \param cattle_value which will be set to the Cattle.
        */
        void setCattleValue(int cattle_earring, double cattle_value){
            pImpl_->setCattleValue(cattle_earring, cattle_value);
        }

        /*!
            Calls the getCattleValue() method implemented in the FarmBody Class.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content value attribute.  
        */
        QString getCattleValue(int cattle_earring) const{
            return pImpl_->getCattleValue(cattle_earring);
        }

        /*!
            Calls the setTransactionNumber() method implemented in the FarmBody Class.
            \param actual_transaction_number the number of the Transaction.
            \param new_transaction_number which will be set to the Transaction.
        */
        void setTransactionNumber(int actual_transaction_number, int new_transaction_number){
            pImpl_->setTransactionNumber(actual_transaction_number, new_transaction_number);
        }

        /*!
            Calls the getTransactionNumber() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \return QString - the content number attribute.
        */
        QString getTransactionNumber(int transaction_number) const{
            return pImpl_->getTransactionNumber(transaction_number);
        }

        /*!
            Calls the setTransactionValue() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \param transaction_value which will be set to the Transaction.
        */
        void setTransactionValue(int transaction_number, double transaction_value){
            pImpl_->setTransactionValue(transaction_number, transaction_value);
        }

        /*!
            Calls the getTransactionValue() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \return QString - the content value attribute.  
        */
        QString getTransactionValue(int transaction_number) const{
            return pImpl_->getTransactionValue(transaction_number);
        }
        
        /*!
            Calls the setTransactionDescription() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \param transaction_description which will be set to the Transaction.
        */
        void setTransactionDescription(int transaction_number, std::string transaction_description){
            pImpl_->setTransactionDescription(transaction_number, transaction_description);
        }

        /*!
            Calls the getTransactionDescription() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \return QString - the content description attribute.  
        */
        QString getTransactionDescription(int transaction_number) const{
            return pImpl_->getTransactionDescription(transaction_number);
        }

        /*!
            Calls the setTransactionDate() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \param transaction_date which will be set to the Transaction.
        */
        void setTransactionDate(int transaction_number, std::string transaction_date){
            pImpl_->setTransactionDate(transaction_number, transaction_date);
        }

        /*!
            Calls the getTransactionDate() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \return QString - the content date attribute.  
        */
        QString getTransactionDate(int transaction_number) const{
            return pImpl_->getTransactionDate(transaction_number);
        }

        /*!
            Calls the setTransactionCattleEarring() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \param transaction_cattle_earring which will be set to the Transaction.
        */
        void setTransactionCattleEarring(int transaction_number, int transaction_cattle_earring){
            pImpl_->setTransactionCattleEarring(transaction_number, transaction_cattle_earring);
        }

        /*!
            Calls the getTransactionCattleEarring() method implemented in the FarmBody Class.
            \param transaction_number the number of the Transaction.
            \return QString - the content cattle earring attribute.  
        */
        QString getTransactionCattleEarring(int transaction_number) const{
            return pImpl_->getTransactionCattleEarring(transaction_number);
        }

        /*!
            Calls the setUserNickname() method implemented in the FarmBody Class.
            \param actual_user_nickname the nickname of the current User.
            \param new_user_nickname which will be set to the current User.
        */
        void setUserNickname(std::string actual_user_nickname, std::string new_user_nickname){
            pImpl_->setUserNickname(actual_user_nickname, new_user_nickname);
        }

        /*!
            Calls the getUserNickname() method implemented in the FarmBody Class.
            \param user_nickname the nickname of the current User.
            \return QString - the content nickname attribute.  
        */
        QString getUserNickname(std::string user_nickname) const{
            return pImpl_->getUserNickname(user_nickname);
        }

        /*!
            Calls the setUserName() method implemented in the FarmBody Class.
            \param user_nickname the nickname of the current User.
            \param user_name which will be set to the current User.
        */
        void setUserName(std::string user_nickname, std::string user_name){
            pImpl_->setUserName(user_nickname, user_name);
        }

        /*!
            Calls the getUserName() method implemented in the FarmBody Class.
            \param user_nickname the name of the current User.
            \return QString - the content name attribute.  
        */
        QString getUserName(std::string user_nickname) const{
            return pImpl_->getUserName(user_nickname);
        }

        /*!
            Calls the setUserPassword() method implemented in the FarmBody Class.
            \param user_nickname the nickname of the current User.
            \param user_password which will be set to the current User.
        */
        void setUserPassword(std::string user_nickname, std::string user_password){
            pImpl_->setUserPassword(user_nickname, user_password);
        }

        /*!
            Calls the getUserPassword() method implemented in the FarmBody Class.
            \param user_nickname the password of the current User.
            \return QString - the content password attribute.  
        */
        QString getUserPassword(std::string user_nickname) const{
            return pImpl_->getUserPassword(user_nickname);
        }

        /*!
            Calls the setUserDate() method implemented in the FarmBody Class.
            \param user_nickname the nickname of the current User.
            \param user_date which will be set to the current User.
        */
        void setUserDate(std::string user_nickname, std::string user_date){
            pImpl_->setUserDate(user_nickname, user_date);
        }

        /*!
            Calls the getUserDate() method implemented in the FarmBody Class.
            \param user_nickname the date of the current User.
            \return QString - the content date attribute.  
        */
        QString getUserDate(std::string user_nickname) const{
            return pImpl_->getUserDate(user_nickname);
        }

        /*!
            Calls the setUserType() method implemented in the FarmBody Class.
            \param user_nickname the nickname of the current User.
            \param user_type which will be set to the current User.
        */
        void setUserType(std::string user_nickname, std::string user_type){
            pImpl_->setUserType(user_nickname, user_type);
        }

        /*!
            Calls the getUserType() method implemented in the FarmBody Class.
            \param user_nickname the type of the current User.
            \return QString - the content type attribute.  
        */
        QString getUserType(std::string user_nickname) const{
            return pImpl_->getUserType(user_nickname);
        }

        /*!
            Calls the getLastEarringAvailable() method implemented in the FarmBody Class.
            \return int - the last available earring on the cattle table from the database.
        */
        int getLastEarringAvailable(){
            return pImpl_->getLastEarringAvailable();
        }

        /*!
            Calls the getLastNumberAvailable() method implemented in the FarmBody Class.
            \return int - the last available number on the financial table from the database.
        */
        int getLastNumberAvailable(){
            return pImpl_->getLastNumberAvailable();
        }

};

#endif
