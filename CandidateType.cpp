#include <iostream>
#include "CandidateType.h"
using namespace std;

CandidateType::CandidateType()
{
    totalVotes = 0;
    for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
    {
        campusVotes[i] = 0;
    }
}

CandidateType::CandidateType(const string& newFName, const string& newLName, int SSN)
    : PersonType(newFName, newLName, SSN)
{
    totalVotes = 0;
    for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
    {
        campusVotes[i] = 0;
    }
}

void CandidateType::updateVotesByCampus(int campusNum, int votes)
{
    if (campusNum >= 1 && campusNum <= NUM_OF_CAMPUSES)
    {
        campusVotes[campusNum - 1] = votes;
        totalVotes += votes;
    }
}

int CandidateType::getTotalVotes() const
{
    return totalVotes;
}

int CandidateType::getVotesByCampus(int campusNum) const
{
    if (campusNum >= 1 && campusNum <= NUM_OF_CAMPUSES)
    {
        return campusVotes[campusNum - 1];
    }
    return 0;
}

void CandidateType::printCandidateInfo() const
{
    printSSN();
    cout << " - ";
    printName();
    cout << endl;
}

void CandidateType::printCandidateTotalVotes() const
{
    printName();
    cout << "\n  Total Votes (all campuses): " << totalVotes << endl;
}

void CandidateType::printCandidateCampusVotes(int campusNum) const
{
    printName();
    cout << "\n  Campus " << campusNum << " total votes: " << getVotesByCampus(campusNum) << endl;
}

CandidateType::~CandidateType()
{
    // Empty destructor
}
