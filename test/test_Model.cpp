#include <boost/test/unit_test.hpp>
#include <performance_map/Model.hpp>
#include <string>

using namespace performance_map;


BOOST_AUTO_TEST_CASE(get_max_performance)
{
    performance_map::Model model;
    const std::string path="./maps_tests";
    model.set_path(path);
    std::tuple<int, double> max_performance = model.get_max_performance();
    BOOST_CHECK(std::get<0>(max_performance) == 141);
    BOOST_CHECK(std::get<1>(max_performance) == 0.6761466571268595);
}


BOOST_AUTO_TEST_CASE(get_best_config)
{
    performance_map::Model model;
    const std::string path="./maps_tests";
    model.set_path(path);
    ConfigSet best_config = model.get_best_config();
    BOOST_CHECK(best_config.get_id() == 141);

}
