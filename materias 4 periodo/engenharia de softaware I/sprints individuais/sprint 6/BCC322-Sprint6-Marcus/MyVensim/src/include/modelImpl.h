#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "./model.h"
#include "./handlebody.h"

using namespace std;

//! Class ModelBody
/**
* This Class represents a model in the General Systems Theory implemented in this code.
*/
class ModelBody : public Body{

    protected:
        string name; /*!< This attribute contains a name for the model. */
        double time; /*!< This attribute contains the current time in which the operations in the model is being executed. */

        vector<System*> systems; /*!< This attribute stores pointers to the systems contained in the model. */
        vector<Flow*> flows; /*!< This attribute stores pointers to the flows contained in the model. */   
        static vector<Model*> models; /*!< This attribute stores pointers to the models present in the API. */     

    private:  
        /*!
            This is the copy constructor for the ModelBody Class.
            \param model the ModelBody that is going to be cloned.
        */
        ModelBody (const ModelBody& model);
        
        /*!
            This is the overloaded assignment operator for the ModelBody Class.
        */
        ModelBody& operator=(const ModelBody& model);

    public:             
        typedef vector<System *>::iterator systemIterator;
        typedef vector<Flow *>::iterator flowIterator;
        typedef vector<Model *>::iterator modelIterator;

        systemIterator beginSystems(); /*!< Returns the iterator to the beginning of systems attribute. */
        systemIterator endSystems(); /*!< Returns the iterator to the end of systems attribute. */
        flowIterator beginFlows(); /*!< Returns the iterator to the beginning of flows attribute. */
        flowIterator endFlows(); /*!< Returns the iterator to the end of flows attribute. */
        modelIterator beginModels(); /*!< Returns the iterator to the beginning of models attribute. */
        modelIterator endModels(); /*!< Returns the iterator to the end of models attribute. */
        
        /*!
            This is the default constructor for the ModelBody Class. 
            \param name the name of the ModelBody Class.
            \param time the time for the ModelBody Class to run.
            \return ModelBody - a ModelBody Class object.
        */
        ModelBody(string name="", double time=0.0);
        
        /*!
            This is the default destructor for the ModelBody Class.
        */
        virtual ~ModelBody();
            
        /*!
            Executes all the flows in the ModelBody.
            \param start the initial time.
            \param final the final time.
            \param increment represents the iteration step.
        */
        void execute(double start=0.0, double final=0.0, double increment=1.0);

        /*!
            Creates a model and returns the model pointer.
            \param name the model's name.
            \param time the initial time.
        */
        static Model* createModel(string name, double time);

        /*!
            Creates a system and returns the system pointer.
            \param name the system's name.
            \param value the value of the system.
        */
        System* createSystem(string name, double value);
        
        /*!        
           Removes a system's pointer on the systems vector.
           \param sys which will be removed from the vector flows.  
        */ 
        void remove(System* sys);
      
        /*!
           Removes a flow's pointer on the flows vector.
           \param flow which will be removed from the vector flows. 
        */
        void remove(Flow* flow);

        /*!
            Sets the name attribute in the ModelBody Class.
            \param modelName which will be set to the current model.
        */
        void setName(string modelName);

        /*!
            Returns the name attribute in the ModelBody Class.
            \return string - the name attribute.
        */
        string getName() const;

        /*!
            Sets the time attribute in the ModelBody Class.
            \param currentTime which will be set to the current model.
        */
        void setTime(double currentTime);

        /*!
            Returns the time attribute in the ModelBody Class.
            \return double - the time attribute.
        */
        double getTime() const;

        /*!
            Sets the source system of a flow.
            \param flow the flow that will receive a source system.
            \param sourceSys a pointer to the source system.
        */
        void setSource(Flow* flow, System* sourceSys);

        /*!
            Returns the source system of a flow.
            \param flow the flow that will return his source system.
            \return System* - the pointer of the source system. 
        */
        System* getSource(Flow* flow);

