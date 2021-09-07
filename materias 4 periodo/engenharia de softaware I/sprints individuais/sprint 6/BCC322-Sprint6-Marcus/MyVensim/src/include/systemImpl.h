#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "./system.h"
#include "./handlebody.h"

using namespace std;

//! Class SystemBody
/**
* This Class represents a system in the General Systems Theory implemented in this code.
*/
class SystemBody : public Body{

    protected:
        string name; /*!< This attribute contains a name for the SystemBody. */
        double value; /*!< This attribute contains the actual value of the SystemBody. */

    private:
        /*!
            This is the copy constructor for the SystemBody Class.
            \param sys the SystemBody that is going to be cloned.
        */
        SystemBody (const SystemBody& sys);

        /*!
            This is the overloaded assignment operator for the SystemBody Class.
        */
        SystemBody& operator=(const SystemBody& sys);

    public:
        /*!
            This is the default constructor for the SystemBody Class.
            \param name the name of the SystemBody.
            \param value the initial value of the SystemBody.
            \return SystemBody - a SystemBody Class object.
        */
        SystemBody(string name = "", double value = 0.0);

        /*!
            This is the default destructor for the SystemBody Class.
        */
        virtual ~SystemBody();

        /*!
            Sets the name attribute in the SystemBody Class.
            \param sysName which will be set to the current SystemBody.
        */
        void setName(string sysName);

        /*!
            Returns the name attribute in the SystemBody Class.
            \return string - the content name attribute.  
        */
        string getName() const;
        
        /*!
            Sets the value attribute in the SystemBody Class.
            \param sysValue which will be set to the current SystemBody.
        */
        void setValue(double sysValue);

        /*!
            Returns the value attribute in the SystemBody Class.
            \return double - the content value attribute.  
        */
        double getValue() const;
      
        /*!
            This is the overloaded "+" operator for the SystemBody Class.
        */
        double operator+(const System& sys);
        
        /*!
            This is the overloaded "+" operator for the SystemBody Class.
        */
        double operator+(const double& valueSys);

        /*!
            This is the overloaded "-" operator for the SystemBody Class.
        */
        double operator-(const System& sys);
        
        /*!
            This is the overloaded "-" operator for the SystemBody Class.
        */
        double operator-(const double& valueSys);

        /*!
            This is the overloaded "*" operator for the SystemBody Class.
        */
        double operator*(const System& sys);
        
        /*!
            This is the overloaded "*"" operator for the SystemBody Class.
        */
        double operator*(const double& valueSys);

        /*!
            This is the overloaded "/" operator for the SystemBody Class.
        */
        double operator/(const System& sys);
        
        /*!
            This is the overloaded "/" operator for the SystemBody Class.
        */
        double operator/(const double& valueSys);

};

//! Class SystemHandle
/**
* This Class represents the handle of a Handle/Body idiom for the System.
*/
class SystemHandle : public Handle<SystemBody>, public System{
    public:
        /*!
            This is the copy constructor for the SystemHandle Class.
            \param sys the SystemHandle that is going to be cloned.
        */
        SystemHandle(const SystemHandle& sys){
            if (this == &sys){
                return;
            }

            pImpl_->detach();
            pImpl_ = sys.pImpl_;
        }

        /*!
            This is the overloaded assignment operator for the SystemHandle Class.
        */
        SystemHandle& operator=(const SystemHandle& sys){
            if(this == &sys){
                return *this;
            }
        
            pImpl_->detach();
            pImpl_ = sys.pImpl_;
            return *this;
        }
        
        /*!
            This is the default constructor for the SystemHandle Class.
            \param name the name of the SystemHandle.
            \param value the initial value of the SystemHandle.
            \return SystemHandle - a SystemHandle Class object.
        */
        SystemHandle(string name = "", double value = 0.0){  
            pImpl_->setName(name);
            pImpl_->setValue(value);
        }

        /*!
            This is the default destructor for the SystemHandle Class.
        */
        virtual ~SystemHandle(){};

        /*!
            Sets the name attribute in the SystemHandle Class.
            \param sysName which will be set to the current SystemHandle.
        */
        void setName(string sysName){
            pImpl_->setName(sysName);
        }

        /*!
            Returns the name attribute in the SystemHandle Class.
            \return string - the content name attribute.  
        */
        string getName() const{
            return pImpl_->getName();
        }
        
        /*!
            Sets the value attribute in the SystemHandle Class.
            \param sysValue which will be set to the current SystemHandle.
        */
        void setValue(double sysValue){
            pImpl_->setValue(sysValue);
        }

        /*!
            Returns the value attribute in the SystemHandle Class.
            \return double - the content value attribute.  
        */
        double getValue() const{
            return pImpl_->getValue();
        }

        /*!
            This is the overloaded "+" operator for the SystemBody Class.
        */
        double operator+(const System& sys){
            if (this == &sys){
                return 2.0 * pImpl_->getValue();
            }

            return pImpl_->operator+(sys);
        }
            
        /*!
            This is the overloaded "+" operator for the SystemHandle Class.
        */
        double operator+(const double& valueSys){
            return pImpl_->operator+(valueSys);
        }

        /*!
            This is the overloaded "-" operator for the SystemHandle Class.
        */
        double operator-(const System& sys){
            if (this == &sys){
                return 0.0;
            }

            return pImpl_->operator-(sys);
        }
        
        /*!
            This is the overloaded "-" operator for the SystemHandle Class.
        */
        double operator-(const double& valueSys){
            return pImpl_->operator-(valueSys);
        }

        /*!
            This is the overloaded "*" operator for the SystemHandle Class.
        */
        double operator*(const System& sys){
            if (this == &sys){
                return pImpl_->getValue() * pImpl_->getValue();
            }

            return pImpl_->operator*(sys);
        }
        
        /*!
            This is the overloaded "*"" operator for the SystemHandle Class.
        */
        double operator*(const double& valueSys){
            return pImpl_->operator*(valueSys);
        }

        /*!
            This is the overloaded "/" operator for the SystemHandle Class.
        */
        double operator/(const System& sys){
            if (this == &sys){
                return 1.0;
            }

            return pImpl_->operator/(sys);
        }
        
        /*!
            This is the overloaded "/" operator for the SystemHandle Class.
        */
        double operator/(const double& valueSys){
            return pImpl_->operator/(valueSys);
        }
};

double operator+(const double& valueSys, const System& sys);
double operator-(const double& valueSys, const System& sys);
double operator*(const double& valueSys, const System& sys);
double operator/(const double& valueSys, const System& sys);

#endif