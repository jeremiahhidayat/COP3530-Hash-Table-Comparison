//
// Created by jerem on 11/2/2025.
//
#include <iostream>
#include <ostream>
#include <limits>
#include <sstream>

#include <string>
#include <regex>
#include <algorithm>

#include "CLI.h"
#include "parser.h"
#include "hashOpenAddress.h"
#include "hashSeparateAddress.h"

using namespace std;

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
