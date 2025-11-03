//
// Created by jerem on 11/2/2025.
//

#ifndef PROJECT_2_MOVIE_H
#define PROJECT_2_MOVIE_H

#include <string>

// Note: hash key is the Movie.id (tconst)
struct Movie{
    std::string id;
    std::string title;
    int year = -1;
    std::string genres = "Unknown";

    Movie() = default;

    Movie(const std::string& id, const std::string& title, const int year,const std::string& genres)
    : id(id), title(title), year(year), genres(genres) {}
};

#endif //PROJECT_2_MOVIE_H