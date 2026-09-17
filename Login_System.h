#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include <vector>
#include <string>
#include "Engineer.h"

class LoginSystem
{
private:
    vector<Engineer> engineers;

public:
    void addEngineer(const Engineer &e);
    vector<Engineer> &getEngineers();

    int sequentialSearchByUsername(const string &username) const;

    int binarySearchByID(const string &id) const;

    void sortByID();

    // Wrappers combining search + password check
    Engineer *loginLinear(const string &username, const string &password);
    Engineer *loginBinary(const string &id, const string &password);
};

#endif