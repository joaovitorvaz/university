/*!
 \file transactionImpl.h
 \brief This file contains the handle/body of a Transaction for the GiroDeGado software.
*/

#ifndef TRANSACTIONIMPL_H
#define TRANSACTIONIMPL_H

#include <QtSql>
#include "./transaction.h"
#include "./handlebody.h"
#include "lib_global.h"

using namespace std;

/** 
 * \brief
 * This Class represents the body of a Handle/Body idiom of a Transaction for the GiroDeGado software.
*/
class LIB_EXPORT TransactionBody : public Body{

    private:
        // No copy allowed

        /*!
            This is the copy constructor for the TransactionBody Class.
            \param transaction the TransactionBody that is going to be cloned.
        */
        TransactionBody (const TransactionBody& transaction);

        /*!
            This is the overloaded assignment operator for the TransactionBody Class.
        */
        TransactionBody& operator=(const TransactionBody& transaction);

    public:

        /*!
            This is the default constructor for the TransactionBody Class.
            \return TransactionBody - a TransactionBody Class object.
        */
        TransactionBody();

        /*!
            This is the default destructor for the TransactionBody Class.
        */
        virtual ~TransactionBody();

        /*!
            Sets the number of the current Transaction in the database.
            \param query the query of a database.
            \param actual_transaction_number the number of the current Transaction.
            \param new_transaction_number which will be set to the current Transaction.
        */
        void setNumber(QSqlQuery* query, int actual_transaction_number, int new_transaction_number);

        /*!
            Returns the number of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content number attribute.
        */
        QString getNumber(QSqlQuery* query, int transaction_number) const;

        /*!
            Sets the value of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_value which will be set to the current Transaction.
        */
        void setValue(QSqlQuery* query, int transaction_number, double transaction_value);

        /*!
            Returns the value of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content value attribute.  
        */
        QString getValue(QSqlQuery* query, int transaction_number) const;
        
        /*!
            Sets the description of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_description which will be set to the current Transaction.
        */
        void setDescription(QSqlQuery* query, int transaction_number, std::string transaction_description);

        /*!
            Returns the description of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content description attribute.  
        */
        QString getDescription(QSqlQuery* query, int transaction_number) const;

        /*!
            Sets the date of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_date which will be set to the current Transaction.
        */
        void setDate(QSqlQuery* query, int transaction_number, std::string transaction_date);

        /*!
            Returns the date of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content date attribute.  
        */
        QString getDate(QSqlQuery* query, int transaction_number) const;

        /*!
            Sets the cattle earring of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_cattle_earring which will be set to the current Transaction.
        */
        void setCattleEarring(QSqlQuery* query, int transaction_number, int transaction_cattle_earring);

        /*!
            Returns the cattle earring of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content cattle earring attribute.  
        */
        QString getCattleEarring(QSqlQuery* query, int transaction_number) const;

};

/** 
 * \brief
 * This Class represents the handle of a Handle/Body idiom of a Transaction for the GiroDeGado software implemented in this code.
*/
class LIB_EXPORT TransactionHandle : public Handle<TransactionBody>, public Transaction{
    public:
        
        /*!
            This is the default constructor for the TransactionHandle Class.
            \return TransactionHandle - a TransactionHandle Class object.
        */
        TransactionHandle(){};

        /*!
            This is the default destructor for the TransactionHandle Class.
        */
        virtual ~TransactionHandle(){};
        
        /*!
            Calls the setNumber() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param actual_transaction_number the number of the current Transaction.
            \param new_transaction_number which will be set to the current Transaction.
        */
        void setNumber(QSqlQuery* query, int actual_transaction_number, int new_transaction_number){
            pImpl_->setNumber(query, actual_transaction_number, new_transaction_number);
        }

        /*!
            Calls the getNumber() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content number attribute.
        */
        QString getNumber(QSqlQuery* query, int transaction_number) const{
            return pImpl_->getNumber(query, transaction_number);
        }

        /*!
            Calls the setValue() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_value which will be set to the current Transaction.
        */
        void setValue(QSqlQuery* query, int transaction_number, double transaction_value){
            pImpl_->setValue(query, transaction_number, transaction_value);
        }

        /*!
            Calls the getValue() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content value attribute.  
        */
        QString getValue(QSqlQuery* query, int transaction_number) const{
            return pImpl_->getValue(query, transaction_number);
        }
        
        /*!
            Calls the setDescription() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_description which will be set to the current Transaction.
        */
        void setDescription(QSqlQuery* query, int transaction_number, std::string transaction_description){
            pImpl_->setDescription(query, transaction_number, transaction_description);
        }

        /*!
            Calls the getDescription() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content description attribute.  
        */
        QString getDescription(QSqlQuery* query, int transaction_number) const{
            return pImpl_->getDescription(query, transaction_number);
        }

        /*!
            Calls the setDate() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_date which will be set to the current Transaction.
        */
        void setDate(QSqlQuery* query, int transaction_number, std::string transaction_date){
            pImpl_->setDate(query, transaction_number, transaction_date);
        }

        /*!
            Calls the getDate() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content date attribute.  
        */
        QString getDate(QSqlQuery* query, int transaction_number) const{
            return pImpl_->getDate(query, transaction_number);
        }

        /*!
            Calls the setCattleEarring() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_cattle_earring which will be set to the current Transaction.
        */
        void setCattleEarring(QSqlQuery* query, int transaction_number, int transaction_cattle_earring){
            pImpl_->setCattleEarring(query, transaction_number, transaction_cattle_earring);
        }

        /*!
            Calls the getCattleEarring() method implemented in the TransactionBody Class.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content cattle earring attribute.  
        */
        QString getCattleEarring(QSqlQuery* query, int transaction_number) const{
            return pImpl_->getCattleEarring(query, transaction_number);
        }
};

#endif
