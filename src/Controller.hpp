#ifndef _PERFORMANCE_MAP_CONTROLLER_HPP_
#define _PERFORMANCE_MAP_CONTROLLER_HPP_

#include "ConfigSet.hpp"
#include "Model.hpp"

namespace performance_map
{
    class Controller
    {
        public:
            std::string path;
            Model library;

            void set_path(const std::string & path) { this->path = path;};
            ConfigSet get_best_config();
    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_CONTROLLER_HPP_
