#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "containers/doubly_linked_list.hpp"
#include "services/content_manager.hpp"
#include "core/content.hpp"

void ContentManager::content_frame (std::ofstream & file, const Content & content) {

    file_frame(file, content.get_id());
    file_frame(file, content.get_title());
    file_frame(file, static_cast<int>(content.get_type()));
    file_frame(file, static_cast<int>(content.get_genre()));
    file_frame(file, content.get_year());
    file_frame(file, content.get_views());
    file_frame(file, content.get_rating());
    file << "\n";

}

void ContentManager::save_data (const DoublyLinkedList<Content> & list) {

    std::ofstream file(data_file);

    if (!file.is_open()) return;

    Node<Content> * pointer = list.get_head();
    
    while (pointer != nullptr) {

        content_frame(file, pointer->info);
        pointer = pointer->next;

    }

    file.close();

}

Node<Content> * ContentManager::load_data(DoublyLinkedList<Content> & list) {
    
    

}
