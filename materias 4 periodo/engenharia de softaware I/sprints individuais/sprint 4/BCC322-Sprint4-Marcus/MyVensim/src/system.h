#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <ios>
#include <fstream>

using namespace std;

//! Class System
/**
* This Class represents a system in the General Systems Theory implemented in this code.
*/
class System{

    public:
        /*!
            This is the default destructor for the System Class.
        */
        virtual ~System(){}
     
        /*!
            Sets the name attribute in the System Class.
            \param sysName which will be set to the current system.
        */
        virtual void setName(string sysName) = 0;

        /*!
            Returns the name attribute in the System Class.
            \return string - the content name attribute.  
        */
        virtual string getName() const = 0;
        
        /*!
            Sets the value attribute in the System Class.
            \param sysValue which will be set to the current system.
        */
        virtual void setValue(double sysValue) = 0;

        /*!
            Returns the value attribute in the System Class.
            \return double - the content value attribute.  
        */
        virtual double getValue() const = 0;
      
      
        /*!
            This is the overloaded "+" operator for the System Class.
        */
        double operator+(const System& sys);
        
        /*!
            This is the overloaded "+" operator for the System Class.
        */
        double operator+(const double& valueSys);

        /*!
            This is the overloaded "-" operator for the System Class.
        */
        double operator-(const System& sys);
        
        /*!
            This is the overloaded "-" operator for the System Class.
        */
        double operator-(const double& valueSys);

        /*!
            This is the overloaded "*" operator for the System Class.
        */
        double operator*(const System& sys);
        
        /*!
            This is the overloaded "*"" operator for the System Class.
        */
        double operator*(const double& valueSys);

        /*!
            This is the overloaded "/" operator for the System Class.
        */
        double operator/(const System& sys);
        
        /*!
            This is the overloaded "/" operator for the System Class.
        */
        double operator/(const double& valueSys);

};


double operator+(const double& valueSys, const System& sys);
double operator-(const double& valueSys, const System& sys);
double operator*(const double& valueSys, const System& sys);
double operator/(const double& valueSys, const System& sys);

#endif