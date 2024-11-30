#pragma once
#include "PersonType.h"

const int NUM_OF_CAMPUSES = 4;

class CandidateType : public PersonType
{
public:
    CandidateType();
    CandidateType(const string& newFName, const string& newLName, int SSN);

    void updateVotesByCampus(int campusNum, int votes);
    int getTotalVotes() const;
    int getVotesByCampus(int campusNum) const;
    void printCandidateInfo() const;
    void printCandidateTotalVotes() const;
    void printCandidateCampusVotes(int campusNum) const;

    ~CandidateType();

private:
    int totalVotes;
    int campusVotes[NUM_OF_CAMPUSES];
};
