#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "containers/doubly_linked_list.hpp"
#include "services/Genre_manager.hpp"
#include "core/genre.hpp"

void GenreManager::Genre_frame (std::ofstream & file, const Genre & Genre) {

    file_frame(file, Genre.get_id());
    file_frame(file, Genre.get_name());
    file_frame(file, static_cast<int>(Genre.get_genre()));

    file << "\n";

}

void GenreManager::save_data (const DoublyLinkedList<Genre> & list) {

    std::ofstream file(data_file);

    if (!file.is_open()) return;

    Node<Genre> * pointer = list.get_head();
    
    while (pointer != nullptr) {

        Genre_frame(file, pointer->info);
        pointer = pointer->next;

    }

    file.close();

}

void GenreManager::load_data(DoublyLinkedList<Genre> & list) {
    
    std::ifstream file(data_file);
    if (!file.is_open()) {
        std::cout << "Arquivo não encontrado." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string field;

        std::getline(ss, field, ';');
        int id = std::stoi(field);

        std::string name;
        std::getline(ss, name, ';');

        std::getline(ss, field, ';');
        Genre genre = static_cast<Genre>(std::stoi(field));

        std::getline(ss, field, '{');
        DoublyLinkedList<std::string> subgenres_list;
        while(std::getline(ss, field, ',') && field != '}'){
            
            subgenres_list.insert(field);
        }

        Genre Genre(id, name, subgenres_list);
        list.insert(Genre);
    }

    file.close();
}
