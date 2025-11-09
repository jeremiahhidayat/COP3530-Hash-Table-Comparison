//
// Created by jerem on 11/5/2025.
//

#include "../include/CLI.h"

#include "hashSeparateAddress.h"
#include "parser.h"
using namespace std;

void showMainMenu() {
    cout << "\n--- IMDb Movie Hash Table Benchmark ---" << endl;
    cout << "   1. Use Separate Chaining Hash Table" << endl;
    cout << "   2. Use Open Addressing Hash Table" << endl;
    cout << "   3. Compare Performance"            <<endl;
    cout << "   4. Exit" << endl;
}

void showSubMenu() {
    cout << "\n--- Hash Table Operations --- " << endl;
    cout << "   1. Load IMDb Dataset and Insert into Hash Table" << endl;
    cout << "   2. Search for a Movie Title" << endl;
    cout << "   3. Delete a Record" << endl;
    cout << "   4. Go Back to Main Menu " << endl;
    cout << "\nEnter Choice: ";
}

template <typename T>
void interactiveSession(T& table) {
    bool allFlag = false;
    string key;
    int choice = 0;

    // Regex to match integers
    regex intRegex(R"(^-?\d+$)");

    do {
        showSubMenu();

        string choiceStr;
        getline(cin, choiceStr);
        choiceStr.erase(remove(choiceStr.begin(), choiceStr.end(), '\r'), choiceStr.end());

        if (!regex_match(choiceStr, intRegex)) {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        choice = stoi(choiceStr);

        switch (choice) {
            // --- Load dataset ---
            case 1: {
                int amount = 0;
                bool printFlag = false;

                cout << "Enter number of IMDb entries (-1 for all) \nnote: does not print more than 50 \nentry: ";
                while (true) {
                    string amountStr;
                    getline(cin, amountStr);
                    amountStr.erase(remove(amountStr.begin(), amountStr.end(), '\r'), amountStr.end());

                    if (regex_match(amountStr, intRegex)) {
                        amount = stoi(amountStr);
                        break;
                    } else {
                        cout << "Invalid number. Try again: ";
                    }
                }

                // if -1 -> false
                // print if amount <= 50 is true
                printFlag = (amount != -1 && amount <= 50);

                vector<Movie> movies = movieParser("data/title.basics.tsv", amount);
                int movieCount = 0;

                auto start = chrono::high_resolution_clock::now(); // start timing
                for (const auto& movie : movies) {
                    table.insert(movie.title, movie.genres);
                    movieCount++;
                    if (printFlag)
                        cout << "Inserted: " << movie.title << "\n";
                }
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;

                cout << "Insertion of " << movieCount << " movies complete. Time taken: "
                     << elapsed.count() << " seconds.\n";
                break;
            }

            // --- Search for a movie ---
            case 2: {
                cout << "Enter key: ";
                getline(cin, key);
                key.erase(remove(key.begin(), key.end(), '\r'), key.end());

                auto start = chrono::high_resolution_clock::now();
                try {
                    string result = table.search(key);
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> elapsed = end - start;

                    cout << key << "'s genres is/are: " << result << "\n";
                    cout << "Search took: " << elapsed.count() << " seconds.\n";
                } catch (const runtime_error& e) {
                    auto end = chrono::high_resolution_clock::now();
                    chrono::duration<double> elapsed = end - start;

                    cout << e.what() << "\n";
                    cout << "Search took: " << elapsed.count() << " seconds.\n";
                }
                break;
            }

            // --- Remove a movie ---
            case 3: {
                cout << "Enter key to remove: ";
                getline(cin, key);
                key.erase(remove(key.begin(), key.end(), '\r'), key.end());

                auto start = chrono::high_resolution_clock::now();
                bool removed = table.remove(key);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = end - start;

                if (removed) {
                    cout << "Removed \"" << key << "\" successfully.\n";
                } else {
                    cout << "Key \"" << key << "\" not found.\n";
                }
                cout << "Remove operation took: " << elapsed.count() << " seconds.\n";
                break;
            }

            // --- Return to main menu ---
            case 4: {
                cout << "Returning to main menu.\n";
                break;
            }

            default:
                cout << "Invalid option. Please enter a valid choice.\n";
        }

    } while (choice != 4);
}


void runCLI(TableType type) {
    if (type == TableType::SEPARATE_CHAIN) {
        hashSeparateAddress table;
        cout << "\nUsing Separate Chaining Hash Table\n";
        interactiveSession(table);
    } else {
        hashOpenAddress table;
        cout << "\nUsing Open Addressing Hash Table\n";
        interactiveSession(table);
    }
}

void compareImplementations() {
    using namespace std;
    using namespace std::chrono;

    int amount = 0;
    int searchCount = 0;
    regex intRegex(R"(^-?\d+$)");

    // Get number of movies to load
    cout << "Enter number of IMDb entries to compare (-1 for all, highly unrecommended): ";
    while (true) {
        string amountStr;
        getline(cin, amountStr);
        amountStr.erase(remove(amountStr.begin(), amountStr.end(), '\r'), amountStr.end());
        if (regex_match(amountStr, intRegex)) {
            amount = stoi(amountStr);
            break;
        } else {
            cout << "Invalid number. Try again: ";
        }
    }

    // Get number of random searches
    cout << "Enter number of random searches to perform: ";
    while (true) {
        string searchStr;
        getline(cin, searchStr);
        searchStr.erase(remove(searchStr.begin(), searchStr.end(), '\r'), searchStr.end());
        if (regex_match(searchStr, intRegex)) {
            searchCount = stoi(searchStr);
            break;
        } else {
            cout << "Invalid number. Try again: ";
        }
    }

    vector<Movie> movies = movieParser("data/title.basics.tsv", amount);
    int movieCount = movies.size();

    if (searchCount > movieCount) searchCount = movieCount; // clamp to available movies

    // Prepare random subset of movies to search
    vector<int> indices(movieCount);
    iota(indices.begin(), indices.end(), 0); // fill with 0..movieCount-1
    random_device rd;
    mt19937 gen(rd());
    shuffle(indices.begin(), indices.end(), gen);

    vector<int> searchIndices(indices.begin(), indices.begin() + searchCount);

    // --- Separate Chaining ---
    hashSeparateAddress scTable;
    auto start = high_resolution_clock::now();
    for (const auto& movie : movies) scTable.insert(movie.title, movie.genres);
    auto end = high_resolution_clock::now();
    auto insertTimeSC = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (int idx : searchIndices) {
        try { scTable.search(movies[idx].title); } catch(...) {}
    }
    end = high_resolution_clock::now();
    auto searchTimeSC = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (const auto& movie : movies) scTable.remove(movie.title);
    end = high_resolution_clock::now();
    auto removeTimeSC = duration<double>(end - start).count();

    // --- Open Addressing ---
    hashOpenAddress oaTable;
    start = high_resolution_clock::now();
    for (const auto& movie : movies) oaTable.insert(movie.title, movie.genres);
    end = high_resolution_clock::now();
    auto insertTimeOA = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (int idx : searchIndices) {
        try { oaTable.search(movies[idx].title); } catch(...) {}
    }
    end = high_resolution_clock::now();
    auto searchTimeOA = duration<double>(end - start).count();

    start = high_resolution_clock::now();
    for (const auto& movie : movies) oaTable.remove(movie.title);
    end = high_resolution_clock::now();
    auto removeTimeOA = duration<double>(end - start).count();

    // --- Print results ---
    cout << "\n--- Hash Table Performance Comparison ---\n";
    cout << "Number of movies tested: " << movieCount << "\n";
    cout << "Random searches performed: " << searchCount << "\n\n";

    cout << "Separate Chaining:\n";
    cout << "  Insert time: " << insertTimeSC << " s\n";
    cout << "  Search time: " << searchTimeSC << " s\n";
    cout << "  Remove time: " << removeTimeSC << " s\n\n";

    cout << "Open Addressing:\n";
    cout << "  Insert time: " << insertTimeOA << " s\n";
    cout << "  Search time: " << searchTimeOA << " s\n";
    cout << "  Remove time: " << removeTimeOA << " s\n";

    cout << "\n--- Summary of Faster Implementation ---\n";
    cout << "Insert: " << ((insertTimeSC < insertTimeOA) ? "Separate Chaining" : "Open Addressing") << "\n";
    cout << "Search: " << ((searchTimeSC < searchTimeOA) ? "Separate Chaining" : "Open Addressing") << "\n";
    cout << "Remove: " << ((removeTimeSC < removeTimeOA) ? "Separate Chaining" : "Open Addressing") << "\n";
}
