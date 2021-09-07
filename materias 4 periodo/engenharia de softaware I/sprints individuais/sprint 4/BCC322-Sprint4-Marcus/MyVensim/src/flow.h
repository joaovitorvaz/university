#ifndef FLOW_H
#define FLOW_H

#include "./system.h"

using namespace std;

//! Class Flow
/**
* This Class represents a flow in the General Systems Theory implemented in this code.
*/
class Flow{

    public:
        friend class Model; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
        friend class ModelImpl; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
        friend class UnitFlow; /*!< This Class is used to test the copy constructor and assignment operator of the Flow class. */
        
        /*!
            This is the default destructor for the Flow Class.
        */
        virtual ~Flow(){}

        /*!
            A pure virtual method that will be inherited by subclasses created by the user, and that will contain
            an equation that will be executed by the model.
        */
        virtual double execute() = 0;

        /*!
            Returns the name attribute in the Flow Class.
            \return string - the content name attribute.  
        */
        virtual string getName() const = 0;
                
        /*!
            Sets the name attribute in the Flow Class.
            \param flowName which will be set to the current flow.
        */
        virtual void setName(string flowName) = 0;

        /*!
            Returns the source attribute in the Flow Class.  
            \return System* - the pointer of the source system. 
        */
        virtual System* getSource() const = 0;

        /*!
            Sets the source attribute in the Flow Class. 
            \param sourceSys a pointer to the source target.
        */
        virtual void setSource(System* sourceSys) = 0;

        /*!
            Sets the pointer of the source attribute as NULL.
        */
        virtual void clearSource() = 0;

        /*!
            Returns the target attribute in the Flow Class. 
            \return System* - the pointer of the target system. 
        */
        virtual System* getTarget() const = 0;
        
        /*!
            Sets the target attribute in the Flow Class.   
            \param targetSys a pointer to the target system.
        */
        virtual void setTarget(System* targetSys) = 0;

        /*!
            Sets the pointer of the target attribute as NULL.
        */
        virtual void clearTarget() = 0;
};

#endif