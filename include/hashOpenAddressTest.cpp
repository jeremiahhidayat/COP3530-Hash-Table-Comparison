//
// Created by kaide on 11/7/2025.
//

#include "hashOpenAddress.h"
#include <iostream>

int main() {
    try {
        hashOpenAddress table(5, 0.6f);

        table.insert("apple", "red");
        table.insert("banana", "yellow");
        table.insert("grape", "purple");

        std::cout << "apple: " << table.search("apple") << std::endl;
        std::cout << "banana: " << table.search("banana") << std::endl;

        table.insert("apple", "green");
        std::cout << "apple (updated): " << table.search("apple") << std::endl;

        table.insert("orange", "orange");
        table.insert("lemon", "yellow");
        table.insert("lime", "green");

        std::cout << "After rehash:" << std::endl;
        std::cout << "grape: " << table.search("grape") << std::endl;
        std::cout << "lime: " << table.search("lime") << std::endl;

        std::cout << "Load Factor: " << table.getLoadFactor() << std::endl;
        std::cout << "Memory Utilization: " << table.memoryUtilization() << std::endl;

        std::cout << table.search("pear") << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}