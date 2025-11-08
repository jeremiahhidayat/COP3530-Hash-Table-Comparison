//
// Created by jerem on 11/2/2025.
//
#include <iostream>
#include "movie.h"
#include <ostream>
#include <limits>
#include <sstream>
#include <bits/fs_fwd.h>
#include <bits/fs_path.h>

#include <string>
#include <regex>
#include <algorithm>

#include "CLI.h"
#include "parser.h"
#include "hashOpenAddress.h"
#include "hashTableSC.h"

using namespace std;

void testParser() {
    std::cout << "Current working directory: "
              << std::filesystem::current_path() << std::endl;
    vector<Movie> movies = movieParser("data/title.basics.tsv",10);
    cout << "Size of movie vector: " << endl;
    cout << movies.size() << endl;
}


int main() {
    int choice = 0;
    std::regex intRegex(R"(^\d+$)"); // only positive integers for menu

    do {
        showMainMenu();
        std::cout << "\nEnter choice: ";

        std::string choiceStr;
        std::getline(std::cin, choiceStr);

        // Remove carriage return if Windows
        choiceStr.erase(std::remove(choiceStr.begin(), choiceStr.end(), '\r'), choiceStr.end());

        // Validate input with regex
        if (!std::regex_match(choiceStr, intRegex)) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        choice = std::stoi(choiceStr);

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
                std::cout << "Exiting...\n";
            break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}

// int main() {
//     try {
//         hashTableSC table;
//
//         table.insert("apple", "red");
//         table.insert("banana", "yellow");
//         table.insert("grape", "purple");
//
//         std::cout << "apple: " << table.search("apple") << std::endl;
//         std::cout << "banana: " << table.search("banana") << std::endl;
//
//         table.insert("apple", "green");
//         std::cout << "apple (updated): " << table.search("apple") << std::endl;
//
//         table.insert("orange", "orange");
//         table.insert("lemon", "yellow");
//         table.insert("lime", "green");
//
//         std::cout << "After rehash:" << std::endl;
//         std::cout << "grape: " << table.search("grape") << std::endl;
//         std::cout << "lime: " << table.search("lime") << std::endl;
//
//         // std::cout << "Load Factor: " << table.getLoadFactor() << std::endl;
//         // std::cout << "Memory Utilization: " << table.memoryUtilization() << std::endl;
//
//         std::cout << table.search("pear") << std::endl;
//     } catch (const std::exception& e) {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     return 0;
// }