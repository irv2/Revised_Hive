#include <iostream>
#include "CandidateList.h"
#include "InputHandler.h"

using namespace std;

void displayMenu();
void processChoice(CandidateList& candidateList);

int main()
{
    CandidateList candidateList;

    // Fill the list with candidate data
    readCandidateData(candidateList);

    // Menu and process
    displayMenu();
    processChoice(candidateList);

    cout << "\nProgram exiting..." << endl;
    return 0;
}

void displayMenu()
{
    cout << "\n*** MAIN MENU ***\n";
    cout << "1: Print all candidates\n";
    cout << "2: Print a candidate's campus votes\n";
    cout << "3: Print a candidate's total votes\n";
    cout << "4: Print winner\n";
    cout << "5: Print final results\n";
    cout << "6: Exit\n";
}

void processChoice(CandidateList& candidateList)
{
    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;

    while (choice != 6)
    {
        int ssn;
        switch (choice)
        {
        case 1:
            candidateList.printAllCandidates();
            break;
        case 2:
            cout << "Enter candidate's SSN: ";
            cin >> ssn;
            candidateList.printCandidateCampusVotes(ssn);
            break;
        case 3:
            cout << "Enter candidate's SSN: ";
            cin >> ssn;
            candidateList.printCandidateTotalVotes(ssn);
            break;
        case 4:
        {
            string winnerName;
            int winnerSSN = candidateList.getWinner(winnerName);
            if (winnerSSN != 0)
            {
                cout << "Winner: " << winnerName << endl;
                cout << "SSN: " << winnerSSN << endl;
            }
            break;
        }
        case 5:
            candidateList.printFinalResults();
            break;
        default:
            cout << "Invalid choice.\n";
        }

        cout << "\nEnter your choice: ";
        cin >> choice;
    }
    cout << "Exiting program.\n";
}
