#include <iostream>

#include "core/question.hpp"

Question::Question(const Genre& g, bool is_genre) : is_genre_question(is_genre), genre(g) {
    if (is_genre_question) {
        question_text = "Do you like " + genre.get_name() + "?";
    }
}

Question::Question(const std::string& sub, bool is_genre) : is_genre_question(is_genre), subgenre(sub) {
    if (!is_genre_question) {
        question_text = "Do you like " + subgenre + "?";
    }
}

std::string Question::get_question() const {
    return question_text;
}

Genre Question::get_genre() const {
    return genre;
}

void Question::set_bool(bool is_genre) {
    is_genre_question = is_genre;
}

void Question::set_question(std::string q) {
    question_text = q;
}

void Question::set_genre(const Genre& g) {
    genre = g;
}