#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

enum class EventType
{
    TrafficAccident,
    PowerFailure,
    NetworkOverload,
    WeatherAlert
};

class Event
{
private:
    string eventID;
    EventType type;
    string timestamp;
    int severity; // used for filtering

public:
    Event() = default;
    Event(const string &id, EventType t, const string &time, int sev);

    string getID() const;
    EventType getType() const;
    string getTimestamp() const;
    int getSeverity() const;
    string getTypeString() const;
    void display() const;
};

class EmergencyEvent : public Event
{
private:
    string reason; // why for the override

public:
    EmergencyEvent() = default;
    EmergencyEvent(const string &id, EventType t, const string &time,
                   int sev, const string &reason);

    string getReason() const;
    void display() const;
};

#endif
