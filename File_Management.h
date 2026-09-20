#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <list>
#include <map>
#include <Engineer.h>
#include "Event_Processing.h"
#include <City_Data.h>

struct SystemConfig
{
    int maxEventCapacity = 100;
    int criticalSeverityThreshold = 4;
    string city_name = "NeoVerse City";
};

class File_Manager
{
public:
    // This is for the data file for the Engineers(engineers.dat)
    static bool save_Engineers(const vector<Engineer> &engineers, const string &filename);
    static bool load_Engineers(vector<Engineer> &engineers, const string &filename);

    // This is for the data file for the events data(events.dat)
    static bool save_Events(const vector<Event> &events, const string &filename);
    static bool load_Events(vector<Event> &events, const string &filename);

    // This is for the data file City Logs(city_logs.dat)
    static bool save_CityLogs(const list<CityLog> &logs, const string &filename);
    static bool load_CityLogs(list<CityLog> &logs, const string &filename);

    // This is for the data file Config(config.txt)
    static bool save_Config(const SystemConfig &config, const string &filename);
    static bool load_Config(SystemConfig &config, const string &filename);

    // This is the part where we export the logs to the CSV file
    static bool export_Logs_To_CSV(const list<CityLog> &logs, const string &filename);
};

#endif