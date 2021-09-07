#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "./system.h"

using namespace std;

//! Class Flow
/**
* This Class represents a flow in the General Systems Theory implemented in this code.
*/
class Flow{

    protected:
        string name; /*!< This attribute contains a name for the flow. */
        System* source; /*!< This attribute stores a pointer to the source system of a flow. */
        System* target; /*!< This attribute stores a pointer to the target system of a flow. */
        bool isAddedToModel; /*!< This attribute is True if the Flow is added to a Model, and it is False otherwise. */

    public:
        friend class Model; /*!< This Class represents a model in the General Systems Theory implemented in this code. */

        /*!
            This is the default constructor for the Flow Class.
        */
        Flow():isAddedToModel(false){}
        
        /*!
            This is a more elaborated constructor for the Flow Class.
            \param name the name of the Flow.
            \param source a pointer to the source system of the Flow.
            \param target a pointer to the target system of the Flow.
            \return Flow - a Flow Class object, with it's isCopy attribute set to false.
        */
        Flow(string name = "", System* source = NULL, System* target = NULL):name(name), source(source), target(target), isAddedToModel(false){}
        
        /*!
            This is the default destructor for the Flow Class.
        */
        virtual ~Flow(){
            /*
             * Verifying if the flow is a copy, if true it's instances for source and target should be deleted
             * to avoid memory leak.
             */
            if (!(source->getIsAddedToModel())){
                delete(source);
            }
            if (!(target->getIsAddedToModel())){
                delete(target);
            }
        }

        /*!
            A pure virtual method that will be inherited by subclasses created by the user, and that will contain
            an equation that will be executed by the model.
        */
        virtual double execute() = 0;

        /*!
            Returns the name attribute in the Flow Class.
            \return string - the content name attribute.  
        */
        string getName() const{
            return name;
        }
                
        /*!
            Sets the name attribute in the Flow Class.
            \param flowName which will be set to the current flow.
        */
        void setName(string flowName){
            name = flowName;
        }

        /*!
            Returns the source attribute in the Flow Class.  
            \return System* - the pointer of the source system. 
        */
        System* getSource() const{
            return source;
        }

        /*!
            Sets the source attribute in the Flow Class. 
            \param sourceSys a pointer to the source target.
        */
        void setSource(System* sourceSys){
            source = sourceSys;
        }

        /*!
            Sets the pointer of the source attribute as NULL.
        */
        void clearSource() {
            source = NULL;
        }

        /*!
            Returns the target attribute in the Flow Class. 
            \return System* - the pointer of the target system. 
        */
        System* getTarget() const{
            return target;
        }
        
        /*!
            Sets the target attribute in the Flow Class.   
            \param targetSys a pointer to the target system.
        */
        void setTarget(System* targetSys) {
            target = targetSys;
        }

        /*!
            Sets the pointer of the target attribute as NULL.
        */
        void clearTarget() {
            target = NULL;
        }

    private:
        /*!
            Returns the isAddedToModel attribute in the Flow Class. 
            \return bool - the content of isAddedToModel attribute.
        */
        bool getIsAddedToModel() const{
            return isAddedToModel;
        }
        
        /*!
            Sets the isAddedToModel attribute in the Flow Class.   
            \param flowInModel which will be set to the current flow.
        */
        void setIsAddedToModel(bool flowInModel) {
            isAddedToModel = flowInModel;
        }

        /*!
            This is the copy constructor for the Flow Class.
            \param flow the flow that is going to be cloned.
        */
        Flow (const Flow& flow){
            if (this == &flow){
                return;
            }

            if(getSource() != NULL && !(source->getIsAddedToModel())){
                delete (getSource());
            }

            if(getTarget() != NULL && !(target->getIsAddedToModel())){
                delete (getTarget());
            }
            
            System* sourceCopy = new System(flow.getSource()->getName(), flow.getSource()->getValue());
            System* targetCopy = new System(flow.getTarget()->getName(), flow.getTarget()->getValue());
            
            name = flow.getName();           
            source = sourceCopy;
            target = targetCopy;
            isAddedToModel = false;
        }

        /*!
            This is the overloaded assignment operator for the Flow Class.
        */
        Flow& operator=(const Flow& flow){
            if (this == &flow){
                return *this;
            }

            if(getSource() != NULL && !(source->getIsAddedToModel())){
                delete (getSource());
            }

            if(getTarget() != NULL && !(target->getIsAddedToModel())){
                delete (getTarget());
            }

            System* sourceCopy = new System(flow.getSource()->getName(), flow.getSource()->getValue());
            System* targetCopy = new System(flow.getTarget()->getName(), flow.getTarget()->getValue());

            name = flow.getName();
            source = sourceCopy;
            target = targetCopy;
            isAddedToModel = false;

            return *this;
        }

};

#endif