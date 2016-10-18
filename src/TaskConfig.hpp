#ifndef _PERFORMANCE_MAP_TASK_CONFIG_HPP_
#define _PERFORMANCE_MAP_TASK_CONFIG_HPP_

#include <string>
#include <vector>

#include <configmaps/ConfigData.h>

namespace performance_map
{
    template<typename type>
    struct ParamValue
    {
        std::string param_name;
        type value;
    };

    class TaskConfig
    {
        public:

            TaskConfig(){};
            TaskConfig(const std::string & name, 
                    const configmaps::ConfigMap & config_vals);

            std::string get_name(){ return this->name;};
            std::string get_param_type(const std::string &param_name);
            bool matches(const std::string &name, configmaps::ConfigMap map);

            std::string name;
            std::vector < ParamValue < int > > ints;
            std::vector < ParamValue < double > > doubles;
            std::vector < ParamValue < bool > >  bools;
            std::vector < ParamValue < std::string > >  strings;

    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_TASK_CONFIG_HPP_
