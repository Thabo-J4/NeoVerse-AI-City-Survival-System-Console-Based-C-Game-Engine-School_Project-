#include <File_Management.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// splitting a delimited line into fields
static vector<string> split_Line(const string &line, char delim)
{
    vector<string> fields;
    stringstream ss(line);
    string field;
    while (getline(ss, field, delim))
    {
        fields.push_back(field);
    }
    return fields;
}

// This is for the engineers data
bool File_Manager::save_Engineers(const vector<Engineer> &engineers, const string &filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Error: could not open " << filename << " for writing." << endl;
        return false;
    }
    for (const Engineer &e : engineers)
    {
        outFile << e.getID() << "|" << e.getUsername() << "|" << e.getEncryptedPassword() << "|" << Engineer::clearanceToString(e.getClearance()) << "\n";
    }
    outFile.close();
    return true;
}

bool File_Manager::load_Engineers(vector<Engineer> &engineers, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Notice: " << filename << " not found, starting with no saved enginers." << endl;
        return false;
    }
    engineers.clear();
    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;
        vector<string> fields = split_Line(line, '|');
        if (fields.size() != 4)
            continue; // this will skip the malformed rows

        ClearanceLevel level = Engineer::stringToClearance(fields[3]);
        engineers.push_back(Engineer::fromRecord(fields[0], fields[1], fields[2], level));
    }
    inFile.close();
    return true;
}

// This is for the events.dat
bool File_Manager::save_Events(const vector<Event> &events, const string &filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Error: could not open " << filename << " for writing." << endl;
        return false;
    }
    for (const Event &e : events)
    {
        outFile << e.getID() << "|" << e.getTypeString() << "|" << e.getTimestamp() << "|" << e.getSeverity() << "\n";
    }
    outFile.close();
    return true;
}

bool File_Manager::load_Events(vector<Event> &events, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Notice: " << filename << " not found, starting with no saved events." << endl;
        return false;
    }
    events.clear();
    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;
        vector<string> fields = split_Line(line, '|');
        if (fields.size() != 4)
            continue;

        EventType type = Event::stringToType(fields[1]);
        int severity = stoi(fields[3]);
        events.push_back(Event(fields[0], type, fields[2], severity));
    }
    inFile.close();
    return true;
}

// this is for city_logs.dat
bool File_Manager::save_CityLogs(const list<CityLog> &logs, const string &filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Error: could not open " << filename << " for writing." << endl;
        return false;
    }
    for (const CityLog &log : logs)
    {
        outFile << log.getTimestamp() << "|" << log.getMessage() << "\n";
    }
    outFile.close();
    return true;
}

bool File_Manager::load_CityLogs(list<CityLog> &logs, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Notice: " << filename << " not found, starting with no saved logs." << endl;
        return false;
    }
    logs.clear();
    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;
        size_t pos = line.find('|');
        if (pos == string::npos)
            continue;
        string timestamp = line.substr(0, pos);
        string message = line.substr(pos + 1);
        logs.push_back(CityLog(timestamp, message));
    }
    inFile.close();
    return true;
}

// this is for the config.txt
bool File_Manager::save_Config(const SystemConfig &config, const string &filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Error: could not open " << filename << " for writing." << endl;
        return false;
    }
    outFile << "City_Name=" << config.city_name << "\n";
    outFile << "Max_Event_Capacity=" << config.maxEventCapacity << "\n";
    outFile << "Critical_Severity_Threshold=" << config.criticalSeverityThreshold << "\n";
    outFile.close();
    return true;
}

bool File_Manager::load_Config(SystemConfig &config, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Notice: " << filename << " not found, using default configuration." << endl;
        return false;
    }
    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue;
        size_t eq = line.find('=');
        if (eq == string::npos)
            continue;

        string key = line.substr(0, eq);
        string value = line.substr(eq + 1);

        if (key == "City_Name")
            config.city_name = value;
        else if (key == "Max_Event_Capacity")
            config.maxEventCapacity == stoi(value);
        else if (key == "Critical_Severity_Threshold")
            config.criticalSeverityThreshold = stoi(value);
    }
    inFile.close();
    return true;
}

// this is for the csv export
bool File_Manager::export_Logs_To_CSV(const list<CityLog> &logs, const string &filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Error: could not open " << filename << " for writing." << endl;
        return false;
    }
    outFile << "Timestamp,Message\n";
    for (const CityLog &log : logs)
    {
        // this could be used to wrap messages in quotes in case it contains a comma
        outFile << log.getTimestamp() << ",\"" << log.getMessage() << "\"\n";
    }
    outFile.close();
    return true;
}