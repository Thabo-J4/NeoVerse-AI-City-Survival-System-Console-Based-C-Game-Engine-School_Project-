#include "City_Data_Manager.h"
#include <iostream>
using namespace std;

void CityDataManager::addReading(const SensorRead &reading)
{
    dailyReadings.push_back(reading); // 0(1) amortised
}

void CityDataManager::addLog(const CityLog &Log)
{
    historicalLogs.push_back(Log); // 0(1)
}

void CityDataManager::removeOldReadings()
{
    if (!dailyReadings.empty())
    {
        dailyReadings.erase(dailyReadings.begin());
    }
}

void CityDataManager::removelogsBefore(const string &cutoffTimestamp)
{
    auto it = historicalLogs.begin();
    while (it != historicalLogs.end())
    {
        if (it->getTimestamp() < cutoffTimestamp)
        {
            it = historicalLogs.erase(it); // 0(1) per erase, no shifting
        }
        else
        {
            ++it;
        }
    }
}

void CityDataManager::displayReadings() const
{
    for (int i = 0; i < static_cast<int>(dailyReadings.size()); i++)
    {
        dailyReadings[i].display(); // 0(1) random access per element
    }
}

void CityDataManager::displayLogs() const
{
    for (const CityLog &Log : historicalLogs)
    {
        Log.display(); // sequential traversal
    }
}

int CityDataManager::readingCount() const { return static_cast<int>(dailyReadings.size()); }
int CityDataManager::LogCount() const { return static_cast<int>(historicalLogs.size()); }