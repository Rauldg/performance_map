#include "TaskConfig.hpp"
#include <iostream>
#include "MapsDefines.hpp"

#include <base-logging/Logging.hpp>
#include <lib_config/YAMLConfiguration.hpp>
#include <graph_analysis/BaseGraph.hpp>
#include <system_modelling/io/OrogenModelReader.hpp>

using namespace performance_map;
using namespace configmaps;

TaskConfig::TaskConfig(const std::string & name, 
                    const configmaps::ConfigMap & config_vals)
{
    this->name = name;

}

std::string TaskConfig::get_param_type(const std::string & param_name){
    std::string result = "double";
    return result;
}

std::string get_type(const std::string &task, const std::string &param){
    graph_analysis::BaseGraph::Ptr graph = graph_analysis::BaseGraph::getInstance();
    system_modelling::io::OrogenModelReader reader;
    return "";
}

bool TaskConfig::matches(const std::string &name, configmaps::ConfigMap map){
    LOG_DEBUG_S << "MATCHES:  " << this->name << " and  " << name;
    bool ok = (this->name==name);
    //LOG_DEBUG_S << "OK:  " << ok ;
    //if (ok)
    //{
    //    // Go through the map, for each key find the correspondent param_value
    //    // in the TaskConfig and make sure they are the same
    //    ConfigMap::FIFOMap::iterator it;
    //    it = map.begin();
    //    // Loop over the parameter-value pairs
    //    while(ok and it!=map.end()){
    //        std::string param_name = it->first;
    //        std::string type = get_type(name, param_name);
    //        ok = check_exists_equal(param_name, type, it->second);
    //    }
    //}
    return ok;
}
        //ConfigMap::FIFOMap::iterator it;

        //it = map.begin();
        //// Loop over the parameter-value pairs
        //while(ok and it!=map.end()){
        //    std::string param_name = it->first;
        //    // get type
        //    // instantiate correspondent param_value
        //    // see if param_value exists in taskconfig

        //    std::string type = get_param_type(param_name);
        //    bool found = false;
        //    if (type == "double"){
        //        ParamValue<double> param_value;
        //        //found = find_param(param_name, param_value);
        //        //ok = (paramValue.value == (double)map[param_name]);
        //        ok = found;
        //    }
        //    else if (type == "int" ){
        //        ParamValue<int> param_value;
        //        //found = find_param(param_name, param_value);
        //        //ok = (paramValue.value == (int)map[param_name]);
        //        ok = found;
        //    }
        //    else if (type == "bool"){
        //        ParamValue<bool> param_value;
        //        //found = find_param(param_name, param_value);
        //        //ok = (paramValue.value == (bool)map[param_name]);
        //        ok = found;
        //    }
        //    else if (type == "std::string"){
        //        ParamValue<std::string> param_value;
        //        //found = find_param(param_name, param_value);
        //        //ok = (paramValue.value == (std::string)map[param_name]);
        //        ok = found;
        //    }

        //    //ParamValue paramValue;
        //    //found = find_param(param_name, paramValue);
        //    //type = ParamTypes.get_type(param_name);

        //    //std::string path = libConfig::YAMLConfigParser::applyStringVariableInsertions("<%=ENV(AUTOPROJ_CURRENT_ROOT) %>/<%=ENV(SPACECLIMBER)%>"); 

        //    //if (type == "double")
        //    //    ok = (paramValue.value == (double)map[param_name]);
        //    //else if (type == "int" )
        //    //    ok = (paramValue.value == (int)map[param_name]);
        //    //else if (type == "bool")
        //    //    ok = (paramValue.value == (bool)map[param_name]);
        //    //else if (type == "std::string")
        //    //    ok = (paramValue.value == (std::string)map[param_name]);

        //    //if ((it->first)!= ID)
        //    //{
        //    //    std::string task_name = it->first;
        //    //    ConfigMap task_config_vals = it->second;
        //    //    check_contains(config_set, task_name, task_config_vals);
        //    //    //TaskConfig task_config(task_name, task_config_vals);
        //    //}
        //    LOG_DEBUG_S << "key:  " << it->first;
        //}

