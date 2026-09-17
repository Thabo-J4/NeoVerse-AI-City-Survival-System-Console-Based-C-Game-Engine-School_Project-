#include "Engineer_h.cpp"
using namespace std;

Engineer::Engineer(const string &id, const string &uname, const string &plainPassword, ClearanceLevel level)
    : engineerID(id), username(uname), clearance(level)
{
    encryptedPassword = encrypt(plainPassword);
}

string Engineer::getID() const { return engineerID; }
string Engineer::getUsername() const { return username; }
ClearanceLevel Engineer::getClearance() const { return clearance; }
string Engineer::getEncryptedPassword() const { return encryptedPassword; }

bool Engineer::verifyPass(const string &plainPassword) const
{
    return encrypt(plainPassword) == encryptedPassword;
}

// Encryption
string Engineer::encrypt(const string &plainText)
{
    string result = plainText;
    for (char &c : result)
    {
        c = static_cast<char>(c + 3); // Caesar-style shift
    }
    return result;
}

string Engineer::clearanceToString(ClearanceLevel level)
{
    switch (level)
    {
    case ClearanceLevel::Low:
        return "Low";
    case ClearanceLevel::Medium:
        return "Medium";
    case ClearanceLevel::High:
        return "High";
    }
    return "Unknown";
}

ClearanceLevel Engineer::stringToClearance(const string &str)
{
    if (str == "Low")
        return ClearanceLevel::Low;
    if (str == "Medium")
        return ClearanceLevel::Medium;
    return ClearanceLevel::High;
}