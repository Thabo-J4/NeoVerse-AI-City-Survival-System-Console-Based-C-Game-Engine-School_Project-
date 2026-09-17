#include <iostream>
using namespace std;
#include <string>
#ifndef ENGINEER_H
#define ENGINEER_H
#include <string>

enum class ClearanceLevel
{
    Low,
    Medium,
    High
};

class Engineer
{
private:
    string engineerID; // EngineerID (ENG001, ENG002)
    string username;
    string encryptedPassword; // Encrypted password
    ClearanceLevel clearance;

public:
    Engineer() = default;
    Engineer(const string &id, const string &uname,
             const string &plainPassword, ClearanceLevel level);

    // GET
    string getID() const;
    string getUsername() const;
    ClearanceLevel getClearance() const;
    string getEncryptedPassword() const;

    // Verifying a login attempt
    bool verifyPass(const string &plainPassword) const;

    // Utility
    static string encrypt(const string &plainText);
    static string clearanceToString(ClearanceLevel level);
    static ClearanceLevel stringToClearance(const string &str);
};

#endif