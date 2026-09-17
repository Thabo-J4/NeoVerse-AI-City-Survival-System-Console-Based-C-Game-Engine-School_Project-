#include "City_Data_h.cpp"
#include <iostream>
using namespace std;

SensorRead::SensorRead(const string &time, int pop, double energy, double traffic)
    : timestamp(time), population(pop), energyUsage(energy), trafficDensity(traffic) {}

string SensorRead::getTimestamp() const { return timestamp; }
int SensorRead::getPopulation() const { return population; }
double SensorRead::getEnergyUsage() const { return energyUsage; }
double SensorRead::getTrafficDensity() const { return trafficDensity; }

void SensorRead::display() const
{
    cout << "[" << timestamp << "] Pop:" << population
         << " | Energy: " << energyUsage << " MWh"
         << " | Traffic: " << trafficDensity << endl;
}

CityLog::CityLog(const string &time, const string &msg)
    : timestamp(time), message(msg) {}

string CityLog::getTimestamp() const { return timestamp; }
string CityLog::getMessage() const { return message; }

void CityLog::display() const
{
    cout << "[" << timestamp << "] " << message << endl;
}