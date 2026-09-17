#include "Event_Processor_h.cpp"
#include <iostream>
#include <algorithm>
using namespace std;

void EventProcessor::reportEvent(const Event &e)
{
    incomingEvents.push(e);
}

Event EventProcessor::processNextEvent()
{
    Event front = incomingEvents.front();
    incomingEvents.pop(); // removes oldest event
    return front;
}

bool EventProcessor::hasEvents() const
{
    return !incomingEvents.empty();
}

void EventProcessor::raiseEmergency(const EmergencyEvent &e)
{
    emergencyOverrides.push(e);
}

EmergencyEvent EventProcessor::resolveEmergency()
{
    EmergencyEvent top = emergencyOverrides.top();
    emergencyOverrides.pop(); // resolves the most RECENT emergency first
    return top;
}

bool EventProcessor::hasEmergencies() const
{
    return !emergencyOverrides.empty();
}

//<algorithm>::copy_if, using algorithm to prioritise or filter events
vector<Event> EventProcessor::filterBySeverity(vector<Event> allEvents, int minSeverity) const
{
    vector<Event> result;
    copy_if(allEvents.begin(), allEvents.end(), back_inserter(result),
            [minSeverity](const Event &e)
            { return e.getSeverity() >= minSeverity; });
    return result;
}

void EventProcessor::sortBySeverityDescending(vector<Event> &allEvents) const
{
    sort(allEvents.begin(), allEvents.end(),
         [](const Event &a, const Event &b)
         { return a.getSeverity() > b.getSeverity(); });
}