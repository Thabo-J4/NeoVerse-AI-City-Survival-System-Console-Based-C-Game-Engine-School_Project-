#include "Event_Processing.h"
#include <iostream>

Event::Event(const string &id, EventType t, const string &time, int sev)
    : eventID(id), type(t), timestamp(time), severity(sev) {}

string Event::getID() const { return eventID; }
EventType Event::getType() const { return type; }
string Event::getTimestamp() const { return timestamp; }
int Event::getSeverity() const { return severity; }

string Event::type_to_string(EventType t)
{
    switch (t)
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

EventType Event::stringToType(const string &str)
{
    if (str == "Traffic Accident")
        return EventType::TrafficAccident;
    if (str == "Power Failure")
        return EventType::PowerFailure;
    if (str == "Network Overload")
        return EventType::NetworkOverload;
    return EventType::WeatherAlert;
}

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