#include <boost/test/unit_test.hpp>
#include <performance_map/Controller.hpp>
#include <string>

using namespace performance_map;


BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    performance_map::Controller controller;
    const std::string path="./maps_tests";
    controller.set_path(path);


}
