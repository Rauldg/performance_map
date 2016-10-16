#include <boost/test/unit_test.hpp>
#include <performance_map/Model.hpp>
#include <string>

using namespace performance_map;


BOOST_AUTO_TEST_CASE(get_max_performance)
{
    performance_map::Model model;
    const std::string path="./maps_tests";
    model.set_path(path);
    model.get_max_performance();
}


