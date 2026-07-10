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

void ContentManager::save_data (DoublyLinkedList & list) {

    std::ofstream write_file(data_file, std::ios::app);

    if (write_file.is_open()) {
        
        content_frame(write_file, content);
        write_file.close();

    } else {
        std::cout << "Erro, arquivo não encontrado." << std::endl;
    }

}

void ContentManager::load_data(DoublyLinkedList & list) {
    
    std::ifstream read_content(data_file);
    std::string line;

    if (!read_content.is_open()) {
        std::cerr << "Arquivo não encontrado" << std::endl;
        return;
    }

    while (std::getline(read_content, line)) {
        
        if (line.empty()) continue; 
        
        std::stringstream ss(line);
        std::string camp;
        
        if (std::getline(ss, camp, ';')) {
            
            int actual_id = std::stoi(camp);
            
            std::string title, str_type, str_genre, str_year, str_views, str_rating;
            
            std::getline(ss, title, ';');
            std::getline(ss, str_type, ';');
            std::getline(ss, str_genre, ';');
            std::getline(ss, str_year, ';');
            std::getline(ss, str_views, ';');
            std::getline(ss, str_rating, ';');

            Type type = static_cast<Type>(std::stoi(str_type));
            Genre genre = static_cast<Genre>(std::stoi(str_genre));
            int year = std::stoi(str_year);
            long views = std::stol(str_views);
            float rating = std::stof(str_rating);

            Content content(title, type, genre, year, views, rating);
            
            main_list.insert(content);
        } 
    }
    
    read_content.close(); 
}

