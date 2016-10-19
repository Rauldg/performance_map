#include "Model.hpp"
#include <iostream>

#include <base-logging/Logging.hpp>
#include <configmaps/ConfigData.h>

using namespace std;
using namespace performance_map;
using namespace configmaps;



ConfigSet Model::get_best_config(){
    int id = get_best_config_id();
    ConfigSet result(id);
    return result;
}

int Model::get_best_config_id(){
    std::tuple<int, double> max_tuple = get_max_performance();
    return std::get<0>(max_tuple);
}

std::tuple <int, double> Model::get_max_performance(){
    double max_p = 0.0;
    int max_id = -1;
    configmaps::ConfigMap map;
    map = configmaps::ConfigMap::fromYamlFile(path + BPM_PATH);
    LOG_DEBUG_S << "Yaml file path " << path + BPM_PATH;
    LOG_DEBUG_S << "About to access key " << BPM;
    configmaps::ConfigVector::iterator it;
    for(it=map[BPM].begin(); it!=map[BPM].end(); ++it) {
        ConfigVector * bpm = it->getOrCreateVector();
        configmaps::ConfigVector::iterator itv;
        for(itv=bpm->begin(); itv!=bpm->end(); ++itv) {
            ConfigVector * tuples = itv->getOrCreateVector();
            int i = 0;
            configmaps::ConfigVector::iterator itt;
            for(itt=tuples->begin(); itt!=tuples->end(); ++itt) {
                ConfigMap individual;
                individual = tuples[i][0];
                i++;
                double performance = individual.get(PERFORMANCE, 0.0);
                if (performance > max_p){
                    max_p = performance;
                    max_id = individual.get(ID, -1);
                }
            }
        }
    }
    return std::make_tuple(max_id, max_p);
}

ConfigSet Model::get_configSet(int id){
    std::string filename = path + SAMPLES_PATH + ".yml";
    ConfigMap map = ConfigMap::fromYamlFile(filename);
    ConfigSet result(map);
    return result;
}

