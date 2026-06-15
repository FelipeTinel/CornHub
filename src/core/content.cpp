#include <iostream>

#include "core/content.hpp"

int Content::next_id = 1;

Content::Content (std::string title, Type type, Genre genre, int year, long views, float rating):

    id(next_id++),
    title(title),
    type(type),
    genre(genre),
    year(year),
    views(views),
    rating(rating)

{}

int Content::get_id() { return id; }
std::string Content::get_title() { return title; }
Type Content::get_type() { return type; }
Genre Content::get_genre() { return genre; }
int Content::get_year() { return year; }
long Content::get_views() { return views; }
float Content::get_rating () { return rating; }