#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <map>
#include <cstring>

#include "./flow.h"

using namespace std;

//! Class Model
/**
* This Class represents a model in the General Systems Theory implemented in this code.
*/
class Model{

    public:        
        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        
        virtual systemIterator beginSystems() = 0; /*!< Returns the iterator to the beginning of systems attribute. */
        virtual systemIterator endSystems() = 0; /*!< Returns the iterator to the end of systems attribute. */
        virtual flowIterator beginFlows() = 0; /*!< Returns the iterator to the beginning of flows attribute. */
        virtual flowIterator endFlows() = 0; /*!< Returns the iterator to the end of flows attribute. */

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
           Adds a system's pointer to the systems vector.
           \param sys the system to be added.
        */ 
        virtual void add(System* sys) = 0;
        
        /*!        
           Adds a flow's pointer to the flows vector. 
           \param flow the flow to be added.
        */ 
        virtual void add(Flow* flow) = 0;
        
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