/*!
 \file user.h
 \brief This file contains the interface of a User for the GiroDeGado software.
*/

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <QtSql/QtSql>
#include "lib_global.h"

/** 
 * \brief
 * This Class represents a User for the GiroDeGado software.
*/
class LIB_EXPORT User{

    public:
        /*!
            This is the default destructor for the User Class.
        */
        virtual ~User(){}

        /*!
            Sets the nickname of the current User in the database.
            \param query the query of a database.
            \param actual_user_nickname the nickname of the current User.
            \param new_user_nickname which will be set to the current User.
        */
        virtual void setNickname(QSqlQuery* query, std::string actual_user_nickname, std::string new_user_nickname) = 0;

        /*!
            Returns the nickname of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \return QString - the content nickname attribute.  
        */
        virtual QString getNickname(QSqlQuery* query, std::string user_nickname) const = 0;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_name which will be set to the current User.
        */
        virtual void setName(QSqlQuery* query, std::string user_nickname, std::string user_name) = 0;

        /*!
            Returns the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the name of the current User.
            \return QString - the content name attribute.  
        */
        virtual QString getName(QSqlQuery* query, std::string user_nickname) const = 0;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_password which will be set to the current User.
        */
        virtual void setPassword(QSqlQuery* query, std::string user_nickname, std::string user_password) = 0;

        /*!
            Returns the password of the current User in the database.
            \param query the query of a database.
            \param user_nickname the password of the current User.
            \return QString - the content password attribute.  
        */
        virtual QString getPassword(QSqlQuery* query, std::string user_nickname) const = 0;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_date which will be set to the current User.
        */
        virtual void setDate(QSqlQuery* query, std::string user_nickname, std::string user_date) = 0;

        /*!
            Returns the date of the current User in the database.
            \param query the query of a database.
            \param user_nickname the date of the current User.
            \return QString - the content date attribute.  
        */
        virtual QString getDate(QSqlQuery* query, std::string user_nickname) const = 0;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_type which will be set to the current User.
        */
        virtual void setType(QSqlQuery* query, std::string user_nickname, std::string user_type) = 0;

        /*!
            Returns the type of the current User in the database.
            \param query the query of a database.
            \param user_nickname the type of the current User.
            \return QString - the content type attribute.  
        */
        virtual QString getType(QSqlQuery* query, std::string user_nickname) const = 0;

};

#endif