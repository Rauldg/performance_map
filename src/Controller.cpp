#include "Controller.hpp"
#include <iostream>
#include <system_modelling/io/ConfigReader.hpp>

using namespace std;
using namespace performance_map;

ConfigSet Controller::get_best_config()
{
    return this->mLibrary.get_best_config();
}

void Controller::load_best_config_set(const graph_analysis::BaseGraph::Ptr graph)
{
    system_modelling::io::ConfigReader reader;
    ConfigSet bestConfig = mLibrary.get_best_config();
    std::vector<std::string> paths = bestConfig.get_paths();
    std::cout << "FOO" << std::endl;
    for (std::vector<std::string>::const_iterator taskIterator = paths.begin(); taskIterator != paths.end(); ++taskIterator)
    {
        std::cout << "Config path: " << taskIterator->c_str() << std::endl;
    }
}
