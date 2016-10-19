#include <boost/test/unit_test.hpp>
#include <performance_map/Controller.hpp>
#include <string>
#include <base-logging/Logging.hpp>

using namespace performance_map;


BOOST_AUTO_TEST_CASE(Instantiate_and_give_path)
{
    performance_map::Controller controller;
    const std::string path="./maps_tests";
    controller.set_path(path);
}

BOOST_AUTO_TEST_CASE(Get_best_id)
{
    performance_map::Controller controller;
    const std::string path="./maps_tests";
    controller.set_path(path);
    int best_id = controller.get_best_config_id();
    LOG_DEBUG_S << "Best id: " << best_id;
    BOOST_CHECK(best_id==141);

}
