#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "./flowImpl.h"

using namespace std;

//! Class Model
/**
* This Class represents a model in the General Systems Theory implemented in this code.
*/
class Model{

    protected:
        /*!        
           Adds a system's pointer to the systems vector.
           \param sys the system to be added.
        */ 
        virtual void add(System* sys) = 0;
        
        /*!        
           Adds a flow's pointer to the flows vector. 
           \param flow the flow to be added.
        */ 
        virtual void add(Flow* flow) = 0;

    public: 
        friend class UnitModel; /*!< Class to support on the unit tests */

        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        typedef vector<Model*>::iterator modelIterator;
        
        virtual systemIterator beginSystems() = 0; /*!< Returns the iterator to the beginning of systems attribute. */
        virtual systemIterator endSystems() = 0; /*!< Returns the iterator to the end of systems attribute. */
        virtual flowIterator beginFlows() = 0; /*!< Returns the iterator to the beginning of flows attribute. */
        virtual flowIterator endFlows() = 0; /*!< Returns the iterator to the end of flows attribute. */
        virtual modelIterator beginModels() = 0; /*!< Returns the iterator to the beginning of models attribute. */
        virtual modelIterator endModels() = 0; /*!< Returns the iterator to the end of models attribute. */

        /*!
            This is the default destructor for the Model Class.
        */
        virtual ~Model(){}
            
        /*!
            Executes all the flows in the model.
            \param start the initial time.
            \param final the final time.
            \param increment represents the iteration step.
        */
        virtual void execute(double start, double final, double increment) = 0;

        /*!
            Creates a model and returns the model pointer.
            \param name the model's name.
            \param time the initial time.
        */
        static Model* createModel(string name="", double time=0);

        /*!
            Creates a flow and returns the flow pointer.
            \param name the flow's name.
            \param source a pointer to the source system.
            \param target a pointer to the target system.
        */
        template <typename F_IMPL>
        Flow* createFlow(string name = "", System* source = NULL, System* target = NULL){
            Flow* flow = new FlowHandle<F_IMPL>(name, source, target);
            add(flow);
            return flow;
        }

        /*!
            Creates a system and returns the system pointer.
            \param name the system's name.
            \param value the value of the system.
        */
        virtual System* createSystem(string name, double value) = 0;       
        
        /*!        
           Removes a system's pointer on the systems vector.
           \param sys which will be removed from the vector flows.  
        */ 
        virtual void remove(System* sys) = 0;
      
        /*!
           Removes a flow's pointer on the flows vector.
           \param flow which will be removed from the vector flows. 
        */
        virtual void remove(Flow* flow) = 0;

        /*!
            Sets the name attribute in the Model Class.
            \param modelName which will be set to the current model.
        */
        virtual void setName(string modelName) = 0;

        /*!
            Returns the name attribute in the Model Class.
            \return string - the name attribute.
        */
        virtual string getName() const = 0;

        /*!
            Sets the time attribute in the Model Class.
            \param currentTime which will be set to the current model.
        */
        virtual void setTime(double currentTime) = 0;

        /*!
            Returns the time attribute in the Model Class.
            \return double - the time attribute.
        */
        virtual double getTime() const = 0;

        /*!
            Sets the source system of a flow.
            \param flow the flow that will receive a source system.
            \param sourceSys a pointer to the source system.
        */
        virtual void setSource(Flow* flow, System* sourceSys) = 0;

        /*!
            Returns the source system of a flow.
            \param flow the flow that will return his source system.
            \return System* - the pointer of the source system. 
        */
        virtual System* getSource(Flow* flow) = 0;

        /*!
            Sets the pointer of a flow's source system as NULL.
            \param flow the flow which will have his source system changed.
        */
        virtual void clearSource(Flow* flow) = 0;

        /*!
            Sets the target system of a flow.
            \param flow the flow that will receive a target system.
            \param targetSys a pointer to the target system.
        */
        virtual void setTarget(Flow* flow, System* targetSys) = 0;

        /*!
            Returns the target system of a flow.
            \param flow the flow that will return his target system.
            \return System* - the pointer of the target system. 
        */
        virtual System* getTarget(Flow* flow) = 0;

        /*!
            Sets the pointer of a flow's target system as NULL.
            \param flow the flow which will have his target system changed.
        */
        virtual void clearTarget(Flow* flow) = 0;

        /*!
            This method increments the time attribute in the Model Class.
            \param increment which will define by how much time should increment.
        */
        virtual void incrementTime(double increment) = 0;

        /*!
            Returns a system in the index-th position of the systems attribute Model Class.
            \return System* - a system in the index-th position of the systems attribute.
        */
        virtual System* getSystem(int index) = 0;

        /*!
            Returns a flow in the index-th position of the flows attribute Model Class.
            \return Flow* - a flow in the index-th position of the systems attribute.
        */
        virtual Flow* getFlow(int index) = 0;

};

#endif