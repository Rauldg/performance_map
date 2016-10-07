#include <boost/test/unit_test.hpp>
#include <performance_map/Dummy.hpp>

using namespace performance_map;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    performance_map::DummyClass dummy;
    dummy.welcome();
}
