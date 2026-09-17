#include "Event_Processing_h.cpp"
#include <iostream>

Event::Event(const string &id, EventType t, const string &time, int sev)
    : eventID(id), type(t), timestamp(time), severity(sev) {}

string Event::getID() const { return eventID; }
EventType Event::getType() const { return type; }
string Event::getTimestamp() const { return timestamp; }
int Event::getSeverity() const { return severity; }

string Event::getTypeString() const
{
    switch (type)
    {
    case EventType::TrafficAccident:
        return "Traffic Accident";
    case EventType::PowerFailure:
        return "Power Failure";
    case EventType::NetworkOverload:
        return "Network Overload";
    case EventType::WeatherAlert:
        return "Weather Alert";
    }
    return "Unknown";
}

void Event::display() const
{
    cout << "[" << timestamp << "] " << eventID << " -- " << getTypeString()
         << " (Severity " << severity << ")" << endl;
}

EmergencyEvent::EmergencyEvent(const string &id, EventType t, const string &time,
                               int sev, const string &why)
    : Event(id, t, time, sev), reason(why) {}

string EmergencyEvent::getReason() const { return reason; }

void EmergencyEvent::display() const
{
    Event::display();
    cout << "  -> Override reason: " << reason << endl;
}