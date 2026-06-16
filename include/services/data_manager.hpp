#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "core/content.hpp"

class DataManager {

    protected:

        std::string data_file;

        template <typename T> 
        void file_frame (std::ofstream & file, T info) { file << info << ";"; }

    public:

        DataManager (const std::string & data_file): data_file(data_file) {}

        void write_content(Content & content);
        void update_content (int id, Content & content);
        void remove_content(int id);
        Content * get_content (int id);

};