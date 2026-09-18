#include "Performance_Tools.h"
#include <algorithm>
#include <iostream>
using namespace std;

// Sorting, sort(), ordering
void PerformanceTools::sortByEnergyUsage(vector<SensorRead> &readings)
{
    sort(readings.begin(), readings.end(),
         [](const SensorRead &a, const SensorRead &b)
         {
             return a.getEnergyUsage() < b.getEnergyUsage();
         });
}

// a single linear scan keeping the current max is unavoidable but also sufficient, no need to pay to fully sort the data just to read off one extreme value.
SensorRead PerformanceTools::findHighestUsage(const vector<SensorRead> &readings)
{
    auto it = max_element(readings.begin(), readings.end(),
                          [](const SensorRead &a, const SensorRead &b)
                          {
                              return a.getEnergyUsage() < b.getEnergyUsage();
                          });
    return *it;
}

// This is the min element same, opposite direction of max element
SensorRead PerformanceTools::findLowestUsage(const vector<SensorRead> &readings)
{
    auto it = min_element(readings.begin(), readings.end(),
                          [](const SensorRead &a, const SensorRead &b)
                          {
                              return a.getEnergyUsage() < b.getEnergyUsage();
                          });
    return *it;
}

// count_if element
int PerformanceTools::countCriticalAlerts(const vector<Event> &events, int threshold)
{
    return static_cast<int>(count_if(events.begin(), events.end(),
                                     [threshold](const Event &e)
                                     { return e.getSeverity() >= threshold; }));
}

// find() function
bool PerformanceTools::eventExists(const vector<Event> &events, const string &eventID)
{
    auto it = find_if(events.begin(), events.end(),
                      [&eventID](const Event &e)
                      { return e.getID() == eventID; });
    return it != events.end();
}