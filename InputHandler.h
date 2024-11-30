#pragma once
#include <fstream>
#include <string>
#include "CandidateList.h"

void createCandidateList(ifstream& infile, CandidateList& candidateList)
{
    int ssn = 0;
    int allVotes[NUM_OF_CAMPUSES];
    string fName, lName;
    infile >> ssn;
    while (ssn != -999)
    {
        CandidateType newCandidate;
        infile >> fName >> lName;
        newCandidate.setPersonInfo(fName, lName, ssn);
        for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
        {
            infile >> allVotes[i];
            newCandidate.updateVotesByCampus(i + 1, allVotes[i]);
        }
        candidateList.addCandidate(newCandidate);
        infile >> ssn;
    }
}

void readCandidateData(CandidateList& candidateList)
{
    ifstream infile("Votes.txt");
    if (!infile)
    {
        cerr << "Input file does not exist." << endl;
        exit(1);
    }
    createCandidateList(infile, candidateList);
    infile.close();
}
