#include <fstream>
#include <iostream>

#include "services/data_manager.hpp"
#include "core/content.hpp"

void DataManager::content_frame (std::ofstream & file, Content & content) {

    file_frame(file, content.get_id());
    file_frame(file, content.get_title());
    file_frame(file, static_cast<int>(content.get_type()));
    file_frame(file, static_cast<int>(content.get_genre()));
    file_frame(file, content.get_year());
    file_frame(file, content.get_views());
    file_frame(file, content.get_rating());
    file << "\n";

}

void DataManager::write_content (Content & content) {

    std::ofstream write_file(data_file, std::ios::app);

    if (write_file.is_open()) {
        
        content_frame(write_file, content);
        write_file.close();

    } else {
        std::cout << "Erro, arquivo não encontrado" << std::endl;
    }

}


