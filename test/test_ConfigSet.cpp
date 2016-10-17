#include <boost/test/unit_test.hpp>
#include <performance_map/ConfigSet.hpp>
#include <performance_map/MapsDefines.hpp>
#include <string>
#include <configmaps/ConfigData.h>


using namespace performance_map;

BOOST_AUTO_TEST_CASE(constructors)
{
    configmaps::ConfigMap map;
    map[ID] = 1;
    ConfigSet config(map);
    BOOST_CHECK(config.get_id() == 1);

}
