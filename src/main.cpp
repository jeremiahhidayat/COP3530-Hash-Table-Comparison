//
// Created by jerem on 11/2/2025.
//
#include <iostream>
#include "movie.h"
#include <ostream>
#include <limits>
#include <sstream>
#include "CLI.h"
#include "parser.h"
#include "hashOpenAddress.h"

using namespace std;

//void testParser() {
//    vector<Movie> movies = movieParser("data/title.basics.tsv");
//    cout << "Size of movie vector: " << endl;
//    cout << movies.size() << endl;
//}

// void menu() {
//     cout << "--- IMDb Movie Lookup Benchmark ---" << endl;
//     cout << "    1. Load IMDb Dataset" << endl;
//     cout << "    2. Insert All Records into Hash Tables" << endl;
//     cout << "    3. Search for a Random Movie Title" << endl;
//     cout << "    4. Delete a Record" << endl;
//     cout << "    5. Compare Performance (Chaining vs Open Addressing)" << endl;
//     cout << "    6. Exit" << endl;
// }

// int main(int argc, char *argv[]) {
//     //testParser();
//     bool running = true;
//     int choice = 0;
//
//     menu();
//     cout << endl;
//     cout << "Enter your choice:" << endl;
//     cin >> choice;
//
//     while(running) {
//         if (choice == 1) {
//             cout << "Loading IMDb Dataset..." << endl << endl;
//         } else if (choice == 2) {
//             cout << "Inserting Records..." << endl << endl;
//         } else if (choice == 3) {
//             cout << "Searching for a Random Movie Title..." << endl << endl;
//         } else if (choice == 4) {
//             cout << "Deleting a Record..." << endl << endl;
//         } else if (choice == 5) {
//             cout << "Comparing Performance..." << endl << endl;
//         } else if (choice == 6) {
//             cout << "Exiting..." << endl;
//             running = false;
//         }
//
//         if (!running) break;
//
//         cout << "Enter next choice or press Enter to reprint menu: " << endl;
//
//         string nextLine;
//         getline(cin, nextLine);
//         if (nextLine.empty()) {
//             cout << endl;
//             menu();
//             cout << endl << "Enter your choice:" << endl;
//             cin >> choice;
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else {
//             stringstream ss(nextLine);
//             ss >> choice;
//         }
//     }
//     return 0;
// }

int main() {
    int choice;

    do {
        showMainMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                runCLI(TableType::SEPARATE_CHAIN);
                break;
            case 2:
                runCLI(TableType::OPEN_ADDRESS);
                break;
            case 3:
                compareImplementations();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}