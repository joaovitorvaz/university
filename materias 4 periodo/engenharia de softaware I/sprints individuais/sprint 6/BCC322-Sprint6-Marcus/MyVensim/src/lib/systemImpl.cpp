#include "../include/systemImpl.h"

using namespace std;

SystemBody::SystemBody(string name, double value):name(name), value(value){}

SystemBody::~SystemBody(){}

void SystemBody::setName(string sysName){
    name = sysName;
}

string SystemBody::getName() const {
    return name;
}    

void SystemBody::setValue(double sysValue){
    value = sysValue;
}

double SystemBody::getValue() const{
    return value;
}

double SystemBody::operator+(const System& sys){
    return getValue() + sys.getValue();
}

double SystemBody::operator+(const double& valueSys){
    return valueSys + getValue();
}

double operator+(const double& valueSys, const System& sys){
    return sys.getValue() + valueSys;
}

double  SystemBody::operator-(const System& sys){
    return getValue() - sys.getValue();
}

double SystemBody::operator-(const double& valueSys){
    return getValue() - valueSys;
}

double operator-(const double& valueSys, const System& sys){
    return valueSys - sys.getValue();
}

double SystemBody::operator*(const System& sys){
    return getValue() * sys.getValue();
}

double SystemBody::operator*(const double& valueSys){
    return getValue() * valueSys;
}

double operator*(const double& valueSys, const System& sys){
    return valueSys * sys.getValue();
}

double SystemBody::operator/(const System& sys){
    return getValue() / sys.getValue();
}

double SystemBody::operator/(const double& valueSys){
    return getValue() / valueSys;
}

double operator/(const double& valueSys, const System& sys){
    return valueSys / sys.getValue();
}