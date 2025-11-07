//
// Created by jerem on 11/2/2025.
//

#ifndef PROJECT_2_MOVIE_H
#define PROJECT_2_MOVIE_H

#include <iostream>
#include <ostream>
#include <string>
#include <bits/unique_ptr.h>

// Note: hash key is the Movie.id (tconst)
struct Movie{
    std::string id;
    std::string title;
    int year = -1;
    std::string genres = "Unknown";
    int runtime = -1;

    Movie() = default;

    Movie(const std::string& id, const std::string& title, const int year,const std::string& genres, int runtime)
    : id(id), title(title), year(year), genres(genres), runtime(runtime) {}

    void display() const {
        std::cout << "id: " << id << std::endl;
        std::cout << "title: " << title << std::endl;
        std::cout << "year: " << year << std::endl;
        std::cout << "genres: " << genres << std::endl;
        std::cout << "runtime: " << runtime << std::endl;

    }
};

#endif //PROJECT_2_MOVIE_H