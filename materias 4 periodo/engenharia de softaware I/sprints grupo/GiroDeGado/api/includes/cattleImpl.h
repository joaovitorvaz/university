/*!
 \file cattleImpl.h
 \brief This file contains the handle/body of a Cattle for the GiroDeGado software.
*/

#ifndef CATTLEIMPL_H
#define CATTLEIMPL_H

#include "./cattle.h"
#include "./handlebody.h"
#include "lib_global.h"

/** 
 * \brief
 * This Class represents the body of a Handle/Body idiom of a Cattle for the GiroDeGado software.
*/
class LIB_EXPORT CattleBody : public Body{

    private:
        // No copy allowed

        /*!
            This is the copy constructor for the CattleBody Class.
            \param cattle the CattleBody that is going to be cloned.
        */
        CattleBody (const CattleBody& cattle);

        /*!
            This is the overloaded assignment operator for the CattleBody Class.
        */
        CattleBody& operator=(const CattleBody& cattle);

    public:

        /*!
            This is the default constructor for the CattleBody Class.
            \return CattleBody - a CattleBody Class object.
        */
        CattleBody();

        /*!
            This is the default destructor for the CattleBody Class.
        */
        virtual ~CattleBody();

        /*!
            Sets the earring of the current cattle in the database.
            \param query the query of a database.
            \param actual_cattle_earring the earring of the current Cattle.
            \param new_cattle_earring which will be set to the current Cattle.
        */
        void setEarring(QSqlQuery* query, int actual_cattle_earring, int new_cattle_earring);

        /*!
            Returns the earring of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content earring attribute.  
        */
        QString getEarring(QSqlQuery* query, int cattle_earring) const;
        
        /*!
            Sets the breed of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_breed which will be set to the current Cattle.
        */
        void setBreed(QSqlQuery* query, int cattle_earring, std::string cattle_breed);

        /*!
            Returns the breed of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content Breed attribute.  
        */
        QString getBreed(QSqlQuery* query, int cattle_earring) const;

        /*!
            Sets the acquisition date of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_acquisition_date which will be set to the current Cattle.
        */
        void setAcquisitionDate(QSqlQuery* query, int cattle_earring, std::string cattle_acquisition_date);

        /*!
            Returns the acquisition date of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content acquisition date attribute.  
        */
        QString getAcquisitionDate(QSqlQuery* query, int cattle_earring) const;

        /*!
            Sets the birth date of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_birth_date which will be set to the current Cattle.
        */
        void setBirthDate(QSqlQuery* query, int cattle_earring, std::string cattle_birth_date);

        /*!
            Returns the birth date of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content birth date attribute.  
        */
        QString getBirthDate(QSqlQuery* query, int cattle_earring) const;

        /*!
            Sets the father's earring of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_father which will be set to the current Cattle.
        */
        void setFather(QSqlQuery* query, int cattle_earring, int cattle_father);

        /*!
            Returns the father's earring of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content father attribute.  
        */
        QString getFather(QSqlQuery* query, int cattle_earring) const;

        /*!
            Sets the mother's earring of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_mother which will be set to the current Cattle.
        */
        void setMother(QSqlQuery* query, int cattle_earring, int cattle_mother);

        /*!
            Returns the mother's earring of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content mother attribute.  
        */
        QString getMother(QSqlQuery* query, int cattle_earring) const;

        /*!
            Sets the weight of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_weight which will be set to the current Cattle.
        */
        void setWeight(QSqlQuery* query, int cattle_earring, double cattle_weight);

        /*!
            Returns the weight of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content weight attribute.  
        */
        QString getWeight(QSqlQuery* query, int cattle_earring) const;

        /*!
            Sets the value of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_value which will be set to the current Cattle.
        */
        void setValue(QSqlQuery* query, int cattle_earring, double cattle_value);

        /*!
            Returns the value of the current cattle in the database.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content value attribute.  
        */
        QString getValue(QSqlQuery* query, int cattle_earring) const;

};

