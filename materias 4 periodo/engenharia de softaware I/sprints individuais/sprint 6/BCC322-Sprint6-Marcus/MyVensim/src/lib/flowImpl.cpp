#include "../include/flowImpl.h"

FlowBody::FlowBody(string name, System* source, System* target):name(name), source(source), target(target){}

FlowBody::~FlowBody(){}

string FlowBody::getName() const{
    return name;
}
        
void FlowBody::setName(string flowName){
    name = flowName;
}

System* FlowBody::getSource() const{
    return source;
}

void FlowBody::setSource(System* sourceSys){
    source = sourceSys;
}

void FlowBody::clearSource(){
    source = NULL;
}

System* FlowBody::getTarget() const{
    return target;
}

void FlowBody::setTarget(System* targetSys){
    target = targetSys;
}

void FlowBody::clearTarget(){
    target = NULL;
}