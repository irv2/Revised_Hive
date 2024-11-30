#pragma once
#include "CandidateType.h"

class Node
{
private:
    CandidateType candidate;
    Node* next;

public:
    Node(const CandidateType& candidateData, Node* nextNode = nullptr);

    CandidateType& getCandidate();
    const CandidateType& getCandidate() const;

    Node* getNext() const;
    void setNext(Node* nextNode);
};
