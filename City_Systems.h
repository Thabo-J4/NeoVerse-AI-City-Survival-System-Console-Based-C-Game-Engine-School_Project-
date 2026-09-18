#ifndef CITYSYSTEMS_H
#define CITYSYSTEMS_H

#include "City_Component.h"
#include <iostream>

class PowerSystem : public CityComponent
{
private:
    double powerLevel;

public:
    PowerSystem(int id, const string &n, double level);
    ~PowerSystem() override;

    void supplyPower();
    void processEvent(const string &eventDescription) override;
};

class TransportSystem : public CityComponent
{
private:
    int trafficFlow;

public:
    TransportSystem(int id, const string &n, int flow);
    ~TransportSystem() override;

    void manageTraffic();
    void processEvent(const string &eventDescription) override;
};

class HealthSystem : public CityComponent
{
private:
    int hospitalCnt;

public:
    HealthSystem(int id, const string &n, int hospitals);
    ~HealthSystem() override;

    void provideCare();
    void processEvent(const string &eventDescription) override;
};

class SecuritySystem : public CityComponent
{
private:
    int threatLevel;

public:
    SecuritySystem(int id, const string &n, int threat);
    ~SecuritySystem() override;

    void monitorCity();
    void processEvent(const string &eventDescription) override;
};

#endif