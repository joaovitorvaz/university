#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "system.h"

using namespace std;

//! Class SystemImpl
/**
* This Class represents a SystemImpl in the General Systems Theory implemented in this code.
*/
class SystemImpl : public System{

    protected:
        string name; /*!< This attribute contains a name for the SystemImpl. */
        double value; /*!< This attribute contains the actual value of the SystemImpl. */

        /*!
            This is the copy constructor for the SystemImpl Class.
            \param sys the SystemImpl that is going to be cloned.
        */
        // SystemImpl (const SystemImpl& sys);

        /*!
            This is the overloaded assignment operator for the SystemImpl Class.
        */
        SystemImpl& operator=(const SystemImpl& sys);

    public:
        SystemImpl (const SystemImpl& sys);

        friend class Flow; /*!< This Class represents a flow in the General Systems Theory implemented in this code. */
        friend class ModelImpl; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
        friend class UnitSystem; /*!< This Class is used to test the copy constructor and assignment operator of the SystemImpl class. */

        /*!
            This is the default constructor for the SystemImpl Class.
            \param name the name of the SystemImpl.
            \param value the initial value of the SystemImpl.
            \return SystemImpl - a SystemImpl Class object.
        */
        SystemImpl(string name = "", double value = 0.0);

        /*!
            This is the default destructor for the SystemImpl Class.
        */
        virtual ~SystemImpl();

        /*!
            Sets the name attribute in the SystemImpl Class.
            \param sysName which will be set to the current SystemImpl.
        */
        void setName(string sysName);

        /*!
            Returns the name attribute in the SystemImpl Class.
            \return string - the content name attribute.  
        */
        string getName() const;
        
        /*!
            Sets the value attribute in the SystemImpl Class.
            \param sysValue which will be set to the current SystemImpl.
        */
        void setValue(double sysValue);

        /*!
            Returns the value attribute in the SystemImpl Class.
            \return double - the content value attribute.  
        */
        double getValue() const;
      
        /*!
            This is the overloaded "+" operator for the SystemImpl Class.
        */
        double operator+(const SystemImpl& sys);
        
        /*!
            This is the overloaded "+" operator for the SystemImpl Class.
        */
        double operator+(const double& valueSys);

        /*!
            This is the overloaded "-" operator for the SystemImpl Class.
        */
        double operator-(const SystemImpl& sys);
        
        /*!
            This is the overloaded "-" operator for the SystemImpl Class.
        */
        double operator-(const double& valueSys);

        /*!
            This is the overloaded "*" operator for the SystemImpl Class.
        */
        double operator*(const SystemImpl& sys);
        
        /*!
            This is the overloaded "*"" operator for the SystemImpl Class.
        */
        double operator*(const double& valueSys);

        /*!
            This is the overloaded "/" operator for the SystemImpl Class.
        */
        double operator/(const SystemImpl& sys);
        
        /*!
            This is the overloaded "/" operator for the SystemImpl Class.
        */
        double operator/(const double& valueSys);

};


double operator+(const double& valueSys, const SystemImpl& sys);
double operator-(const double& valueSys, const SystemImpl& sys);
double operator*(const double& valueSys, const SystemImpl& sys);
double operator/(const double& valueSys, const SystemImpl& sys);

#endif