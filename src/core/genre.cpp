#include <iostream>

#include "core/genre.hpp"

// Initialize the static member variable genres_list
DoublyLinkedList<Genre> Genre::genres_list;

Genre::Genre() : id(0), name(""), subgenres_list() {}

Genre::Genre(int i, std::string n, DoublyLinkedList<std::string> sg_list) : id(i), name(n), subgenres_list(sg_list) {
    addGenre(*this); // Adiciona o gênero à lista de gêneros
}

void Genre::addSubgenre(const std::string& s) { 
    subgenres_list.insert(s); 
} 

void Genre::addGenre(const Genre& g) { 
    genres_list.insert(g); 
}

int Genre::get_id() const { 
    return id; 
}

std::string Genre::get_name() const { 
    return name; 
}

Genre::Value Genre::get_genre() const { 
    return static_cast<Genre::Value>(id); 
}

DoublyLinkedList<std::string> Genre::get_subgenres() { 
    return subgenres_list; 
}

DoublyLinkedList<Genre>& Genre::get_genres_list() { 
    return genres_list; 
}