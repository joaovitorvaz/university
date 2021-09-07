#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "./model.h"

using namespace std;

//! Class ModelImpl
/**
* This Class represents a ModelImpl in the General Systems Theory implemented in this code.
*/
class ModelImpl : public Model{

    protected:
        string name; /*!< This attribute contains a name for the model. */
        double time; /*!< This attribute contains the current time in which the operations in the model is being executed. */

        vector<System*> systems; /*!< This attribute stores pointers to the systems contained in the model. */
        vector<Flow*> flows; /*!< This attribute stores pointers to the flows contained in the model. */   
        static vector<Model*> models; /*!< This attribute stores pointers to the models present in the API. */     
        
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

    public:             
        typedef vector<System *>::iterator systemIterator;
        typedef vector<Flow *>::iterator flowIterator;
        typedef vector<Model *>::iterator momdelIterator;

        systemIterator beginSystems(); /*!< Returns the iterator to the beginning of systems attribute. */
        systemIterator endSystems(); /*!< Returns the iterator to the end of systems attribute. */
        flowIterator beginFlows(); /*!< Returns the iterator to the beginning of flows attribute. */
        flowIterator endFlows(); /*!< Returns the iterator to the end of flows attribute. */
        modelIterator beginModels(); /*!< Returns the iterator to the beginning of models attribute. */
        modelIterator endModels(); /*!< Returns the iterator to the end of models attribute. */
        
        /*!
            This is the default constructor for the ModelImpl Class. 
            \param name the name of the ModelImpl Class.
            \param time the time for the ModelImpl Class to run.
            \return ModelImpl - a ModelImpl Class object.
        */
        ModelImpl(string name="", double time=0.0);
        
        /*!
            This is the default destructor for the ModelImpl Class.
        */
        virtual ~ModelImpl();
            
        /*!
            Executes all the flows in the ModelImpl.
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
           \param sys which will be removed from the vector system.  
        */ 
        void remove(System* sys);
      
        /*!
           Removes a flow's pointer on the flows vector.
           \param flow which will be removed from the vector flows. 
        */
        void remove(Flow* flow);

        /*!
            Sets the name attribute in the ModelImpl Class.
            \param modelName which will be set to the current model.
        */
        void setName(string modelName);

        /*!
            Returns the name attribute in the ModelImpl Class.
            \return string - the name attribute.
        */
        string getName() const;

        /*!
            Sets the time attribute in the ModelImpl Class.
            \param currentTime which will be set to the current model.
        */
        void setTime(double currentTime);

        /*!
            Returns the time attribute in the ModelImpl Class.
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
            This method increments the time attribute in the ModelImpl Class.
            \param increment which will define by how much time should increment.
        */
        void incrementTime(double increment);

        /*!
            Returns a system in the index-th position of the systems attribute ModelImpl Class.
            \return System* - a system in the index-th position of the systems attribute.
        */
        System* getSystem(int index);

        /*!
            Returns a flow in the index-th position of the flows attribute ModelImpl Class.
            \return Flow* - a flow in the index-th position of the systems attribute.
        */
        Flow* getFlow(int index);

    private:
        /*!
            This is the copy constructor for the ModelImpl Class.
            \param model the ModelImpl that is going to be cloned.
        */
        ModelImpl (const ModelImpl& model);
        
        /*!
            This is the overloaded assignment operator for the ModelImpl Class.
        */
        void operator=(const ModelImpl& model);
};

#endif