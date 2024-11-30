#pragma once
#include "Node.h"

class CandidateList
{
private:
    Node* first;
    Node* last;
    int count;
    Node* mergeSortRec(Node* head, bool ascending);
    Node* getMiddle(Node* head);
    Node* merge(Node* left, Node* right, bool ascending);

public:
    CandidateList();
    ~CandidateList();

    void addCandidate(const CandidateType& candidate);
    int getWinner(string& winnerName) const;
    bool searchCandidate(int SSN) const;
    void printAllCandidates();
    void printCandidateTotalVotes(int SSN) const;
    void printCandidateCampusVotes(int SSN) const;
    void printFinalResults();

private:
    void clearList();
};
