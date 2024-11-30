#include "Node.h"

// Constructor
Node::Node(const CandidateType& candidateData, Node* nextNode)
    : candidate(candidateData), next(nextNode) {}

// Get candidate
CandidateType& Node::getCandidate()
{
    return candidate;
}

const CandidateType& Node::getCandidate() const
{
    return candidate;
}

// Get next node
Node* Node::getNext() const
{
    return next;
}

// Set next node
void Node::setNext(Node* nextNode)
{
    next = nextNode;
}
