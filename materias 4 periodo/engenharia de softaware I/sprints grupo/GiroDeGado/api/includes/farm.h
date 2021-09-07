/*!
 \file farm.h
 \brief This file contains the interface of a Farm for the GiroDeGado software.
*/

#ifndef FARM_H
#define FARM_H

#include <vector>
#include <QtSql/QtSql>
#include "lib_global.h"

/** 
 * \brief
 * This Class represents a Farm for the GiroDeGado software.
*/
class LIB_EXPORT Farm{

    public:

        /*!
            Returns the singleton Farm.
            \param query the query of a database.
            \return Farm* - the pointer to the singleton Farm.
        */
        static Farm* getFarm(QSqlQuery* query = NULL);

        /*!
            This is the default destructor for the Farm Class.
        */
        virtual ~Farm(){}

        /*!
            Sets the query attribute in the Farm Class.
            \param query the query of a database.
        */
        virtual void setQuery(QSqlQuery* query) = 0;

        /*!
            Returns the query attribute in the Farm Class.
            \return QSqlQuery* - the content query attribute.  
        */
        virtual QSqlQuery* getQuery() const = 0;

        /*!
            Executes the exec() method of the query.
            \param command the command that will be executed by the query.
            \return bool - if the method was successful or not. 
        */
        virtual bool queryExec(QString command) = 0;

        /*!
            Executes the next() method of the query.
            \return bool - if the method was successful or not. 
        */
        virtual bool queryNext() = 0;

        /*!
            Executes the first() method of the query.
            \return bool - if the method was successful or not. 
        */
        virtual bool queryFirst() = 0;

        /*!
            Executes the value(pos).toString() methods of the query.
            \param pos the position of the field in the current record.
            \return QString - the value of the field in the current record, converted to a QString. 
        */
        virtual QString queryValue(int pos) = 0;
        
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
        virtual void createCattle(int earring = 0, std::string breed = "", 
                                  std::string acquisition_date = "", std::string birth_date = "",
                                  int father = 0, int mother = 0, double weight = 0.0,
                                  double value = 0.0) = 0;
        
        /*!
            Creates a transaction and adds it to the database.
            \param id the id of the Transaction.
            \param value the value of the Transaction.
            \param description the description of the Transaction.
            \param date the date of the Transaction.
            \param cattle_earring the cattle's earring of the Transaction.
        */
        virtual void createTransaction(int number = 0, double value = 0.0, std::string description = "",
                                       std::string date = "", int cattle_earring = 0) = 0;

        /*!
            Creates a user and adds it to the database.
            \param nickname the nickname of the User.
            \param name the name of the User.
            \param password the password of the User.
            \param birth_date the birth_date of the User.
            \param type the type of the User.
        */
        virtual void createUser(std::string nickname = "", std::string name = "", std::string password = "",
                                std::string birth_date = "", std::string type = "") = 0;

        /*!        
           Deletes a cattle from the database.
           \param cattle_earring earring of the cattle that will be deleted.
        */ 
        virtual void deleteCattle(int cattle_earring) = 0;
      
        /*!
           Deletes a transaction from the database.
           \param transaction_number number of the transaction that will be deleted.
        */
        virtual void deleteTransaction(int transaction_number) = 0;

        /*!
           Deletes a user from the database.
           \param user_nickname nickname of the user that will be deleted.
        */
        virtual void deleteUser(std::string user_nickname) = 0;

        /*!
            Sets the earring of a registered Cattle in the database.
            \param actual_cattle_earring the earring of the Cattle.
            \param new_cattle_earring which will be set to the Cattle.
        */
        virtual void setCattleEarring(int actual_cattle_earring, int new_cattle_earring) = 0;

        /*!
            Returns the earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content earring attribute.  
        */
        virtual QString getCattleEarring(int cattle_earring) const = 0;
        
        /*!
            Sets the breed of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_breed which will be set to the Cattle.
        */
        virtual void setCattleBreed(int cattle_earring, std::string cattle_breed) = 0;

        /*!
            Returns the breed of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content Breed attribute.  
        */
        virtual QString getCattleBreed(int cattle_earring) const = 0;

        /*!
            Sets the acquisition date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_acquisition_date which will be set to the Cattle.
        */
        virtual void setCattleAcquisitionDate(int cattle_earring, std::string cattle_acquisition_date) = 0;

        /*!
            Returns the acquisition date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content acquisition date attribute.  
        */
        virtual QString getCattleAcquisitionDate(int cattle_earring) const = 0;

        /*!
            Sets the birth date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_birth_date which will be set to the Cattle.
        */
        virtual void setCattleBirthDate(int cattle_earring, std::string cattle_birth_date) = 0;

        /*!
            Returns the birth date of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content birth date attribute.  
        */
        virtual QString getCattleBirthDate(int cattle_earring) const = 0;

        /*!
            Sets the father's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_father which will be set to the Cattle.
        */
        virtual void setCattleFather(int cattle_earring, int cattle_father) = 0;

        /*!
            Returns the father's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content father attribute.  
        */
        virtual QString getCattleFather(int cattle_earring) const = 0;

