#include "Controller.hpp"
#include <iostream>
#include <system_modelling/io/ConfigReader.hpp>
#include <system_modelling/io/CndModelWriter.hpp>

using namespace std;
using namespace performance_map;

ConfigSet Controller::get_best_config()
{
    return this->mLibrary.get_best_config();
}

void Controller::load_best_config_set(graph_analysis::BaseGraph::Ptr graph)
{
    system_modelling::io::ConfigReader configReader;
    ConfigSet bestConfig = mLibrary.get_best_config();
    std::vector<std::string> paths = bestConfig.get_paths(); 
    std::vector<std::string> sections = {std::to_string(bestConfig.get_id())};
    system_modelling::io::CndModelWriter writer;
    writer.write("GraphContents.yml", graph);
    //for (std::vector<std::string>::const_iterator taskIterator = paths.begin(); taskIterator != paths.end(); ++taskIterator)
    for (auto taskIterator : paths)
    {
        std::string configPath = taskIterator;
        std::cout << "[Controller::load_best_config_set]Config path: " << configPath << std::endl;
        configReader.read(configPath, graph, sections); 
        std::cout << "Config path: " << taskIterator << std::endl;
    }
}
