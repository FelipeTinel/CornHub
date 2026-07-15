#pragma once

#include <iostream>
#include <string>

#include "genre.hpp"
#include "type.hpp"

class Question {

    private:

        bool is_genre_question = true;
        std::string question_text;
        Genre genre;
        std::string subgenre;

        
    public:

        Question(const Genre& genre, bool is_genre_question);
        Question(const std::string& subgenre, bool is_genre_question);

        std::string get_question() const;
        Genre get_genre() const;


        void set_bool(bool is_genre_question);
        void set_question(std::string question);
        void set_genre(const Genre& genre);

};