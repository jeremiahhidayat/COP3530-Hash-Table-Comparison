//
// Created by jerem on 11/2/2025.
//

#include "parser.h"
#include <fstream>
#include <sstream>
using namespace std;

vector<Movie> parserMovies(const string &filename) {
    vector<Movie> movies;
    ifstream file(filename);
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

        std::getline(ss, movie.genres, '\t');

        movies.push_back(movie);
    }

    return movies;
}