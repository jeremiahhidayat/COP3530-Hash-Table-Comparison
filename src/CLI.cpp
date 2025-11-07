//
// Created by jerem on 11/5/2025.
//

#include "../include/CLI.h"

#include "parser.h"
using namespace std;

void showMainMenu() {
    cout << "\n --- IMDb Movie Hash Table Benchmark ---" << endl;
    // cout << "    0. Show Help" << endl;
    cout << "    1. Use Separate Chaining Hash Table" << endl;
    cout << "    2. Use Open Addressing Hash Table" << endl;
    cout << "    3. Compare Performance"            <<endl;
    cout << "    4. Exit" << endl;
}

void showSubMenu() {
    cout << "\n --- Hash Table Operations --- " << endl;
    cout << "    1. Load IMDb Dataset" << endl;
    cout << "    2. Insert All Records into Hash Tables" << endl;
    cout << "    3. Search for a Movie Title" << endl;
    cout << "    4. Delete a Record" << endl;
    cout << "    5. Go Back to Main Menu " << endl;
    cout << "\n Enter Choice: " << endl;
}

template <typename T>
void interactiveSession() {
    int choice ;
    string key;
    Movie output;
    vector<Movie> movies;

    do {
        showSubMenu();
        cin >> choice ;
        switch (choice) {
            case 1:
                cout << "Enter number of IMBb entries desired" << endl;
                cout << "Put -1 for all values to be entered" << endl;



            case 2:
            case 3:
            case 4:
            default:
        }
    }while (choice != 5);
}

void runCLI(TableType type) {
    if (type == TableType::CHAINING) {
        hashSeparateAddress<string, int> table;
        cout << "\nUsing Separate Chaining Hash Table\n";
        interactiveSession(table);
    } else {
        hashOpenAddress<string, int> table;
        cout << "\nUsing Open Addressing Hash Table\n";
        interactiveSession(table);
    }
}


void compareImplementations() {
}
