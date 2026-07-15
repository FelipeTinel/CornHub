#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "data_manager.hpp"
#include "core/genre.hpp"
#include "containers/doubly_linked_list.hpp"

class GenreManager : public DataManager<Genre> {

    private:

        void Genre_frame(std::ofstream & file, const Genre & genre);

    public: 

        GenreManager(const std::string & data_file) : DataManager<Genre>(data_file) {}

        void save_data(const DoublyLinkedList<Genre> & list) override;
        void load_data(DoublyLinkedList<Genre> & list) override;

};