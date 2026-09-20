// AI City Survival Engine
// 1. Engineer login with lineaar + binary search
// 2. City data management (vector + list)
// 3. Event queue (FIFO) + emergency override stack (LIFO)
// 4. Polymorphic city components
// 5. STL algorithm performance tools
// 6. System Reports & analytics
// 7. File persistence and management(engineers.dat, events.dat, city_logs.dat, config.txt)

#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <limits>

#include "Engineer.h"
#include "Login_System.h"
#include "City_Data.h"
#include "City_Data_Manager.h"
#include "Event_Processor.h"
#include "City_Component.h"
#include "City_Systems.h"
#include "Performance_Tools.h"
#include "Reports.h"
#include "File_Management.h"
#include "Event_Processing.h"

// this is for the default engineers
void seedDefaultEngineers(LoginSystem &loginSystem)
{
    loginSystem.addEngineer(Engineer("ENGINEER-001", "Thabo", "Admin123", ClearanceLevel::High));
    loginSystem.addEngineer(Engineer("ENGINEER-002", "Thabiso", "number123", ClearanceLevel::Medium));
    loginSystem.addEngineer(Engineer("ENGINEER-003", "Kamohelo", "password123", ClearanceLevel::Low));
}

// This is for the Engineer Login
bool run_login_section(LoginSystem &loginSystem)
{
    cout << "\n<----AI City Survival Engine - LOGIN---->\n";
    cout << "Sample -> Username: Thabo | Password: Admin123\n";
    string username, password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    // linear search login section
    Engineer *engineer = loginSystem.loginLinear(username, password);

    if (engineer == nullptr)
    {
        cout << "Login failed due to invalid username or password!!\n";
        return false;
    }

    cout << "Login Successful, Welcome Mr, " << engineer->getUsername() << " (" << engineer->getID() << ", clearance: " << Engineer::clearanceToString(engineer->getClearance()) << ")\n";
    // binary search
    loginSystem.sortByID();
    int idx = loginSystem.binarySearchByID(engineer->getID());
    cout << "[Binary search check] Found Engineer: " << engineer->getID() << " at sorted index " << idx << " (0(log n) lookup)\n";
    return true;
}

// City data management
void run_city_data_section(CityDataManager &cityData)
{
    cout << "\n<---- City Data Management ---->\n";

    // insert sensor readings
    cityData.addReading(SensorRead("08:00", 1250000, 340.5, 0.42));
    cityData.addReading(SensorRead("12:00", 1250500, 512.7, 0.75));
    cityData.addReading(SensorRead("18:00", 1249800, 601.2, 0.88));

    if (cityData.LogCount() == 0)
    {
        cityData.addLog(CityLog("08:01", "Morning sensor sweep completed"));
        cityData.addLog(CityLog("12:05", "Midday traffic congestion detected"));
        cityData.addLog(CityLog("18:10", "Evening peak load logged"));
    }

    cout << "\n<---- Daily Sensor Readings (vector, fast indexed access)  ---->\n";
    cityData.displayReadings();

    cout << "\nRemoving oldest sensor reading........\n";
    cityData.removeOldReadings();
    cout << "Readings remaining: " << cityData.readingCount() << "\n";
}

// event queue + emergency stack
void run_event_section(EventProcessor &processor, ReportGenerator &report_gen)
{
    cout << "\n<---- Event Processing System ---->\n";

    processor.reportEvent(Event("EVENT-001", EventType::TrafficAccident, "09.15", 2));
    processor.reportEvent(Event("EVENT-002", EventType::NetworkOverload, "09:20", 3));
    processor.reportEvent(Event("EVENT-003", EventType::WeatherAlert, "09:30", 1));

    cout << "\n<---- Processing queued events in FIFO order ---->\n";
    while (processor.hasEvents())
    {
        Event e = processor.processNextEvent();
        e.display();
        report_gen.logProcessedEvent(e, 4.2); // this is just a pretend response time
    }

    // Emergency overrides arrive and are pushed LIFO
    processor.raiseEmergency(EmergencyEvent("EMERGENCY-001", EventType::PowerFailure, "10:00", 5, "Substation trip in Sector 4"));
    processor.raiseEmergency(EmergencyEvent("EMERGENCY-002", EventType::NetworkOverload, "10:02", 4, "Backup network saturated during power event"));

    cout << "\n <---- Resolving emergencies in LIFO order (most recent first) ---->\n";
    while (processor.hasEmergencies())
    {
        EmergencyEvent e = processor.resolveEmergency();
        e.display();
        report_gen.logProcessedEvent(e, 1.5);
    }
}

