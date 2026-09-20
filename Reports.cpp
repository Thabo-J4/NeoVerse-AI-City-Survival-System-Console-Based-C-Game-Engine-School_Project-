#include "Reports.h"
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

void ReportGenerator::logProcessedEvent(const Event &e, double responseTimeSeconds)
{
    processedEventLog.push_back(e);
    responseTimes.push_back(responseTimeSeconds);
}

// iterator loop
int ReportGenerator::getTotalEventsProcessed() const
{
    int count = 0;
    for (vector<Event>::const_iterator it = processedEventLog.begin();
         it != processedEventLog.end(); ++it)
    {
        count++;
    }
    return count;
}

string ReportGenerator::getMostCommonEmergencyType() const
{
    int counts[4] = {0, 0, 0, 0};

    for (vector<Event>::const_iterator it = processedEventLog.begin();
         it != processedEventLog.end(); ++it)
    {
        counts[static_cast<int>(it->getType())]++;
    }

    int maxIndex = static_cast<int>(max_element(counts, counts + 4) - counts);

    switch (static_cast<EventType>(maxIndex))
    {
    case EventType::TrafficAccident:
        return "Traffic Accident!!";
    case EventType::PowerFailure:
        return "Power Failure!!";
    case EventType::NetworkOverload:
        return "Network Overload!!";
    case EventType::WeatherAlert:
        return "Weather Alert!!";
    }
    return "None";
}

// accumulate
double ReportGenerator::getAverageResponseTime() const
{
    if (responseTimes.empty())
        return 0.0;
    double total = accumulate(responseTimes.begin(), responseTimes.end(), 0.0);
    return total / responseTimes.size();
}

// System load
double ReportGenerator::getSystemLoad(int maxCapacity) const
{
    if (maxCapacity <= 0)
        return 0.0;
    return (static_cast<double>(processedEventLog.size()) / maxCapacity) * 100.0;
}

System_Report ReportGenerator::generateFullReport(int maxCapacity) const
{
    System_Report report;
    report.totalEventsProcessed = getTotalEventsProcessed();
    report.mostCommonEmergencyType = getMostCommonEmergencyType();
    report.averageResponseTimeSeconds = getAverageResponseTime();
    report.systemLoadPercentage = getSystemLoad(maxCapacity);
    return report;
}

void ReportGenerator::displayReport(const System_Report &report) const
{
    cout << "<---City System Report--->" << endl;
    cout << "<---Total Events Processed---> : " << report.totalEventsProcessed << endl;
    cout << "<---Most Common Emergency---> : " << report.mostCommonEmergencyType << endl;
    cout << "<---Average Response Time---> : " << report.averageResponseTimeSeconds << " sec" << endl;
    cout << "<---System Load---> : " << report.systemLoadPercentage << "%" << endl;
    cout << "<-------Full Report------->" << endl;
}
