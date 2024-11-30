#include "CandidateList.h"
#include <iostream>
using namespace std;

// Default Constructor
CandidateList::CandidateList()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

// Destructor
CandidateList::~CandidateList()
{
    clearList();
}

// Clear the list
void CandidateList::clearList()
{
    Node* current = first;
    while (current != nullptr)
    {
        Node* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
    first = last = nullptr;
    count = 0;
}

// Add a candidate to the list
void CandidateList::addCandidate(const CandidateType& candidate)
{
    Node* newNode = new Node(candidate);

    if (first == nullptr) // List is empty
    {
        first = last = newNode;
    }
    else
    {
        last->setNext(newNode);
        last = newNode;
    }

    ++count;
}

// Get the winner's SSN
int CandidateList::getWinner(string& winnerName) const
{
    if (first == nullptr) // List is empty
    {
        cout << "=> List is empty" << endl;
        winnerName = "N/A";
        return 0;
    }

    Node* current = first;
    Node* winnerNode = first;
    int maxVotes = first->getCandidate().getTotalVotes();

    while (current != nullptr)
    {
        if (current->getCandidate().getTotalVotes() > maxVotes)
        {
            maxVotes = current->getCandidate().getTotalVotes();
            winnerNode = current;
        }
        current = current->getNext();
    }

    // Set the winner's name
    winnerName = winnerNode->getCandidate().getFirstName() + " " + winnerNode->getCandidate().getLastName();

    // Return the winner's SSN
    return winnerNode->getCandidate().getSSN();
}

// Search for a candidate by SSN
bool CandidateList::searchCandidate(int SSN) const
{
    Node* current = first;

    while (current != nullptr)
    {
        if (current->getCandidate().getSSN() == SSN)
            return true;

        current = current->getNext();
    }

    return false;
}


void CandidateList::printAllCandidates()
{
    if (first == nullptr)
    {
        cout << "=> No candidates in the list." << endl;
        return;
    }

    Node* current = first;
    while (current != nullptr)
    {
        current->getCandidate().printCandidateInfo();
        current = current->getNext();
    }
}
void CandidateList::printCandidateTotalVotes(int SSN) const
{
    if (first == nullptr)
    {
        cout << "=> No candidates in the list." << endl;
        return;
    }

    Node* current = first;
    while (current != nullptr)
    {
        if (current->getCandidate().getSSN() == SSN)
        {
            current->getCandidate().printCandidateTotalVotes();
            return;
        }
        current = current->getNext();
    }

    cout << "=> Candidate with SSN " << SSN << " not found." << endl;
}

Node* CandidateList::mergeSortRec(Node* head, bool ascending)
{
    if (head == nullptr || head->getNext() == nullptr)
        return head; // Base case

    // Split the list
    Node* mid = getMiddle(head);
    Node* halfList = mid->getNext();
    mid->setNext(nullptr);

    // Recursively sort each half
    Node* left = mergeSortRec(head, ascending);
    Node* right = mergeSortRec(halfList, ascending);

    // Merge sorted halves
    return merge(left, right, ascending);
}

Node* CandidateList::getMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head->getNext();

    while (fast != nullptr && fast->getNext() != nullptr)
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }

    return slow;
}

Node* CandidateList::merge(Node* left, Node* right, bool ascending)
{
    if (!left) return right;
    if (!right) return left;

    Node* result = nullptr;

    if (ascending)
    {
        if (left->getCandidate().getTotalVotes() <= right->getCandidate().getTotalVotes())
        {
            result = left;
            result->setNext(merge(left->getNext(), right, ascending));
        }
        else
        {
            result = right;
            result->setNext(merge(left, right->getNext(), ascending));
        }
    }
    else
    {
        if (left->getCandidate().getTotalVotes() >= right->getCandidate().getTotalVotes())
        {
            result = left;
            result->setNext(merge(left->getNext(), right, ascending));
        }
        else
        {
            result = right;
            result->setNext(merge(left, right->getNext(), ascending));
        }
    }

    return result;
}



void CandidateList::printFinalResults()
{
    if (first == nullptr)
    {
        cout << "=> No candidates in the list." << endl;
        return;
    }

    // Sort the list in descending order
    first = mergeSortRec(first, false);

    // Print the sorted list
    Node* current = first;
    cout << "\nFinal Results (Descending Order):" << endl;
    cout << "----------------------------------" << endl;
    while (current != nullptr)
    {
        current->getCandidate().printCandidateTotalVotes();
        current = current->getNext();
    }
}


void CandidateList::printCandidateCampusVotes(int SSN) const
{
    if (first == nullptr)
    {
        cout << "=> No candidates in the list." << endl;
        return;
    }

    Node* current = first;
    while (current != nullptr)
    {
        if (current->getCandidate().getSSN() == SSN)
        {
            for (int i = 1; i <= NUM_OF_CAMPUSES; ++i)
            {
                current->getCandidate().printCandidateCampusVotes(i);
            }
            return;
        }
        current = current->getNext();
    }

    cout << "=> Candidate with SSN " << SSN << " not found." << endl;
}
