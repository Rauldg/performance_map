#ifndef _PERFORMANCE_MAP_MODEL_HPP_
#define _PERFORMANCE_MAP_MODEL_HPP_

#include "ConfigSet.hpp"
#include <yaml-cpp/yaml.h>

#define PERFORMANCE_LABEL std::string("performance")
#define ID_LABEL std::string("id")
#define OVERPASSED_LABEL std::string("overpassed")
#define TASK_TYPE_LABEL std::string("Task")
#define TASK_NAME_LABEL std::string("Task_name")
#define SECTION_LABEL std::string("Sections")
#define IDS_PERFORMANCES_FILE std::string("/bpms/ids_performance_vector.yml")
#define MAPS_DEFAULT_FOLDER std::string("./maps")

#define SAMPLES_PATH std::string("/all_samples")

namespace performance_map
{
    class Model
    {
        private:
            YAML::Node get_max_performance_and_id();
            // TODO This whole method should disappear by using correct config
            // yml files and not compositions. Also task_name and task should
            // be contained
            void reshape_config_file(int id);

        public:
            std::string path;

            Model(const std::string & path=MAPS_DEFAULT_FOLDER){ this->path = path;};
            void set_path(const std::string & path) { this->path = path;};
            std::string get_path(){return this->path;};
            ConfigSet get_best_config();
            double get_max_performance();
            std::vector<std::string> get_config_paths(int id);


    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_MODEL_HPP_
