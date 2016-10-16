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

            int id;
            std::vector<TaskConfig> set;

    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_CONFIG_SET_HPP_