        /*!
            Sets the pointer of a flow's source system as NULL.
            \param flow the flow which will have his source system changed.
        */
        void clearSource(Flow* flow);

        /*!
            Sets the target system of a flow.
            \param flow the flow that will receive a target system.
            \param targetSys a pointer to the target system.
        */
        void setTarget(Flow* flow, System* targetSys);

        /*!
            Returns the target system of a flow.
            \param flow the flow that will return his target system.
            \return System* - the pointer of the target system. 
        */
        System* getTarget(Flow* flow);

        /*!
            Sets the pointer of a flow's target system as NULL.
            \param flow the flow which will have his target system changed.
        */
        void clearTarget(Flow* flow);

        /*!
            This method increments the time attribute in the ModelBody Class.
            \param increment which will define by how much time should increment.
        */
        void incrementTime(double increment);

        /*!        
           Adds a system's pointer to the systems vector.
           \param sys the system to be added.
        */ 
        void add(System* sys);
        
        /*!        
           Adds a flow's pointer to the flows vector. 
           \param flow the flow to be added.
        */ 
        void add(Flow* flow);

        /*!
            Returns a system in the index-th position of the systems attribute ModelBody Class.
            \return System* - a system in the index-th position of the systems attribute.
        */
        System* getSystem(int index);

        /*!
            Returns a flow in the index-th position of the flows attribute ModelBody Class.
            \return Flow* - a flow in the index-th position of the systems attribute.
        */
        Flow* getFlow(int index);
};

//! Class ModelHandle
/**
* This Class represents the handle of a Handle/Body idiom for the Model.
*/
class ModelHandle : public Handle<ModelBody>, public Model{
    protected:
        /*!        
           Adds a system's pointer to the systems vector.
           \param sys the system to be added.
        */ 
        void add(System* sys){
            pImpl_->add(sys);
        }
        
        /*!        
           Adds a flow's pointer to the flows vector. 
           \param flow the flow to be added.
        */ 
        void add(Flow* flow){
            pImpl_->add(flow);
        }

    public:
        friend class UnitModel; /*!< This Class is used to do some unit tests of the Model class. */
        
        typedef vector<System *>::iterator systemIterator;
        typedef vector<Flow *>::iterator flowIterator;
        typedef vector<Model *>::iterator modelIterator;

        systemIterator beginSystems(){return pImpl_->beginSystems();} /*!< Returns the iterator to the beginning of systems attribute. */
        systemIterator endSystems(){return pImpl_->endSystems();} /*!< Returns the iterator to the end of systems attribute. */
        flowIterator beginFlows(){return pImpl_->beginFlows();} /*!< Returns the iterator to the beginning of flows attribute. */
        flowIterator endFlows(){return pImpl_->endFlows();} /*!< Returns the iterator to the end of flows attribute. */
        modelIterator beginModels(){return pImpl_->beginModels();} /*!< Returns the iterator to the beginning of the global models vector. */
        modelIterator endModels(){return pImpl_->endModels();} /*!< Returns the iterator to the end of the global models vector. */   

        /*!
            This is the copy constructor for the ModelHandle Class.
            \param model the ModelHandle that is going to be cloned.
        */
        ModelHandle (const ModelHandle& model){
            //Corrigir
            if (this == &model){
                return;
            }

            pImpl_->detach();
            pImpl_ = model.pImpl_;
        }
        
        /*!
            This is the overloaded assignment operator for the ModelHandle Class.
        */
        ModelHandle& operator=(const ModelHandle& model){
            if(this == &model){
                return *this;
            }
        
            pImpl_->detach();
            pImpl_ = model.pImpl_;
            return *this;
        }

        /*!
            This is the default constructor for the ModelHandle Class. 
            \param name the name of the ModelHandle Class.
            \param time the time for the ModelHandle Class to run.
            \return ModelHandle - a ModelHandle Class object.
        */
        ModelHandle(string name="", double time=0.0){
            pImpl_->setName(name);
            pImpl_->setTime(time);
        }
        
        /*!
            This is the default destructor for the ModelHandle Class.
        */
        virtual ~ModelHandle(){};
            
