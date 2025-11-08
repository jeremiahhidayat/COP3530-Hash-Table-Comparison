//
// Created by jerem on 11/5/2025.
//

#include "../include/CLI.h"

#include "hashTableSC.h"
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
    cout << "    4. Go Back to Main Menu " << endl;
    cout << "\n Enter Choice: ";
}
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <limits>

template <typename T>
void interactiveSession(T& table) {
    bool allFlag = false;
    std::string key;
    int choice = 0;

    // Regex to match integers (optional negative sign)
    std::regex intRegex(R"(^-?\d+$)");

    do {
        showSubMenu();

        // --- Read menu choice ---
        std::string choiceStr;
        std::getline(std::cin, choiceStr);

        // Remove carriage return (\r) if present (Windows)
        choiceStr.erase(std::remove(choiceStr.begin(), choiceStr.end(), '\r'), choiceStr.end());

        if (!std::regex_match(choiceStr, intRegex)) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        choice = std::stoi(choiceStr);

        switch (choice) {
            // --- Load dataset ---
            case 1: {
                int amount = 0;
                allFlag = false;

                std::cout << "Enter number of IMDb entries (-1 for all): ";

                while (true) {
                    std::string amountStr;
                    std::getline(std::cin, amountStr);

                    // Remove \r if Windows
                    amountStr.erase(std::remove(amountStr.begin(), amountStr.end(), '\r'), amountStr.end());

                    if (std::regex_match(amountStr, intRegex)) {
                        amount = std::stoi(amountStr);
                        break;
                    } else {
                        std::cout << "Invalid number. Try again: ";
                    }
                }

                allFlag = (amount == -1);

                // parse movies and insert
                std::vector<Movie> movies = movieParser("data/title.basics.tsv", amount);
                for (const auto& movie : movies) {
                    table.insert(movie.title, movie.genres);
                    if (!allFlag)
                        std::cout << "Inserted: " << movie.title << "\n";
                }

                std::cout << "Insertion complete.\n";
                break;
            }

            // --- Search for a movie ---
            case 2: {
                std::cout << "Enter key: ";
                std::getline(std::cin, key);
                key.erase(std::remove(key.begin(), key.end(), '\r'), key.end()); // remove \r
                std::cout << "Found: " << table.search(key) << "\n";
                break;
            }

            // --- Print table ---
            case 4: {
                if (allFlag) {
                    std::cout << "Are you sure you want to print every value of the IMDb database?\n";
                }

                // table.print();
                break;
            }

            // --- Return to main menu ---
            case 5: {
                std::cout << "Returning to main menu.\n";
                break;
            }

            default:
                std::cout << "Invalid option. Please enter a valid choice.\n";
        }

    } while (choice != 5);
}


void runCLI(TableType type) {
    if (type == TableType::SEPARATE_CHAIN) {
        hashTableSC table;
        cout << "\nUsing Separate Chaining Hash Table\n";
        interactiveSession(table);
    } else {
        hashOpenAddress table;
        cout << "\nUsing Open Addressing Hash Table\n";
        interactiveSession(table);
    }
}


void compareImplementations() {
}
