#include "Controller.hpp"
#include <iostream>

using namespace std;
using namespace performance_map;

int Controller::get_best_config_id(){
    if (library == NULL){
        if (path != "")
        {
            library = new Model();
            library->set_path(path);
        }
        else
            std::cerr << "No BPM library path available";
    }
    return library->get_best_config_id();
}
