#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "./flow.h"

using namespace std;

//! Class FlowImpl
/**
* This Class represents a flow in the General Systems Theory implemented in this code.
*/
class FlowImpl : public Flow{

    protected:
        string name; /*!< This attribute contains a name for the flow. */
        System* source; /*!< This attribute stores a pointer to the source system of a flow. */
        System* target; /*!< This attribute stores a pointer to the target system of a flow. */

        /*!
            This is the copy constructor for the FlowImpl Class.
            \param flow the flow that is going to be cloned.
        */
        FlowImpl(const Flow& flow);

        /*!
            This is the overloaded assignment operator for the FlowImpl Class.
        */
        FlowImpl& operator=(const Flow& flow);

    public:
        friend class Model; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
        friend class ModelImpl; /*!< This Class represents the implementation of a model in the General Systems Theory implemented in this code. */
        friend class UnitFlow; /*!< This Class is used to test the copy constructor and assignment operator of the FlowImpl class. */

        /*!
            This is the default constructor for the FlowImpl Class.
            \param name the name of the Flow.
            \param source a pointer to the source system of the Flow.
            \param target a pointer to the target system of the Flow.
            \return Flow - a FlowImpl Class object, with it's isCopy attribute set to false.
        */
        FlowImpl(string name = "", System* source = NULL, System* target = NULL);
        
        /*!
            This is the default destructor for the FlowImpl Class.
        */
        virtual ~FlowImpl();

        /*!
            A pure virtual method that will be inherited by subclasses created by the user, and that will contain
            an equation that will be executed by the model.
        */
        virtual double execute() = 0;

        /*!
            Returns the name attribute in the FlowImpl Class.
            \return string - the content name attribute.  
        */
        string getName() const;

        /*!
            Sets the name attribute in the FlowImpl Class.
            \param flowName which will be set to the current flow.
        */
        void setName(string flowName);

        /*!
            Returns the source attribute in the FlowImpl Class.  
            \return System* - the pointer of the source system. 
        */
        System* getSource() const;

        /*!
            Sets the source attribute in the FlowImpl Class. 
            \param sourceSys a pointer to the source target.
        */
        void setSource(System* sourceSys);

        /*!
            Sets the pointer of the source attribute as NULL.
        */
        void clearSource();

        /*!
            Returns the target attribute in the FlowImpl Class. 
            \return System* - the pointer of the target system. 
        */
        System* getTarget() const;
        
        /*!
            Sets the target attribute in the FlowImpl Class.   
            \param targetSys a pointer to the target system.
        */
        void setTarget(System* targetSys);

        /*!
            Sets the pointer of the target attribute as NULL.
        */
        void clearTarget();
};

#endif