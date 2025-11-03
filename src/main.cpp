//
// Created by jerem on 11/2/2025.
//
#include <iostream>
#include <movie.h>
#include <ostream>
#include <parser.h>

using namespace std;

void testParser() {
    vector<Movie> movies = movieParser("data/title.basics.tsv");
    cout << "Size of movie vector: " << endl;
    cout << movies.size() << endl;
}


int main(int argc, char *argv[]) {
    testParser();
}
