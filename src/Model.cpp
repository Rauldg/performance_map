#include <iostream>
#include <base-logging/Logging.hpp>

#include "Model.hpp"
// Would be much nicer to do it the system_modelling way and not use the config maps

#include <yaml-cpp/yaml.h>
#include <fstream>

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

void Model::reshape_config_file(int id)
{
    YAML::Node all_configs = YAML::LoadFile(path + SAMPLES_PATH + "/" + std::to_string(id) + ".yml" );
    std::vector<std::string> tasks;
    for (YAML::const_iterator it=all_configs.begin(); it!=all_configs.end(); ++it){
        // find out the name of the tasks
        std::string key = it->first.as<std::string>();
        if ((key != ID_LABEL) and (key != OVERPASSED_LABEL))
        {
            // Key corresponds to a task. Improve the yml so that the tasks are stored as a list in its own dictionary entry
            tasks.push_back(it->first.as<std::string>());
            YAML::Node file_content;
            file_content[TASK_NAME_LABEL] = key;
            std::string taskType;
            if (key == "trajectory_follower")
                taskType = "trajectory_follower::Task";
            if (key == "motion_planner")
                taskType = "motion_planning_libraries::Task";
            if (key == "traversability")
                taskType = "traversability::Simple";
            file_content[TASK_TYPE_LABEL] = taskType;
            file_content[SECTION_LABEL][id] = all_configs[key];
            std::string filename = path+SAMPLES_PATH+"/"+key+"_"+std::to_string(id)+".yml";
            std::ofstream task_file (filename, std::ofstream::out);
            task_file << file_content;
            task_file.close();
        }
    }
}

std::vector<std::string> Model::get_config_paths(int id)
{
    reshape_config_file(id);
    YAML::Node all_configs = YAML::LoadFile(path + SAMPLES_PATH + "/" + std::to_string(id) + ".yml" );
    std::vector<std::string> result;
    for (YAML::const_iterator it=all_configs.begin(); it!=all_configs.end(); ++it){
        std::string key = it->first.as<std::string>();
        if ((key != ID_LABEL) and (key != OVERPASSED_LABEL))
        {
            std::string filename = path+SAMPLES_PATH+"/"+key+"_"+std::to_string(id)+".yml";
            result.push_back(filename);
        }
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


