How to run the simulation:
* Have a C++ compiler that supports at least C++14(e.g. g++/MinGW)
*All project files must be in the same folder
The files are:
main.cpp 
Engineer.h/Engineer.cpp
Login_System.h/LoginSystem.cpp
City_Data_Manager.h/City_Data_Manager.cpp 
Event_Processing.h/Event_Processing.cpp 
Event_Processor.h/Event_Processor.cpp
City_Component.h/City_Component.cpp 
City_Systems.h/City_Systems.cpp 
Performance_Tools.h/Performance_Tools.cpp 
Reports.h/Reports.cpp 
File_Management.h/File_Management.cpp 

If you have those files go ahead and compile:
Open a terminal in the project folder and run:
g++ -std=c++14 *.cpp -0 NeoVerse.exe 

This will compile every cpp file in the folder together into one executable since main cpp 
calls functions defined across all the other classes.

Next run the application on the terminal:
by typing: .\NeoVerse.exe 
on Mac/Linux: ./NeoVerse 

On the first run the program will report that engineers.dat, events.dat, city_logs.dat, and config.txt 
were not found and will automatically seed default engineer accounts and default configuration values. It will keep on loading the previously saved state from those
files when it is subsequently ran. 

The sample login credentials
Username==============Password============Clearance
Thabo                 Admin123            High 
Thabiso               number123           Medium 
Kamohelo              password123         Low 

These are seeded automatically when you first run the program 

Explanation of Containers used 
Container ========= Used For ========= Why
vector<Engineer>    Storing all        Contiguous storage gives 0(1) random access, needed for binary search by ID once sorted
                    registered
                    engineers
                    (LoginSystem)
vector<SensorRead>  Daily sensor       Readings are naturally indexed (today's data, accessed by position)- vector gives 0(1) indexed access
                    Readings
                    (CityDataManager)
list<CityLog>       Historical city    Logs grow unbounded over the city's lifetime and are only ever appended/pruned, never randomly indexed - a linked list gives O(1) insertion/removal at any known position with no shifting or resizing cost
                    logs
                    (CityDataManager)
queue<Event>        Incoming city      Events must be handled in the order they arrive (FIFO) - a queue restricts access to front/back, giving O(1) enqueue/dequeue   
                    events 
                    (EventProcessor)
stack               Emergency          The most recent emergency must be resolved first (LIFO) - a stack gives O(1) push/pop/top
<EmergencyEvent>    overrides
                    (EventProcessor)
vector<Event>       Temporary          Needed wherever STL <algorithm> functions (sort, find_if, count_if, min_element, max_element) operate over a full collection at once      
                    snapshots for
                    filtering/sorting
                    /reporting

Big-O Summary
Operation =================================== Complexity =================== Notes 
Sequential search (login by username)         0(n)                           Checks each engineer in turn; works on unsorted data
Binary search (login by ID)                   0(log n)                       Requires the engineer vector to be sorted by ID first (sortByID(), O(n log n) one-time cost)
vector insert at end                          0(1) amortised                 Occasional resize doubles capacity, so average cost per insert stays constant
vector remove from front                      0(n)                           All remaining elements shift left by one
list insert/remove at known position          0(1)                           No shifting required, unlike a vector
queue push/pop                                0(1)                           Restricted to front/back access only
stack push/pop/top                            0(1)                           Restricted to top access only
sort                                          0(n log n)                     Introsort-hybrid of quicksort/heapsort/insertion sort
min_element/max_element                       0(n)                           Single linear scan; cheaper than a full sort when only one extreme value is needed
count_if/find_if                              0(n)                           Every element must be checked once against the predicate, since data is not pre-sorted by the searched field

File ====================== Purpose
engineers.dat               Saved engineer accounts(ID, username, encrypted password, clearance)
events.dat                  Saved event history 
city_logs.dat               Saved historical city log entries
config.txt                  System configuration(city name, max event capacity, critical severity threshold)
city_logs_export.csv        CSV export of city logs, generated on eery run for reporting/analysis in Excel/Sheets

all the files in the folder are plain, human-readable text (pipe-delimited for .dat files, KEY = VALUE for config.txt), so they can be opened directly to inspect saved state between runs.