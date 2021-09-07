#include "../include/ModelImpl.h"
#include "../include/systemImpl.h"   

vector<Model*> ModelBody::models;

ModelBody::systemIterator ModelBody::beginSystems( void ){return systems.begin();}
ModelBody::systemIterator ModelBody::endSystems( void ){return systems.end();}
ModelBody::flowIterator ModelBody::beginFlows( void ){return flows.begin();} 
ModelBody::flowIterator ModelBody::endFlows( void ){return flows.end();}  
ModelBody::modelIterator ModelBody::beginModels( void ){return models.begin();} 
ModelBody::modelIterator ModelBody::endModels( void ){return models.end();}  

ModelBody::ModelBody(string name, double time):name(name), time(time){}

ModelBody::~ModelBody(){           
    // Delete Flows
    if(!flows.empty()){
        for (Flow* item : flows) {
            delete (item);
        }
        flows.clear();
    }

    // Delete Systems
    if(!systems.empty()){
        for (System* item : systems) {
            delete (item);
        }
        systems.clear();
    }

    // Delete Model
    auto i = beginModels();
    for (Model* item : models){
        if (this == (ModelBody*)item){
            models.erase(i);                    
            break;
        }
        ++i;
    }
}
    
void ModelBody::execute(double start, double final, double increment){
    
    vector<double> results;
    int count = 0;

    for (double k = start; k < final; k += increment){
        // Executes each flow 'i' in the model
        for (Flow* item : flows) {
            results.push_back(item->execute());
        }

        // Updates the system's values associated with each flow 'i' in the model
        count = 0;
        for (Flow* item : flows) {
            if (item->getSource() != NULL){
                item->getSource()->setValue(item->getSource()->getValue() - results[count]);
            }

            if (item->getTarget() != NULL){
                item->getTarget()->setValue(item->getTarget()->getValue() + results[count]);
            }

            count++;
        }

        // Resetting the results vector
        for (auto i = beginFlows(); i != endFlows(); ++i){
            results.pop_back();
        }

        time += increment;
    }

}

Model* Model::createModel(string name, double time){   
    return ModelHandle::createModel(name, time);
}

Model* ModelBody::createModel(string name, double time){
    Model* model = new ModelHandle(name, time);
    models.push_back(model);
    return model;
}

System* ModelBody::createSystem(string name, double value){
    System* system = new SystemHandle(name, value);
    add(system);
    return system;
}

void ModelBody::add(System* sys){
    systems.insert(endSystems(), sys);            
}

void ModelBody::add(Flow* flow){
    flows.insert(endFlows(), flow);       
}

void ModelBody::remove(System* sys){
    auto i = beginSystems();
    for (System* item : systems){
        if (sys == item){
            systems.erase(i);                    
            break;
        }
        ++i;
    }
}

void ModelBody::remove(Flow* flow){
    auto i = beginFlows();
    for (Flow* item : flows){
        if (flow == item){
            flows.erase(i);                   
            break;
        }
        ++i;
    }
}

void ModelBody::setName(string modelName){
    name = modelName;
}

string ModelBody::getName() const{
    return name;
}    

void ModelBody::setTime(double currentTime){
    time = currentTime;
}

double ModelBody::getTime() const{
    return time;
}   

void ModelBody::setSource(Flow* flow, System* sourceSys){
    flow->setSource(sourceSys);
}

System* ModelBody::getSource(Flow* flow){
    return flow->getSource();
}

void ModelBody::clearSource(Flow* flow){
    return flow->clearSource();
}

void ModelBody::setTarget(Flow* flow, System* targetSys){
    flow->setTarget(targetSys);
}

System* ModelBody::getTarget(Flow* flow){
    return flow->getTarget();
}

void ModelBody::clearTarget(Flow* flow){
    return flow->clearTarget();
}

void ModelBody::incrementTime(double increment) {
    time += increment;
}

System* ModelBody::getSystem(int index){
    return systems[index];
}

Flow* ModelBody::getFlow(int index){
    return flows[index];
}

