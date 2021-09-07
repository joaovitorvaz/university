#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

//! Class System
/**
* This Class represents a system in the General Systems Theory implemented in this code.
*/
class System{

    protected:
        string name; /*!< This attribute contains a name for the system. */
        double value; /*!< This attribute contains the actual value of the system. */
        bool isAddedToModel; /*!< This attribute is True if the System is added to a Model, and it is False otherwise.*/

    public:
        friend class Flow; /*!< This Class represents a flow in the General Systems Theory implemented in this code. */
        friend class Model; /*!< This Class represents a model in the General Systems Theory implemented in this code. */

        /*!
            This is the default constructor for the System Class.
        */
        System():isAddedToModel(false){}

        /*!
            This is a more elaborated constructor for the System Class.
            \param name the name of the System.
            \param value the initial value of the System.
            \return System - a System Class object, with it's isAddedToModel attribute set to false.
        */
        System(string name = "", double value = 0.0):name(name), value(value), isAddedToModel(false){}

        /*!
            This is the default destructor for the System Class.
        */
        virtual ~System(){}

        /*!
            Sets the name attribute in the System Class.
            \param sysName which will be set to the current system.
        */
        void setName(string sysName){
            name = sysName;
        }

        /*!
            Returns the name attribute in the System Class.
            \return string - the content name attribute.  
        */
        string getName() const {
            return name;
        }    
        
        /*!
            Sets the value attribute in the System Class.
            \param sysValue which will be set to the current system.
        */
        void setValue(double sysValue){
            value = sysValue;
        }
        /*!
            Returns the value attribute in the System Class.
            \return double - the content value attribute.  
        */
        double getValue() const{
            return value;
        }
        
    private:
        /*!
            Sets the isAddedToModel attribute in the System Class.
            \param sysInModel which will be set to the current system.
        */
        void setIsAddedToModel(bool sysInModel){
            isAddedToModel = sysInModel;
        }

        /*!
            Returns the isAddedToModel attribute in the System Class.
            \return bool - the content of isAddedToModel attribute.
        */
        bool getIsAddedToModel() const{
            return isAddedToModel;
        }

        /*!
            This is the copy constructor for the System Class.
            \param sys the system that is going to be cloned.
        */
        System (const System& sys){
            if (this == &sys){
                return;
            }
            
            name = sys.getName();
            value = sys.getValue();
            isAddedToModel = false;
        }

        /*!
            This is the overloaded assignment operator for the System Class.
        */
        System& operator=(const System& sys){
            if (this == &sys){
                return *this;
            }

            name = sys.getName();
            value = sys.getValue();  
            isAddedToModel = false;  

            return *this;
        }

};

#endif