        /*!
            Sets the mother's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_mother which will be set to the Cattle.
        */
        virtual void setCattleMother(int cattle_earring, int cattle_mother) = 0;

        /*!
            Returns the mother's earring of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content mother attribute.  
        */
        virtual QString getCattleMother(int cattle_earring) const = 0;

        /*!
            Sets the weight of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_weight which will be set to the Cattle.
        */
        virtual void setCattleWeight(int cattle_earring, double cattle_weight) = 0;

        /*!
            Returns the weight of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content weight attribute.  
        */
        virtual QString getCattleWeight(int cattle_earring) const = 0;

        /*!
            Sets the value of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \param cattle_value which will be set to the Cattle.
        */
        virtual void setCattleValue(int cattle_earring, double cattle_value) = 0;

        /*!
            Returns the value of a registered Cattle in the database.
            \param cattle_earring the earring of the Cattle.
            \return QString - the content value attribute.  
        */
        virtual QString getCattleValue(int cattle_earring) const = 0;

        /*!
            Sets the number of a registered Transaction in the database.
            \param actual_transaction_number the number of the Transaction.
            \param new_transaction_number which will be set to the Transaction.
        */
        virtual void setTransactionNumber(int actual_transaction_number, int new_transaction_number) = 0;

        /*!
            Returns the number of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content number attribute.
        */
        virtual QString getTransactionNumber(int transaction_number) const = 0;

        /*!
            Sets the value of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_value which will be set to the Transaction.
        */
        virtual void setTransactionValue(int transaction_number, double transaction_value) = 0;

        /*!
            Returns the value of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content value attribute.  
        */
        virtual QString getTransactionValue(int transaction_number) const = 0;
        
        /*!
            Sets the description of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_description which will be set to the Transaction.
        */
        virtual void setTransactionDescription(int transaction_number, std::string transaction_description) = 0;

        /*!
            Returns the description of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content description attribute.  
        */
        virtual QString getTransactionDescription(int transaction_number) const = 0;

        /*!
            Sets the date of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_date which will be set to the Transaction.
        */
        virtual void setTransactionDate(int transaction_number, std::string transaction_date) = 0;

        /*!
            Returns the date of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content date attribute.  
        */
        virtual QString getTransactionDate(int transaction_number) const = 0;

        /*!
            Sets the cattle earring of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \param transaction_cattle_earring which will be set to the Transaction.
        */
        virtual void setTransactionCattleEarring(int transaction_number, int transaction_cattle_earring) = 0;

        /*!
            Returns the cattle earring of a registered Transaction in the database.
            \param transaction_number the number of the Transaction.
            \return QString - the content cattle earring attribute.  
        */
        virtual QString getTransactionCattleEarring(int transaction_number) const = 0;

        /*!
            Sets the nickname of a registered User in the database.
            \param actual_user_nickname the nickname of the current User.
            \param new_user_nickname which will be set to the current User.
        */
        virtual void setUserNickname(std::string actual_user_nickname, std::string new_user_nickname) = 0;

        /*!
            Returns the nickname of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \return QString - the content nickname attribute.  
        */
        virtual QString getUserNickname(std::string user_nickname) const = 0;

        /*!
            Sets the name of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_name which will be set to the current User.
        */
        virtual void setUserName(std::string user_nickname, std::string user_name) = 0;

        /*!
            Returns the name of a registered User in the database.
            \param user_nickname the name of the current User.
            \return QString - the content name attribute.  
        */
        virtual QString getUserName(std::string user_nickname) const = 0;

        /*!
            Sets the password of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_password which will be set to the current User.
        */
        virtual void setUserPassword(std::string user_nickname, std::string user_password) = 0;

        /*!
            Returns the password of a registered User in the database.
            \param user_nickname the password of the current User.
            \return QString - the content password attribute.  
        */
        virtual QString getUserPassword(std::string user_nickname) const = 0;

        /*!
            Sets the date of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_date which will be set to the current User.
        */
        virtual void setUserDate(std::string user_nickname, std::string user_date) = 0;

        /*!
            Returns the date of a registered User in the database.
            \param user_nickname the date of the current User.
            \return QString - the content date attribute.  
        */
        virtual QString getUserDate(std::string user_nickname) const = 0;

        /*!
            Sets the type of a registered User in the database.
            \param user_nickname the nickname of the current User.
            \param user_type which will be set to the current User.
        */
        virtual void setUserType(std::string user_nickname, std::string user_type) = 0;

        /*!
            Returns the type of a registered User in the database.
            \param user_nickname the type of the current User.
            \return QString - the content type attribute.  
        */
        virtual QString getUserType(std::string user_nickname) const = 0;

        /*!
            Returns the last available earring on the cattle table from the database.
            \return int - the last available earring on the cattle table from the database.
        */
        virtual int getLastEarringAvailable() = 0;

        /*!
            Returns the last available number on the financial table from the database.
            \return int - the last available number on the financial table from the database.
        */
        virtual int getLastNumberAvailable() = 0;
        
};

#endif
