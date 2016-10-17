#include "ConfigSet.hpp"
#include <iostream>
#include "MapsDefines.hpp"

#include <base-logging/Logging.hpp>

using namespace performance_map;
using namespace configmaps;

ConfigSet::ConfigSet(ConfigMap map){
    id = map.get(ID, -1);
    if (id == -1){
        LOG_ERROR("Error in map from which config set is to be created");
    }

}
