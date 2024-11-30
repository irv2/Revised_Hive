#include <iostream>
#include <string>
#include "PersonType.h"
using namespace std;

PersonType::PersonType()
{
    fName = "";
    lName = "";
    SSN = 0;
}

PersonType::PersonType(const string& newFName, const string& newLName, int newSSN)
{
    fName = newFName;
    lName = newLName;
    SSN = newSSN;
}

string PersonType::getFirstName() const
{
    return fName;
}

string PersonType::getLastName() const
{
    return lName;
}

int PersonType::getSSN() const
{
    return SSN;
}

void PersonType::setPersonInfo(const string& newFName, const string& newLName, int newSSN)
{
    fName = newFName;
    lName = newLName;
    SSN = newSSN;
}

void PersonType::printName() const
{
    cout << lName << ", " << fName;
}

void PersonType::printPersonInfo() const
{
    printSSN();
    cout << " " << lName << ", " << fName;
}

void PersonType::printSSN() const
{
    string strSSN = to_string(SSN);
    cout << strSSN.substr(0, 3) << "-" << strSSN.substr(3, 2) << "-" << strSSN.substr(5);
}

PersonType::~PersonType()
{
    // Empty destructor
}
