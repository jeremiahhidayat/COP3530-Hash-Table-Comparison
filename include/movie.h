//
// Created by jerem on 11/2/2025.
//

#ifndef PROJECT_2_MOVIE_H
#define PROJECT_2_MOVIE_H

#include <string>
using namespace std;


// will be hashing on tconst for easy hashing
struct Movie{
    string id;
    string title;
    int year{};
    string genres;

    Movie() = default;

    Movie(const string& id, const string& title, const int year,const string& genres)
    : id(id), title(title), year(year), genres(genres) {}
};

#endif //PROJECT_2_MOVIE_H