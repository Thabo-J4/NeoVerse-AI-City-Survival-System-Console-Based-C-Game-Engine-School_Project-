#include "City_Component.h"
#include <iostream>
using namespace std;

CityComponent::CityComponent(int id, const string &n)
    : componentID(id), name(n), active(false) {}

CityComponent::~CityComponent()
{
    cout << name << " (ID " << componentID << ") shutting down." << endl;
}

void CityComponent::activate()
{
    active = true;
    cout << name << " is activated." << endl;
}

void CityComponent::deactivate()
{
    active = false;
    cout << name << " is deactivated." << endl;
}

string CityComponent::getStatus() const
{
    return name + " is " + (active ? "ACTIVE" : "INACTIVE");
}