
#ifndef CITYDATA_H
#define CITYDATA_H

#include <string>
using namespace std;

class SensorRead
{
private:
    string timestamp;
    int population;
    double energyUsage; // in MWh
    double trafficDensity;

public:
    SensorRead() = default;
    SensorRead(const string &time, int pop, double energy, double traffic);

    string getTimestamp() const;
    int getPopulation() const;
    double getEnergyUsage() const;
    double getTrafficDensity() const;
    void display() const;
};

class CityLog
{
private:
    string timestamp;
    string message;

public:
    CityLog() = default;
    CityLog(const string &time, const string &msg);

    string getTimestamp() const;
    string getMessage() const;
    void display() const;
};

#endif