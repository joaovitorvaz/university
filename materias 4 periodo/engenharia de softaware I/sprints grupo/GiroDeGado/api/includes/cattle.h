/*!
 \file cattle.h
 \brief This file contains the interface of a Cattle for the GiroDeGado software.
*/

#ifndef CATTLE_H
#define CATTLE_H

#include <iostream>
#include <string>
#include <QtSql/QtSql>
#include "lib_global.h"

/** 
 * \brief
 * This Class represents a Cattle for the GiroDeGado software.
*/
class LIB_EXPORT Cattle{

    public:
        /*!
            This is the default destructor for the Cattle Class.
        */
        virtual ~Cattle(){}
     
        /*!
            Sets the earring of the current Cattle in the database.
            \param query the query of a database.
            \param actual_cattle_earring the earring of the current Cattle.
            \param new_cattle_earring which will be set to the current Cattle.
        */
        virtual void setEarring(QSqlQuery* query, int actual_cattle_earring, int new_cattle_earring) = 0;

        /*!
            Returns the earring of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content earring attribute.  
        */
        virtual QString getEarring(QSqlQuery* query, int cattle_earring) const = 0;
        
        /*!
            Sets the breed of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_breed which will be set to the current Cattle.
        */
        virtual void setBreed(QSqlQuery* query, int cattle_earring, std::string cattle_breed) = 0;

        /*!
            Returns the breed of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content Breed attribute.  
        */
        virtual QString getBreed(QSqlQuery* query, int cattle_earring) const = 0;

        /*!
            Sets the acquisition date of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_acquisition_date which will be set to the current Cattle.
        */
        virtual void setAcquisitionDate(QSqlQuery* query, int cattle_earring, std::string cattle_acquisition_date) = 0;

        /*!
            Returns the acquisition date of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content acquisition date attribute.  
        */
        virtual QString getAcquisitionDate(QSqlQuery* query, int cattle_earring) const = 0;

        /*!
            Sets the birth date of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_birth_date which will be set to the current Cattle.
        */
        virtual void setBirthDate(QSqlQuery* query, int cattle_earring, std::string cattle_birth_date) = 0;

        /*!
            Returns the birth date of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content birth date attribute.  
        */
        virtual QString getBirthDate(QSqlQuery* query, int cattle_earring) const = 0;

        /*!
            Sets the father's earring of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_father which will be set to the current Cattle.
        */
        virtual void setFather(QSqlQuery* query, int cattle_earring, int cattle_father) = 0;

        /*!
            Returns the father's earring of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content father attribute.  
        */
        virtual QString getFather(QSqlQuery* query, int cattle_earring) const = 0;

        /*!
            Sets the mother's earring of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_mother which will be set to the current Cattle.
        */
        virtual void setMother(QSqlQuery* query, int cattle_earring, int cattle_mother) = 0;

        /*!
            Returns the mother's earring of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content mother attribute.  
        */
        virtual QString getMother(QSqlQuery* query, int cattle_earring) const = 0;

        /*!
            Sets the weight of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_weight which will be set to the current Cattle.
        */
        virtual void setWeight(QSqlQuery* query, int cattle_earring, double cattle_weight) = 0;

        /*!
            Returns the weight of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content weight attribute.  
        */
        virtual QString getWeight(QSqlQuery* query, int cattle_earring) const = 0;

        /*!
            Sets the value of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_value which will be set to the current Cattle.
        */
        virtual void setValue(QSqlQuery* query, int cattle_earring, double cattle_value) = 0;

        /*!
            Returns the value of the current Cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content value attribute.  
        */
        virtual QString getValue(QSqlQuery* query, int cattle_earring) const = 0;

};

#endif
