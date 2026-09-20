#include "Login_System.h"
#include <algorithm> //sort()

void LoginSystem::addEngineer(const Engineer &e)
{
    engineers.push_back(e);
}

vector<Engineer> &LoginSystem::getEngineers()
{
    return engineers;
}

// Linear
Engineer *LoginSystem::loginLinear(const string &username, const string &password)
{
    int index = sequentialSearchByUsername(username);
    if (index != -1 && engineers[index].verifyPass(password))
    {
        return &engineers[index];
    }
    return nullptr;
}

// Sequential Search
int LoginSystem::sequentialSearchByUsername(const string &username) const
{
    for (int i = 0; i < static_cast<int>(engineers.size()); i++)
    {
        if (engineers[i].getUsername() == username)
        {
            return i; // if found this will return its position
        }
    }
    return -1; // if not found this will return
}

// Binary Search
int LoginSystem::binarySearchByID(const string &id) const
{
    int low = 0;
    int high = static_cast<int>(engineers.size()) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (engineers[mid].getID() == id)
        {
            return mid; // if found this returns
        }
        else if (engineers[mid].getID() < id)
        {
            low = mid + 1; // discard the left half
        }
        else
        {
            high = mid - 1; // discard the right half
        }
    }
    return -1; // if not found
}

// Precondition for binary search
void LoginSystem::sortByID()
{
    sort(engineers.begin(), engineers.end(),
         [](const Engineer &a, const Engineer &b)
         {
             return a.getID() < b.getID();
         });
}

Engineer *LoginSystem::loginBinary(const string &id, const string &password)
{
    int index = binarySearchByID(id);
    if (index != -1 && engineers[index].verifyPass(password))
    {
        return &engineers[index];
    }
    return nullptr;
}