#ifndef _PERFORMANCE_MAP_TASK_PARAM_HPP_
#define _PERFORMANCE_MAP_TASK_PARAM_HPP_

#include <vector>
#include <string>

namespace performance_map
{
    class TaskParam
    {
        public:
            TaskParam( std::string task, std::string param)
            {
                this->task = task;
                this->param = param;
            };

        private:
            std::string task;
            std::string param;

    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_TASK_PARAM_HPP_
