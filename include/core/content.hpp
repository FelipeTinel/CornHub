#pragma once

#include <iostream>
#include <string>

#include "genre.hpp"
#include "type.hpp"
class Content {

    private:

        static int next_id;

        int id, year;
        std::string title;
        Type type;
        Genre genre;
        long views;
        float rating;

    public:

        Content (std::string title, Type type, Genre genre, int year, long views, float rating);

        int get_id();
        std::string get_title();
        Type get_type();
        Genre get_genre();
        int get_year();
        long get_views();
        float get_rating();

};