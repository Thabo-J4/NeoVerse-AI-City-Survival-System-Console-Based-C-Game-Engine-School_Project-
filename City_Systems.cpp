#include "City_Systems.h"
#include <iostream>
using namespace std;

// Power System
PowerSystem::PowerSystem(int id, const string &n, double level)
    : CityComponent(id, n), powerLevel(level) {}

PowerSystem::~PowerSystem()
{
    cout << "Power System Cleanup Complete." << endl;
}

void PowerSystem::supplyPower()
{
    cout << name << " supplying power at level " << powerLevel << endl;
}

void PowerSystem::processEvent(const std::string &eventDescription)
{
    cout << "[Power System] Handling event: " << eventDescription
         << " -> rerouting grid, adjusting powerLevel." << endl;
    powerLevel -= 5.0;
}

// Transport System
TransportSystem::TransportSystem(int id, const string &n, int flow)
    : CityComponent(id, n), trafficFlow(flow) {}

TransportSystem::~TransportSystem()
{
    cout << "Transport System Cleanup Complete." << endl;
}

void TransportSystem::manageTraffic()
{
    cout << name << " managing traffic flow: " << trafficFlow << endl;
}

void TransportSystem::processEvent(const string &eventDescription)
{
    cout << "[Transport System] Handling event: " << eventDescription
         << " -> rerouting traffic signals." << endl;
    trafficFlow += 10;
}

// Health System
HealthSystem::HealthSystem(int id, const string &n, int hospitals)
    : CityComponent(id, n), hospitalCnt(hospitals) {}

HealthSystem::~HealthSystem()
{
    cout << "Health System Cleanup Complete. " << endl;
}

void HealthSystem::provideCare()
{
    cout << name << " coordinating care across " << hospitalCnt << " hospitals." << endl;
}

void HealthSystem::processEvent(const string &eventDescription)
{
    cout << "[Health System] Handling event: " << eventDescription
         << " -> dispatching emergency medical response." << endl;
}

// Security System
SecuritySystem::SecuritySystem(int id, const string &n, int threat)
    : CityComponent(id, n), threatLevel(threat) {}

SecuritySystem::~SecuritySystem()
{
    cout << "Security System Cleanup Complete." << endl;
}

void SecuritySystem::monitorCity()
{
    cout << name << " monitoring city, threat level: " << threatLevel << endl;
}

void SecuritySystem::processEvent(const string &eventDescription)
{
    cout << "[Security System] Handling event: " << eventDescription
         << " -> raising alert status." << endl;
    threatLevel += 1;
}