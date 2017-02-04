#include "Controller.hpp"
#include <iostream>
#include <system_modelling/io/ConfigReader.hpp>

using namespace std;
using namespace performance_map;

ConfigSet Controller::getBestConfig()
{
    return this->mLibrary.getBestConfig();
}

void Controller::init(const std::string & path)
{
    mLibrary.init(path);
}

int Controller::load_best_config_set(graph_analysis::BaseGraph::Ptr graph)
{
    //std::cout << "[Controller::load_best_config_set] Model Path: "<<  mLibrary.get_path() << std::endl;
    system_modelling::io::ConfigReader configReader;
    //std::cout << "[Controller::load_best_config_set] Before get_best_config: " << std::endl;
    ConfigSet bestConfig = mLibrary.getBestConfig();
    //std::cout << "[Controller::load_best_config_set] Best Config Path[0]: "<<  bestConfig.paths[0] << std::endl;
    std::vector<std::string> paths = bestConfig.get_paths(); 
    int id_best = bestConfig.get_id();
    std::vector<std::string> sections = {std::to_string(id_best)};
    for (auto taskIterator : paths)
    {
        std::string configPath = taskIterator;
        //std::cout << "[Controller::load_best_config_set] Config path: " << configPath << std::endl;
        configReader.read(configPath, graph, sections); 
        //std::cout << "Config path: " << taskIterator << std::endl;
    }
    return id_best;
}
