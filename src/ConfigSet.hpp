#ifndef _PERFORMANCE_MAP_CONFIG_SET_HPP_
#define _PERFORMANCE_MAP_CONFIG_SET_HPP_

#include <vector>
#include <string>
#include "TaskParam.hpp"

namespace performance_map
{
    class ConfigSet
    {
        public:
            ConfigSet( int id ){this->id = id;};
            
            int get_id(){return id;};
            std::vector<std::string> get_paths(){return paths;}
            void setTasksParams(std::vector<TaskParam> tasksParams)
            {
                this->mTasksParams = tasksParams;
            }
            std::vector<TaskParam> getTasksParams(){return mTasksParams;}
            double getPerformance(){return performance;}

            int id;
            std::vector<std::string> paths;
            std::vector<TaskParam> mTasksParams;
            double performance;


    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_CONFIG_SET_HPP_
