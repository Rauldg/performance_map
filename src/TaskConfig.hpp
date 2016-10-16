#ifndef _PERFORMANCE_MAP_TASK_CONFIG_HPP_
#define _PERFORMANCE_MAP_TASK_CONFIG_HPP_

#include <string>
#include <vector>

namespace performance_map
{
    template<typename type>
    struct param_value
    {
        std::string param_name;
        type value;
    };

    class TaskConfig
    {
        public:

        std::string task_name;

        std::vector < param_value < int > > ints;
        std::vector < param_value < double > > doubles;
        std::vector < param_value < bool > >  bools;
        std::vector < param_value < std::string > >  strings;

    };

} // end namespace performance_map

#endif // _PERFORMANCE_MAP_TASK_CONFIG_HPP_
