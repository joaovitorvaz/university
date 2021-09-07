#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include "./system.h"
#include "./flow.h"

using namespace std;

//! Class Model
/**
* This Class represents a model in the General Systems Theory implemented in this code.
*/
class Model{

    protected:
        string name; /*!< This attribute contains a name for the model. */
        double time; /*!< This attribute contains the current time in which the operations in the model is being executed. */
        vector<System*> systems; /*!< This attribute stores pointers to the systems contained in the model. */
        vector<Flow*> flows; /*!< This attribute stores pointers to the flows contained in the model. */       

    public:
        auto beginSystems( void ) const {return systems.begin();} /*!< Returns the iterator to the beginning of systems attribute. */
        auto endSystems( void ) const {return systems.end();} /*!< Returns the iterator to the end of systems attribute. */
        auto beginFlows( void ) const {return flows.begin();} /*!< Returns the iterator to the beginning of flows attribute. */
        auto endFlows( void ) const {return flows.end();} /*!< Returns the iterator to the end of flows attribute. */
                        
        /*!
            This is the default constructor for the Model Class.
        */
        Model(){}
        
        /*!
            This is a more elaborated constructor for the Model Class.
            \param name the name of the Model Class.
            \param time the time for the Model Class to run.
            \return Model - a Model Class object.
        */
        Model(string name="", double time=0.0):name(name), time(time){}
        
        /*!
            This is the default destructor for the Model Class.
        */
        virtual ~Model(){           
            // Deletes Systems
            for (System* item : systems) {
                delete (item);
            }

            // Deletes Flows
            for (Flow* item : flows) {
                delete (item);
            }
        }
            
        /*!
            Executes all the flows in the model.
            \param start the initial time.
            \param final the final time.
            \param increment represents the iteration step.
        */
        void execute(double start=0.0, double final=0.0, double increment=1.0){
            
            vector<double> results;
            int count = 0;

            for (double k = start; k < final; k += increment){
                // Executes each flow 'i' in the model
                for (Flow* item : flows) {
                    double result = item->execute();
                    results.push_back(result);
                }

                // Updates the system's values associated with each flow 'i' in the model
                count = 0;
                for (Flow* item : flows) {
                    System* origin = item->getSource();
                    origin->setValue(origin->getValue() - results[count]);

                    System* destiny = item->getTarget();
                    destiny->setValue(destiny->getValue() + results[count]);

                    count++;
                }

                // Resetting the results vector
                for (auto i = beginFlows(); i != endFlows(); ++i){
                    results.pop_back();
                }

                time += increment;
            }

        }
        
        /*!        
           Adds a system's pointer to the systems vector.
           \param sys the system to be added.
        */ 
        void add(System* sys){
            systems.insert(endSystems(), sys);
            sys->setIsAddedToModel(true);
        }
        
        /*!        
           Adds a flow's pointer to the flows vector. 
           \param flow the flow to be added.
        */ 
        void add(Flow* flow){
            flows.insert(endFlows(), flow);            
            flow->setIsAddedToModel(true);
        }
        
        /*!        
           Removes a system's pointer on the systems vector.
           \param sys which will be removed from the vector flows.  
        */ 
        void remove(System* sys){

            auto i = beginSystems();
            for (System* item : systems){
                if (sys == item){
                    systems.erase(i);
                    item->setIsAddedToModel(false);
                    break;
                }
                ++i;
            }

        }
      
        /*!
           Removes a flow's pointer on the flows vector.
           \param flow which will be removed from the vector flows. 
        */
        void remove(Flow* flow){

            auto i = beginFlows();
            for (Flow* item : flows){
                if (flow == item){
                    flows.erase(i);
                    item->setIsAddedToModel(false);
                    break;
                }
                ++i;
            }

        }

        /*!
            Sets the name attribute in the Model Class.
            \param modelName which will be set to the current model.
        */
        void setName(string modelName){
            name = modelName;
        }

        /*!
            Returns the name attribute in the Model Class.
            \return string - the name attribute.
        */
        string getName() const{
            return name;
        }    

        /*!
            Sets the time attribute in the Model Class.
            \param currentTime which will be set to the current model.
        */
        void setTime(double currentTime){
            time = currentTime;
        }

        /*!
            Returns the time attribute in the Model Class.
            \return double - the time attribute.
        */
        double getTime() const{
            return time;
        }    

        /*!
            This method increments the time attribute in the Model Class.
            \param increment which will define by how much time should increment.
        */
        void incrementTime(double increment) {
            time += increment;
        }

    private: 
        /*!        
           This is the copy constructor for the Model Class.
           \param model the model that is going to be cloned.
           \param systemsVector the vector of system pointers, it prevents memory leak.
           \param flowsVector the vector of flow pointers, it prevents memory leak.      
        */ 
        Model (const Model& model){
            if (this == &model){
                return;
            }

            name = model.getName();
            time = model.getTime();   
            
            for (System* item : systems){
                System* copy(item);
                systems.insert(endSystems(), copy);
            }         

            for (Flow* item : flows){
                Flow* copy(item);
                flows.insert(endFlows(), copy);
            }
           
        }
        
        /*!
            This is the overloaded assignment operator for the Model Class.
        */
        Model& operator=(const Model& model){
            if (this == &model){
                return *this;
            }

            name = model.getName();
            time = model.getTime();


            for (System* item : systems){
                System* copy(item);
                systems.insert(endSystems(), copy);
            }

            for (Flow* item : flows){
                Flow* copy(item);
                flows.insert(endFlows(), copy);
            }

            return *this;
        }
};

#endif