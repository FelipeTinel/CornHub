#include <iostream>
#include <fstream>
#include <string>

#include "data_manager.hpp"

class ContentManager : public DataManager {

    private:

        void content_frame (std::ofstream & file, Content & content);

    public:

        ContentManager (std::string & data_file) : DataManager(data_file) {}


};