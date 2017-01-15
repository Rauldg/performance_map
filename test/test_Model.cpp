#include <boost/test/unit_test.hpp>
#include <performance_map/Model.hpp>
#include <performance_map/TaskParam.hpp>
#include <string>

using namespace performance_map;

BOOST_AUTO_TEST_CASE(get_max_performance)
{
    performance_map::Model model("./maps_tests");
    double max_performance = model.get_max_performance();
    BOOST_CHECK_CLOSE( 0.676147, max_performance, 0.03);
}

BOOST_AUTO_TEST_CASE(get_config_paths)
{
    performance_map::Model model("./maps_tests");
    model.getConfigPaths(1);
}

BOOST_AUTO_TEST_CASE(get_best_config)
{
    performance_map::Model model("./maps_tests");
    performance_map::ConfigSet best = model.get_best_config();
    BOOST_CHECK_EQUAL(best.get_id(), 141);
    BOOST_CHECK_EQUAL(best.paths.size(), 3);
}


BOOST_AUTO_TEST_CASE(store_new_configSet)
{
    performance_map::Model model("./maps_tests");
    //model.setNumConfigSets(176);
    performance_map::ConfigSet configSet(model.getNumConfigSets());
    BOOST_CHECK_EQUAL(176, model.getNumConfigSets());
    // The following method does not make much sense, because we don't want to generate the configSets from somewhere else
    // 
    std::vector<TaskParam> taskParams; 
    TaskParam taskParam("Example::task","exampleParameterName" );
    taskParams.push_back(taskParam);
    TaskParam taskParam2("Example::task2", "example2ParameterName");
    taskParams.push_back(taskParam2);
    configSet.setTasksParams(taskParams);
    model.storeConfigSet(configSet);
    BOOST_CHECK_EQUAL(177, model.getNumConfigSets());
    // To generate the config values we would rather use the task infomation
    //
    //BOOST_CHECK_EQUAL();
    //BOOST_CHECK_EQUAL();
}

