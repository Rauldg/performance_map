#ifndef _PERFORMANCE_MAP_MODEL_HPP_
#define _PERFORMANCE_MAP_MODEL_HPP_

#include <tuple>
#include "ConfigSet.hpp"
#include "MapsDefines.hpp"



namespace performance_map
{
    class Model
    {
        public:
            std::string path;

            void set_path(const std::string & path) { this->path = path;};
            ConfigSet get_best_config();
            /*
             * NOTE This method accesses the persistent data
             */
            std::tuple<int, double> get_max_performance();
            ConfigSet get_configSet(int id);
        private:
            int get_max_performance_id();
    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_MODEL_HPP_
