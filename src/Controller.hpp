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

            Controller(const std::string & path=MAPS_DEFAULT_FOLDER):mLibrary(path){};
            ConfigSet getBestConfig();
            void init(const std::string & path);
            int load_best_config_set(graph_analysis::BaseGraph::Ptr graph);

        private:
            Model mLibrary;
    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_CONTROLLER_HPP_
