#include <boost/test/unit_test.hpp>
#include <performance_map/ConfigSet.hpp>
#include <performance_map/MapsDefines.hpp>
#include <string>
#include <configmaps/ConfigData.h>
#include <base-logging/Logging.hpp>


using namespace performance_map;
using namespace configmaps;

void check_contains(ConfigSet & config_set, const std::string & task_name, 
        const ConfigMap &task_config_map){
    TaskConfig task_config;
    bool exists = config_set.get_task(task_name, task_config);
    BOOST_CHECK(exists);
    BOOST_CHECK(task_config.matches(task_name, task_config_map));
}


/*
BOOST_AUTO_TEST_CASE(constructors_ConfigSet)
{
    ConfigMap map;
    map[ID] = 1;
    ConfigSet config(map);
    BOOST_CHECK(config.get_id() == 1);
    // Load the map from the correspondent yml and use the map to instantiate
    // the ConfigSet
    const std::string path="./maps_tests";
    map = ConfigMap::fromYamlFile(path + SAMPLES_PATH + "1.yml");
    map.toYamlFile("Test_ConfigSet.yml");
    ConfigSet config_set(map);
    // Go through the elements in the config set and check that the values
    // correspond
    ConfigMap::FIFOMap::iterator it;
    for(it=map.begin(); it!=map.end(); ++it) {
        if ((it->first)!= ID)
        {
            std::string task_name = it->first;
            ConfigMap task_config_vals = it->second;
            check_contains(config_set, task_name, task_config_vals);
            //TaskConfig task_config(task_name, task_config_vals);

        }
        LOG_DEBUG_S << "key:  " << it->first;
    }
}
*/
