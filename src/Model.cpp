#include "Controller.cpp"
#include <iostream>
#include <base-logging/Logging.hpp>

// Would be much nicer to do it the system_modelling way and not use the config maps

#include <yaml-cpp/yaml.h>

using namespace std;
using namespace performance_map;

YAML::Node Model::get_max_performance_and_id(){
    double max = 0.0;
    YAML::Node resul;
    YAML::Node ids_performances;
    try 
    {
        ids_performances = YAML::LoadFile(path + IDS_PERFORMANCES_FILE);
    }
    catch (...)
    {
        LOG_ERROR_S << "Unable to load file: " + path + IDS_PERFORMANCES_FILE;
        throw;
    }
    for (YAML::Node::const_iterator it=ids_performances.begin(); it!=ids_performances.end(); ++it){
        YAML::Node map = *it;
        double performance = map[PERFORMANCE_LABEL].as<double>();
        if (max < performance)
        {
            resul = map;
            max = performance;
        }
    }
    return resul;
}

std::vector<std::string> Model::get_config_paths(int id)
{
    YAML::Node all_configs = YAML::LoadFile(path + SAMPLES_PATH + "/" + std::to_string(id) + ".yml" );
    std::vector<std::string> result;
    std::vector<std::string> tasks;
    for (YAML::const_iterator it=all_configs.begin(); it!=all_configs.end(); ++it){
        // find out the name of the tasks
        std::string key = it->first.as<std::string>();
        if ((key != ID_LABEL) and (key != OVERPASSED_LABEL))
        {
            // Key corresponds to a task. Improve the yml so that the tasks are stored as a list in its own dictionary entry
            std::cout << "Task Name " << it->first.as<std::string>() << std::endl;
            tasks.push_back(it->first.as<std::string>());
            all_configs[]
        }

    // Split in the different tasks, store and provide a vector with those
    for (YAML::Node::const_iterator it=all_configs.begin(); it!=all_configs.end(); ++it){
        YAML::Node map = *it;
        if ((.as<std::string>() != ID_LABEL) and 
                (map[0].as<std::string>() != OVERPASSED_LABEL))
        {
            std::cout << "Task Name " << it->first.as<std::string>() << std::endl;
            YAML::Node map = *it;
            if (map.IsMap())
                std::cout << "Is a map" << std::endl;
            YAML::Emitter output; 
            output << map;
            std::cout << "To store in filename " << output.c_str() << std::endl;
            
        }
        //if (map.IsMap())
        //{
        //std::cout << "Task Name " << it->first.as<std::string>() << std::endl;
        //}
    }
    return result;
}

ConfigSet Model::get_best_config(){
    // Go through all the ids, select the one with highest performance and return the correspondent config set
    //int id = 0;
    //configmaps::ConfigMap map;
    //map = configmaps::ConfigMap::fromYamlFile("test.yml");
    //configmaps::ConfigVector::iterator it;
    //for(it=map["list"].begin(); it!=map["list"].end(); ++it) {
    //  printf("list entry: %s\n", it->getString().c_str());
    //}
    YAML::Node id_performance = get_max_performance_and_id();
    int id = id_performance[ID_LABEL].as<int>();
    ConfigSet result(id);
    result.paths = get_config_paths(id);
    return result;
}



double Model::get_max_performance(){
    YAML::Node best = get_max_performance_and_id();
    return best[PERFORMANCE_LABEL].as<double>();
}


