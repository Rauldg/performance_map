#include "ConfigSet.hpp"
#include <iostream>
#include "MapsDefines.hpp"

#include <base-logging/Logging.hpp>

using namespace performance_map;
using namespace configmaps;

ConfigSet::ConfigSet(configmaps::ConfigMap map){
    id = map.get(ID, -1);
    if (id == -1){
        LOG_ERROR("Error in map from which config set is to be created");
    }
    // For each task in the map create the correspondent TaskConfig object and
    // add it to the vector "set"

    ConfigMap::FIFOMap::iterator it;
    for(it=map.begin(); it!=map.end(); ++it) {
        if ((it->first)!= ID)
        {
            std::string task_name = it->first;
            ConfigMap task_config_vals = it->second;
            TaskConfig task_config(task_name, task_config_vals);
            set.push_back(task_config);
        }
    }
}

bool ConfigSet::get_task(const std::string &task_name, TaskConfig &task_config){
    bool found = false;
    std::vector<TaskConfig>::iterator it;
    while((it!=set.end()) and (not found)){
        if (it->get_name() == task_name)
        {
            found = true;
            task_config = *it;
        }
        it++;
    }
    return found;
}
