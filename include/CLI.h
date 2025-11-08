//
// Created by jerem on 11/5/2025.
//

#include "hashOpenAddress.h"
#include "hashTemplate.h"
#include <string>
#include <iostream>
#include "movie.h"

#ifndef CLI_H
#define CLI_H

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