        /*!
            Executes all the flows in the ModelHandle.
            \param start the initial time.
            \param final the final time.
            \param increment represents the iteration step.
        */
        void execute(double start=0.0, double final=0.0, double increment=1.0){
            pImpl_->execute(start, final, increment);
        }

        /*!
            Creates a system and returns it's pointer.
            \param name the name of the system that will be created.
            \param value the value of the system that will be created.
        */
        System* createSystem(string name="", double value=0.0){
            return pImpl_->createSystem(name, value);
        }

        /*!
            Creates a model and returns it's pointer.
            \param name the name of the model that will be created.
            \param time the initial time of the model that will be created.
        */
        static Model* createModel(string name="", double time=0.0){
            return ModelBody::createModel(name, time);
        }

        /*!
            Sets the name attribute in the ModelHandle Class.
            \param modelName which will be set to the current model.
        */
        void setName(string modelName){
            pImpl_->setName(modelName);
        }

        /*!
            Returns the name attribute in the ModelHandle Class.
            \return string - the name attribute.
        */
        string getName() const{
            return pImpl_->getName();
        }

        /*!
            Sets the time attribute in the ModelHandle Class.
            \param currentTime which will be set to the current model.
        */
        void setTime(double currentTime){
            pImpl_->setTime(currentTime);
        }

        /*!
            Returns the time attribute in the ModelHandle Class.
            \return double - the time attribute.
        */
        double getTime() const{
            return pImpl_->getTime();
        }

        /*!
            This method increments the time attribute in the ModelHandle Class.
            \param increment which will define by how much time should increment.
        */
        void incrementTime(double increment){
            pImpl_->incrementTime(increment);
        }

        /*!        
           Removes a system's pointer on the systems vector.
           \param sys which will be removed from the vector flows.  
        */ 
        void remove(System* sys){
            pImpl_->remove(sys);
        }
      
        /*!
           Removes a flow's pointer on the flows vector.
           \param flow which will be removed from the vector flows. 
        */
        void remove(Flow* flow){
            pImpl_->remove(flow);
        }

        /*!
            Sets the source system of a flow.
            \param flow the flow which will have it's source system changed.
            \param sourceSys a pointer to the source system.
        */
        void setSource(Flow* flow, System* sourceSys){
            pImpl_->setSource(flow, sourceSys);
        }

        /*!
            Returns the source system of a flow.
            \param flow the flow which will have it's source system returned.
            \return System* - the pointer of the source system. 
        */
        System* getSource(Flow* flow){
            return pImpl_->getSource(flow);
        }

        /*!
            Sets the pointer of the source system of a flow as NULL.
            \param flow the flow which will have it's source system changed.
        */
        void clearSource(Flow* flow){
            pImpl_->clearSource(flow);
        }

        /*!
            Sets the target system of a flow.
            \param flow the flow which will have it's target system changed.
            \param targetSys a pointer to the target system.
        */
        void setTarget(Flow* flow, System* targetSys){
            pImpl_->setTarget(flow, targetSys);
        }

        /*!
            Returns the target system of a flow.
            \param flow the flow which will have it's target system returned.
            \return System* - the pointer of the target system. 
        */
        System* getTarget(Flow* flow){
            return pImpl_->getTarget(flow);
        }

        /*!
            Sets the pointer of the target system of a flow as NULL.
            \param flow the flow which will have it's target system changed.
        */
        void clearTarget(Flow* flow){
            pImpl_->clearTarget(flow);
        }

        /*!
            Returns a system in the index-th position of the systems attribute ModelHandle Class.
            \return System* - a system in the index-th position of the systems attribute.
        */
        System* getSystem(int index){
            return pImpl_->getSystem(index);
        }

        /*!
            Returns a flow in the index-th position of the flows attribute ModelHandle Class.
            \return Flow* - a flow in the index-th position of the systems attribute.
        */
        Flow* getFlow(int index){
            return pImpl_->getFlow(index);
        }
};

#endif