/** 
 * \brief
 * This Class represents the handle of a Handle/Body idiom of a Cattle for the GiroDeGado software implemented in this code.
*/
class LIB_EXPORT CattleHandle : public Handle<CattleBody>, public Cattle{
    public:
        
        /*!
            This is the default constructor for the CattleHandle Class.
            \return CattleHandle - a CattleHandle Class object.
        */
        CattleHandle(){};

        /*!
            This is the default destructor for the CattleHandle Class.
        */
        virtual ~CattleHandle(){};

        /*!
            Calls the setEarring() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param actual_cattle_earring the earring of the current Cattle.
            \param new_cattle_earring which will be set to the current Cattle.
        */
        void setEarring(QSqlQuery* query, int actual_cattle_earring, int new_cattle_earring){
            pImpl_->setEarring(query, actual_cattle_earring, new_cattle_earring);
        }

        /*!
            Calls the getEarring() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content earring attribute.  
        */
        QString getEarring(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getEarring(query, cattle_earring);
        }
        
        /*!
            Calls the setBreed() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_breed which will be set to the current Cattle.
        */
        void setBreed(QSqlQuery* query, int cattle_earring, std::string cattle_breed){
            pImpl_->setBreed(query, cattle_earring, cattle_breed);
        }

        /*!
            Calls the getBreed() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content Breed attribute.  
        */
        QString getBreed(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getBreed(query, cattle_earring);
        }

        /*!
            Calls the setAcquisitionDate() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_acquisition_date which will be set to the current Cattle.
        */
        void setAcquisitionDate(QSqlQuery* query, int cattle_earring, std::string cattle_acquisition_date){
            pImpl_->setAcquisitionDate(query, cattle_earring, cattle_acquisition_date);
        }

        /*!
            Calls the getAcquisitionDate() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content acquisition date attribute.  
        */
        QString getAcquisitionDate(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getAcquisitionDate(query, cattle_earring);
        }

        /*!
            Calls the setBirthDate() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_birth_date which will be set to the current Cattle.
        */
        void setBirthDate(QSqlQuery* query, int cattle_earring, std::string cattle_birth_date){
            pImpl_->setBirthDate(query, cattle_earring, cattle_birth_date);
        }

        /*!
            Calls the getBirthDate() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content birth date attribute.  
        */
        QString getBirthDate(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getBirthDate(query, cattle_earring);
        }

        /*!
            Calls the setFather() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_father which will be set to the current Cattle.
        */
        void setFather(QSqlQuery* query, int cattle_earring, int cattle_father){
            pImpl_->setFather(query, cattle_earring, cattle_father);
        }

        /*!
            Calls the getFather() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content father attribute.  
        */
        QString getFather(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getFather(query, cattle_earring);
        }

        /*!
            Calls the setMother() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_mother which will be set to the current Cattle.
        */
        void setMother(QSqlQuery* query, int cattle_earring, int cattle_mother){
            pImpl_->setMother(query, cattle_earring, cattle_mother);
        }

        /*!
            Calls the getMother() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content mother attribute.  
        */
        QString getMother(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getMother(query, cattle_earring);
        }

        /*!
            Calls the setWeight() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_weight which will be set to the current Cattle.
        */
        void setWeight(QSqlQuery* query, int cattle_earring, double cattle_weight){
            pImpl_->setWeight(query, cattle_earring, cattle_weight);
        }

        /*!
            Calls the getWeight() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content weight attribute.  
        */
        QString getWeight(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getWeight(query, cattle_earring);
        }

        /*!
            Calls the setValue() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \param cattle_value which will be set to the current Cattle.
        */
        void setValue(QSqlQuery* query, int cattle_earring, double cattle_value){
            pImpl_->setValue(query, cattle_earring, cattle_value);
        }

        /*!
            Calls the getValue() method implemented in the CattleBody Class.
            \param query the query of a database.
            \param cattle_earring the earring of the current Cattle.
            \return QString - the content value attribute.  
        */
        QString getValue(QSqlQuery* query, int cattle_earring) const{
            return pImpl_->getValue(query, cattle_earring);
        }    

};

#endif
