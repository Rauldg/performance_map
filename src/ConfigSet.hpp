#ifndef _PERFORMANCE_MAP_CONFIG_SET_HPP_
#define _PERFORMANCE_MAP_CONFIG_SET_HPP_

#include "TaskConfig.hpp"
#include <vector>

namespace performance_map
{
    class ConfigSet
    {
        public:
            ConfigSet( int id ){this->id = id;};
            
            int get_id(){return id;};

            int id;
            std::vector<std::string> paths;

            //TODO Remove the class TaskConfig

    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_CONFIG_SET_HPP_
