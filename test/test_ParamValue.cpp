#include <boost/test/unit_test.hpp>
#include <performance_map/ParamValue.hpp>
#include <base-logging/Logging.hpp>


using namespace performance_map;

BOOST_AUTO_TEST_CASE(constructors_ParamValue)
{
    // Boolean ParamValue
    ParamValue<bool> param_value_bool("testBool", true);
    ParamValue<std::string> param_value_string("testString", "String");
    ParamValue<int> param_value_int("testInt", 1);
    ParamValue<double> param_value_test("test", 2.3);
}

BOOST_AUTO_TEST_CASE(compare_paramValues)
{
    // Boolean ParamValue
    ParamValue<bool> param_value_bool("testBool", true);
    ParamValue<bool> param_value_bool_equal("testBool", true);
    BOOST_CHECK(param_value_bool.is_equal(param_value_bool_equal));
    ParamValue<bool> param_value_bool_other_name("testBoolean", true);
    BOOST_CHECK(!param_value_bool.is_equal(param_value_bool_other_name));
    ParamValue<bool> param_value_bool_other_value("testBool", false);
    BOOST_CHECK(!param_value_bool.is_equal(param_value_bool_other_value));
}
