//
// Created by jerem on 11/2/2025.
//

#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//Make sure that the workspace is set right: Run > Edit Configurations > Working Directory > set to your project root.
vector<Movie> movieParser(const string &filename) {
    vector<Movie> movies;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return {};
    }
    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        Movie movie;

        getline(ss, movie.id, '\t'); // tconst
        std::getline(ss, token, '\t'); // titleType
        std::getline(ss, movie.title, '\t'); //primaryTitle

        std::getline(ss, token, '\t'); // originalTitle
        std::getline(ss, token, '\t'); // isAdult

        std::getline(ss, token, '\t'); // startYear
        movie.year = (token != "\\N") ? std::stoi(token) : -1;

        std::getline(ss, token, '\t'); // endYear (skip)
        std::getline(ss, token, '\t'); // runtimeMinutes

        std::getline(ss, movie.genres);

        movies.push_back(movie);
    }

    return movies;
}