#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

void ContentManager::save_data () {

    std::ofstream file(data_file);

    if (!file.is_open()) return;

    main_list.go_start();

    while () content_frame (file, content);

}

void ContentManager::load_data() {
    
   
}

Node * ContentManager::get_list() {

    
}