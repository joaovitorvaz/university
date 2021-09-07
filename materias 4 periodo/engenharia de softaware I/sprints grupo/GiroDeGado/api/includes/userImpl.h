/*!
 \file userImpl.h
 \brief This file contains the handle/body of a User for the GiroDeGado software.
*/

#ifndef USERIMPL_H
#define USERIMPL_H

#include "./user.h"
#include "./handlebody.h"
#include "lib_global.h"

/** 
 * \brief
 * This Class represents the body of a Handle/Body idiom of a User for the GiroDeGado software.
*/
class LIB_EXPORT UserBody : public Body{

    private:
        // No copy allowed

        /*!
            This is the copy constructor for the UserBody Class.
            \param user the UserBody that is going to be cloned.
        */
        UserBody (const UserBody& user);

        /*!
            This is the overloaded assignment operator for the UserBody Class.
        */
        UserBody& operator=(const UserBody& user);

    public:

        /*!
            This is the default constructor for the UserBody Class.
            \return UserBody - a UserBody Class object.
        */
        UserBody();

        /*!
            This is the default destructor for the UserBody Class.
        */
        virtual ~UserBody();

        /*!
            Sets the nickname of the current User in the database.
            \param query the query of a database.
            \param actual_user_nickname the nickname of the current User.
            \param new_user_nickname which will be set to the current User.
        */
        void setNickname(QSqlQuery* query, std::string actual_user_nickname, std::string new_user_nickname);

        /*!
            Returns the nickname of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \return QString - the content nickname attribute.  
        */
        QString getNickname(QSqlQuery* query, std::string user_nickname) const;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_name which will be set to the current User.
        */
        void setName(QSqlQuery* query, std::string user_nickname, std::string user_name);

        /*!
            Returns the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the name of the current User.
            \return QString - the content name attribute.  
        */
        QString getName(QSqlQuery* query, std::string user_nickname) const;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_password which will be set to the current User.
        */
        void setPassword(QSqlQuery* query, std::string user_nickname, std::string user_password);

        /*!
            Returns the password of the current User in the database.
            \param query the query of a database.
            \param user_nickname the password of the current User.
            \return QString - the content password attribute.  
        */
        QString getPassword(QSqlQuery* query, std::string user_nickname) const;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_date which will be set to the current User.
        */
        void setDate(QSqlQuery* query, std::string user_nickname, std::string user_date);

        /*!
            Returns the date of the current User in the database.
            \param query the query of a database.
            \param user_nickname the date of the current User.
            \return QString - the content date attribute.  
        */
        QString getDate(QSqlQuery* query, std::string user_nickname) const;

        /*!
            Sets the name of the current User in the database.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_type which will be set to the current User.
        */
        void setType(QSqlQuery* query, std::string user_nickname, std::string user_type);

        /*!
            Returns the type of the current User in the database.
            \param query the query of a database.
            \param user_nickname the type of the current User.
            \return QString - the content type attribute.  
        */
        QString getType(QSqlQuery* query, std::string user_nickname) const;

};

/** 
 * \brief
 * This Class represents the handle of a Handle/Body idiom of a User for the GiroDeGado software implemented in this code.
*/
class LIB_EXPORT UserHandle : public Handle<UserBody>, public User{
    public:
        
        /*!
            This is the default constructor for the UserHandle Class.
            \return UserHandle - a UserHandle Class object.
        */
        UserHandle(){};

        /*!
            This is the default destructor for the UserHandle Class.
        */
        virtual ~UserHandle(){};
 
        /*!
            Calls the setNickname() method implemented in the UserBody Class.
            \param query the query of a database.
            \param actual_user_nickname the nickname of the current User.
            \param new_user_nickname which will be set to the current User.
        */
        void setNickname(QSqlQuery* query, std::string actual_user_nickname, std::string new_user_nickname){
            pImpl_->setNickname(query, actual_user_nickname, new_user_nickname);
        }

        /*!
            Calls the getNickname() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \return QString - the content nickname attribute.  
        */
        QString getNickname(QSqlQuery* query, std::string user_nickname) const{
            return pImpl_->getNickname(query, user_nickname);
        }

        /*!
            Calls the setName() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_name which will be set to the current User.
        */
        void setName(QSqlQuery* query, std::string user_nickname, std::string user_name){
            pImpl_->setName(query, user_nickname, user_name);
        }

        /*!
            Calls the getName() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the name of the current User.
            \return QString - the content name attribute.  
        */
        QString getName(QSqlQuery* query, std::string user_nickname) const{
            return pImpl_->getName(query, user_nickname);
        }

        /*!
            Calls the setPassword() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_password which will be set to the current User.
        */
        void setPassword(QSqlQuery* query, std::string user_nickname, std::string user_password){
            pImpl_->setPassword(query, user_nickname, user_password);
        }

        /*!
            Calls the getPassword() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the password of the current User.
            \return QString - the content password attribute.  
        */
        QString getPassword(QSqlQuery* query, std::string user_nickname) const{
            return pImpl_->getPassword(query, user_nickname);
        }

        /*!
            Calls the setDate() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_date which will be set to the current User.
        */
        void setDate(QSqlQuery* query, std::string user_nickname, std::string user_date){
            pImpl_->setDate(query, user_nickname, user_date);
        }

        /*!
            Calls the getDate() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the date of the current User.
            \return QString - the content date attribute.  
        */
        QString getDate(QSqlQuery* query, std::string user_nickname) const{
            return pImpl_->getDate(query, user_nickname);
        }

        /*!
            Calls the setType() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the nickname of the current User.
            \param user_type which will be set to the current User.
        */
        void setType(QSqlQuery* query, std::string user_nickname, std::string user_type){
            pImpl_->setType(query, user_nickname, user_type);
        }

        /*!
            Calls the getType() method implemented in the UserBody Class.
            \param query the query of a database.
            \param user_nickname the type of the current User.
            \return QString - the content type attribute.  
        */
        QString getType(QSqlQuery* query, std::string user_nickname) const{
            return pImpl_->getType(query, user_nickname);
        }

};

#endif