#include <boost/test/unit_test.hpp>
#include <performance_map/Model.hpp>
#include <string>

using namespace performance_map;


BOOST_AUTO_TEST_CASE(get_max_performance)
{
    performance_map::Model model("./maps_tests");
    double max_performance = model.get_max_performance();
    BOOST_CHECK_CLOSE( 0.676147, max_performance, 0.03);
}

BOOST_AUTO_TEST_CASE(get_best_config)
{
    performance_map::Model model("./maps_tests");
    performance_map::ConfigSet best = model.get_best_config();
    BOOST_CHECK_EQUAL(best.get_id(), 141);
}

BOOST_AUTO_TEST_CASE(get_config_paths)
{
    performance_map::Model model("./maps_tests");
    model.get_config_paths(1);
}
