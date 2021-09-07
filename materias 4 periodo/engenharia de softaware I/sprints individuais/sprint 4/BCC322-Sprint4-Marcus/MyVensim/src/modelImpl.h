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


    public:             
        typedef vector<System *>::iterator systemIterator;
        typedef vector<Flow *>::iterator flowIterator;

        systemIterator beginSystems(); /*!< Returns the iterator to the beginning of systems attribute. */
        systemIterator endSystems(); /*!< Returns the iterator to the end of systems attribute. */
        flowIterator beginFlows(); /*!< Returns the iterator to the beginning of flows attribute. */
        flowIterator endFlows(); /*!< Returns the iterator to the end of flows attribute. */
        
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