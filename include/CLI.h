//
// Created by jerem on 11/5/2025.
//

#ifndef CLI_H
#define CLI_H

#include "hashOpenAddress.h"
#include <iostream>
#include "movie.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <limits>
#include <chrono>
#include <random>
#include <algorithm>

enum class TableType {
    SEPARATE_CHAIN,
    OPEN_ADDRESS,
};

void showMainMenu();
void showSubMenu();
template <typename T>
void interactiveSession(T& table);
void runCLI(TableType type);
void compareImplementations();

#endif //CLI_H
