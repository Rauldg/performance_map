#ifndef _PERFORMANCE_MAP_MODEL_HPP_
#define _PERFORMANCE_MAP_MODEL_HPP_

#include "ConfigSet.hpp"
#include "Model.hpp"

namespace performance_map
{
    class Model
    {
        public:
            std::string path;

            void set_path(const std::string & path) { this->path = path;};
            ConfigSet get_best_config();
            double get_max_performance();
    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_MODEL_HPP_
