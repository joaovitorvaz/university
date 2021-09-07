/*!
 \file transaction.h
 \brief This file contains the interface of a Transaction for the GiroDeGado software.
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <QtSql/QtSql>
#include "lib_global.h"

/** 
 * \brief
 * This Class represents a Transaction for the GiroDeGado software.
*/
class LIB_EXPORT Transaction{

    public:
        /*!
            This is the default destructor for the Transaction Class.
        */
        virtual ~Transaction(){}
     
        /*!
            Sets the number of the current Transaction in the database.
            \param query the query of a database.
            \param actual_transaction_number the number of the current Transaction.
            \param new_transaction_number which will be set to the current Transaction.
        */
        virtual void setNumber(QSqlQuery* query, int actual_transaction_number, int new_transaction_number) = 0;

        /*!
            Returns the number of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content number attribute.
        */
        virtual QString getNumber(QSqlQuery* query, int transaction_number) const = 0;

        /*!
            Sets the value of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_value which will be set to the current Transaction.
        */
        virtual void setValue(QSqlQuery* query, int transaction_number, double transaction_value) = 0;

        /*!
            Returns the value of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content value attribute.  
        */
        virtual QString getValue(QSqlQuery* query, int transaction_number) const = 0;
        
        /*!
            Sets the description of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_description which will be set to the current Transaction.
        */
        virtual void setDescription(QSqlQuery* query, int transaction_number, std::string transaction_description) = 0;

        /*!
            Returns the description of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content description attribute.  
        */
        virtual QString getDescription(QSqlQuery* query, int transaction_number) const = 0;

        /*!
            Sets the date of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_date which will be set to the current Transaction.
        */
        virtual void setDate(QSqlQuery* query, int transaction_number, std::string transaction_date) = 0;

        /*!
            Returns the date of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content date attribute.  
        */
        virtual QString getDate(QSqlQuery* query, int transaction_number) const = 0;

        /*!
            Sets the cattle earring of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \param transaction_cattle_earring which will be set to the current Transaction.
        */
        virtual void setCattleEarring(QSqlQuery* query, int transaction_number, int transaction_cattle_earring) = 0;

        /*!
            Returns the cattle earring of the current Transaction in the database.
            \param query the query of a database.
            \param transaction_number the number of the current Transaction.
            \return QString - the content cattle earring attribute.  
        */
        virtual QString getCattleEarring(QSqlQuery* query, int transaction_number) const = 0;

};

#endif
