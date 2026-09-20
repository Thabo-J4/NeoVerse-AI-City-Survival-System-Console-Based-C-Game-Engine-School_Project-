#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H
#include <iostream>
#include <vector>
#include <string>
#include "Event_Processor.h"
using namespace std;

struct System_Report
{
    int totalEventsProcessed;
    string mostCommonEmergencyType;
    double averageResponseTimeSeconds;
    double systemLoadPercentage;
};

class ReportGenerator
{
private:
    vector<Event> processedEventLog; // this is the history of every event handled
    vector<double> responseTimes;    // this is the seconds taken to resolve each event

public:
    void logProcessedEvent(const Event &e, double responseTimeSeconds);

    int getTotalEventsProcessed() const;
    string getMostCommonEmergencyType() const;
    double getAverageResponseTime() const;
    double getSystemLoad(int maxCapacity) const;

    System_Report generateFullReport(int maxCapacity) const;
    void displayReport(const System_Report &report) const;
};

#endif