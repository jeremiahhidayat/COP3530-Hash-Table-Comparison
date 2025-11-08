//
// Created by jerem on 11/5/2025.
//

#include "../include/CLI.h"

#include "../include/hashTableSC.h"
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
    cout << "    1. Load IMDb Dataset and Insert into Hash Table" << endl;
    cout << "    2. Search for a Movie Title" << endl;
    cout << "    3. Delete a Record" << endl;
    cout << "    4. Print Table" << endl;
    cout << "    5. Go Back to Main Menu " << endl;
    cout << "\n Enter Choice: " << endl;
}

template <typename T>
void interactiveSession(T& table) {
    int choice ;
    int amount;
    bool allFlag = false;
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

                cin >> amount;
                if (amount == -1) allFlag = true;
                else allFlag = false;

                movies = movieParser("data/title.basics.tsv", amount);
                for (auto movie : movies) {
                    table.insert(movie.title,movie);
                    cout << movie.title << endl;
                }

                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;

                // cout << "Found: " << table.search(key) << "\n";
                break;
            case 4:
                if (allFlag) {
                    cout<< "Are you sure you want to print every value of the IMDb database?" << endl;
                }

                // table.print();
            case 5:
                cout<< "returning to main menu" << endl;
                break;
            default:
                cout << "Invalid option.\n";
        }
    }while (choice != 5);
}

void runCLI(TableType type) {
    if (type == TableType::SEPARATE_CHAIN) {
        hashTableSC<string, string> table;
        cout << "\nUsing Separate Chaining Hash Table\n";
        interactiveSession(table);
    } else {
        hashOpenAddress<string, string> table;
        cout << "\nUsing Open Addressing Hash Table\n";
        interactiveSession(table);
    }
}


void compareImplementations() {
}
