#include "Event_Processing_h.cpp"
#include <iostream>
using namespace std;
#ifndef EVENTPROCESSOR_H
#define EVENTPROCESSOR_H

#include <queue>
#include <stack>
#include <vector>

class EventProcessor
{
private:
    queue<Event> incomingEvents;              // FIFO, normal city events
    stack<EmergencyEvent> emergencyOverrides; // LIFO, critical overrides
public:
    // Queue operations
    void reportEvent(const Event &e);
    Event processNextEvent();
    bool hasEvents() const;

    // Stack operations
    void raiseEmergency(const EmergencyEvent &e);
    EmergencyEvent resolveEmergency();
    bool hasEmergencies() const;

    // algorithm
    vector<Event> filterBySeverity(vector<Event> allEvents, int minSeverity) const;
    void sortBySeverityDescending(vector<Event> &allEvents) const;
};

#endif