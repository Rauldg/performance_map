#ifndef _PERFORMANCE_MAP_CONFIG_SET_HPP_
#define _PERFORMANCE_MAP_CONFIG_SET_HPP_

#include <vector>
#include <string>

namespace performance_map
{
    class ConfigSet
    {
        public:
            ConfigSet( int id ){this->id = id;};
            
            int get_id(){return id;};
            std::vector<std::string> get_paths(){return paths;}
            double getPerformance(){return performance;}

            int id;
            std::vector<std::string> paths;
            double performance;


    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_CONFIG_SET_HPP_
