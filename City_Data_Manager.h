#ifndef CITYDATAMANAGER_H
#define CITYDATAMANAGER_H

#include <vector>
#include <list>
#include "City_Data.h"

class CityDataManager
{
private:
    vector<SensorRead> dailyReadings; // indexed access, present data
    list<CityLog> historicalLogs;     // unbound growth, full city history

public:
    // Insert new data
    void addReading(const SensorRead &reading); // 0(1) amortised, push back on vector
    void addLog(const CityLog &log);            // 0(1), push back on list

    // Remove outdated data
    void removeOldReadings();                             // 0(n), erase from vector front
    void removelogsBefore(const string &cutoffTimestamp); // 0(n), must walk the list

    // Traverse and display data
    void displayReadings() const; // 0(n)
    void displayLogs() const;     // 0(n)

    int readingCount() const;
    int LogCount() const;
};

#endif