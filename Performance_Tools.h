#ifndef PERFORMANCETOOLS_H
#define PERFORMANCETOOLS_H
#include <iostream>
#include <vector>
#include "City_Data.h"        //Sensor Reading
#include "Event_Processing.h" // Event

class PerformanceTools
{
public:
    // Sorting the sensor readings by energy usage, in ascending order
    static void sortByEnergyUsage(vector<SensorRead> &readings);

    // Find the highest to lowest energy usage Readings
    static SensorRead findHighestUsage(const vector<SensorRead> &readings);
    static SensorRead findLowestUsage(const vector<SensorRead> &readings);

    // Counting critical alers (severity >= threshold)
    static int countCriticalAlerts(const vector<Event> &events, int threshold);

    // Searching for a specific event by ID
    static bool eventExists(const vector<Event> &events, const string &eventID);
};

#endif
