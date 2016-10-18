#include <boost/test/unit_test.hpp>
#include <performance_map/TaskConfig.hpp>
#include <configmaps/ConfigData.h>
#include <performance_map/MapsDefines.hpp>
#include <base-logging/Logging.hpp>

using namespace performance_map;
using namespace configmaps;

BOOST_AUTO_TEST_CASE(constructors_TaskConfig){
    const std::string path="./maps_tests";
    ConfigMap map = ConfigMap::fromYamlFile(path + SAMPLES_PATH + "1.yml");
    ConfigMap::FIFOMap::iterator it;
    for(it=map.begin(); it!=map.end(); ++it) {
        if ((it->first)!= ID)
        {
            std::string task_name = it->first;
            ConfigMap task_config_vals = it->second;
            TaskConfig task_config(task_name, task_config_vals);
        }
        LOG_DEBUG_S << "key:  " << it->first;
    }
}
BOOST_AUTO_TEST_CASE(match_TaskConfig_map){
    const std::string path="./maps_tests";
    ConfigMap map = ConfigMap::fromYamlFile(path + SAMPLES_PATH + "1.yml");
    ConfigMap map2 = ConfigMap::fromYamlFile(path + SAMPLES_PATH + "2.yml");
    ConfigMap::FIFOMap::iterator it;
    for(it=map.begin(); it!=map.end(); ++it) {
        if (((it->first)!= ID) and  ((it->first)!= OVERPASSED))
        {
            std::string task_name = it->first;
            ConfigMap task_config_vals = it->second;
            TaskConfig task_config(task_name, task_config_vals);
            BOOST_CHECK(task_config.matches(task_name, task_config_vals));
            // Check against all tasks Configs from the other yml
            ConfigMap::FIFOMap::iterator it2;
            for(it2=map2.begin(); it2!=map2.end(); ++it2) {
                if (((it2->first)!= ID) and  ((it2->first)!= OVERPASSED))
                {
                    std::string task_name_2 = it2->first;
                    LOG_DEBUG_S << "Name:  " << it2->first;
                    ConfigMap task_config_vals_2 = it2->second;
                    bool match = task_config.matches(task_name_2, task_config_vals_2);
                    BOOST_CHECK(!match);
                }
            }
        }
        LOG_DEBUG_S << "key:  " << it->first;
    }
}
