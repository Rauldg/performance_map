#ifndef _PERFORMANCE_MAP_CONTROLLER_HPP_
#define _PERFORMANCE_MAP_CONTROLLER_HPP_

#include "ConfigSet.hpp"
#include "Model.hpp"
#include <graph_analysis/BaseGraph.hpp>

namespace performance_map
{
    class Controller
    {
        public:


            void set_path(const std::string & path) { this->path = path;};
            ConfigSet get_best_config();
            void load_best_config_set(const graph_analysis::BaseGraph::Ptr graph);

        private:
            std::string path;
            Model mLibrary;
    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_CONTROLLER_HPP_