// Polymorphic city components
void run_city_component_section()
{
    cout << "\n<---- City components (Polymorphism) ---->\n";

    vector<unique_ptr<CityComponent>> systems;
    systems.push_back(make_unique<PowerSystem>(1, "Grid-A", 100.0));
    systems.push_back(make_unique<TransportSystem>(2, "Traffic Central", 50));
    systems.push_back(make_unique<HealthSystem>(3, "MedNet", 12));
    systems.push_back(make_unique<SecuritySystem>(4, "CityWatch", 3));

    // runtime polymorphism
    for (auto &sys : systems)
    {
        sys->activate();
        sys->processEvent("Storm warning issued");
        cout << sys->getStatus() << "\n";
    }
}

// STL algorithm performance tools
vector<Event> run_performance_section(CityDataManager &cityData)

{
    cout << "\n<---- STL Algorithms & Performance ---->\n";

    vector<SensorRead> &readings = cityData.getReadings();
    if (readings.empty())
    {
        cout << "No readings available!\n";
        return vector<Event>();
    }

    SensorRead highest = PerformanceTools::findHighestUsage(readings);
    SensorRead lowest = PerformanceTools::findLowestUsage(readings);

    cout << "Highest energy usage : " << highest.getEnergyUsage() << " MWh at " << highest.getTimestamp() << "\n";
    cout << "Lowest energy usage : " << lowest.getEnergyUsage() << " MWh at " << lowest.getTimestamp() << "\n";

    PerformanceTools::sortByEnergyUsage(readings);
    cout << "\n<---- Readings sorted by energy usage in ascending order ---->\n";
    cityData.displayReadings();

    vector<Event> sampleEvents;
    sampleEvents.push_back(Event("EVENT-010", EventType::PowerFailure, "11:00", 5));
    sampleEvents.push_back(Event("EVENT-011", EventType::TrafficAccident, "11:05", 2));
    sampleEvents.push_back(Event("EVENT-012", EventType::WeatherAlert, "11:10", 4));

    int criticalCount = PerformanceTools::countCriticalAlerts(sampleEvents, 4);
    cout << "\nCritical Alerts (severity >= 4): " << criticalCount << "\n";

    bool found = PerformanceTools::eventExists(sampleEvents, "EVENT-011");
    cout << "Event EVENT-011 exists: " << (found ? "yes" : "no") << "\n";

    return sampleEvents;
}

// Reports section
void run_reports_section(ReportGenerator &report_gen, const SystemConfig &config)
{
    cout << "\n<---- System Reports & Analytics ---->\n";
    System_Report report = report_gen.generateFullReport(config.maxEventCapacity);
    report_gen.displayReport(report);
}

int main()
{
    // load persisted state on startup
    SystemConfig config;
    File_Manager::load_Config(config, "config.txt");
    cout << "Loaded config for: " << config.city_name << "\n";

    LoginSystem loginSystem;
    bool loadedEngineers = File_Manager::load_Engineers(loginSystem.getEngineers(), "engineers.dat");
    if (!loadedEngineers || loginSystem.getEngineers().empty())
    {
        cout << "No engineers.dat found - seeding default engineer accounts.\n";
        seedDefaultEngineers(loginSystem);
        File_Manager::save_Engineers(loginSystem.getEngineers(), "engineers.dat");
        File_Manager::save_Config(config, "config.txt"); // writing defaults for next
    }

    CityDataManager cityData;
    File_Manager::load_CityLogs(cityData.getLogs(), "city_logs.dat");

    // Login
    bool loggedIn = run_login_section(loginSystem);
    if (!loggedIn)
    {
        cout << "Exiting simulation...\n";
        return 1;
    }

    // City Data Management
    run_city_data_section(cityData);

    // Event queue and emergency stack
    EventProcessor processor;
    ReportGenerator report_gen;
    run_event_section(processor, report_gen);

    // OOP city components / polymorphism
    run_city_component_section();

    // STL algorithms & performance
    vector<Event> newEvents = run_performance_section(cityData);
    // reports
    run_reports_section(report_gen, config);

    // Persist state on shutdown
    cout << "\n<---- Saving System State ---->\n";
    File_Manager::save_Engineers(loginSystem.getEngineers(), "engineers.dat");
    File_Manager::save_CityLogs(cityData.getLogs(), "city_logs.dat");
    File_Manager::export_Logs_To_CSV(cityData.getLogs(), "city_logs_export.csv");
    File_Manager::save_Events(newEvents, "events.dat");

    cout << "State saved to files: engineers.dat, city_logs.dat, city_logs_export.csv\n";

    cout << "\nSimulation is completed.\n";
    return 0;
}
