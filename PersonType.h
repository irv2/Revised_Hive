#pragma once
#include <string>
using namespace std;

class PersonType
{
public:
    PersonType();
    PersonType(const string& newFName, const string& newLName, int SSN);

    string getFirstName() const;
    string getLastName() const;
    int getSSN() const;

    void setPersonInfo(const string& newFName, const string& newLName, int newSSN);
    void printName() const;
    void printPersonInfo() const;
    void printSSN() const;

    ~PersonType();

private:
    string fName;
    string lName;
    int SSN;
};
