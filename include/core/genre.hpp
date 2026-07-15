#pragma once

#include <iostream>
#include <string>
#include "containers/doubly_linked_list.hpp"

class Genre {
    public:
        enum Value {
            ACTION = 1,
            COMEDY = 2,
            ROMANCE = 3,
            HORROR = 4,
            SUSPENSE = 5,
            DRAMA = 6,
            SCIENCE_FICTION = 7,
            SLICE_OF_LIFE = 8
        };

    private:
        int id;
        std::string name;
        DoublyLinkedList<std::string> subgenres_list;
        static DoublyLinkedList<Genre> genres_list;

    public:
        Genre();
        Genre(int id, std::string name, DoublyLinkedList<std::string> subgenres_list);

        void addSubgenre(const std::string& s);
        static void addGenre(const Genre& g);

        int get_id() const;
        std::string get_name() const;
        Value get_genre() const;
        DoublyLinkedList<std::string> get_subgenres();
        static DoublyLinkedList<Genre>& get_genres_list();
};