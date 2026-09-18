#ifndef CITYCOMPONENT_H
#define CITYCOMPONENT_H
#include <iostream>
#include <string>
using namespace std;

class CityComponent
{
protected:
    int componentID; // its protected so that derived classes can use it directly
    string name;
    bool active; // it tracks activate or deactivate state

public:
    CityComponent(int id, const string &n);
    virtual ~CityComponent(); // virtual destructor, it is required for polymorphic base classes

    void activate();
    void deactivate();
    string getStatus() const;

    // Pure virtual, it focres every derived system to define its own event handling
    virtual void processEvent(const string &eventDescription) = 0;
};

#endif