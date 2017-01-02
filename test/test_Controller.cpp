#include <boost/test/unit_test.hpp>
#include <performance_map/Controller.hpp>
#include <graph_analysis/BaseGraph.hpp>
#include <lib_config/YAMLConfiguration.hpp>
#include <system_modelling/utils/utils.hpp>
#include <system_modelling/io/CndModelReader.hpp>
#include <system_modelling/io/CndModelWriter.hpp>
#include <string>

using namespace performance_map;


BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    performance_map::Controller controller;
    const std::string path="./maps_tests";
    controller.set_path(path);
}


BOOST_AUTO_TEST_CASE(test_load_best_config)
{
    performance_map::Controller controller;
    const std::string path="./maps_tests";
    controller.set_path(path);

    // Prepare search paths for the task models
    std::vector<std::string> search_paths;
    std::string tasks_models_path = libConfig::YAMLConfigParser::applyStringVariableInsertions("<%=ENV(AUTOPROJ_CURRENT_ROOT) %>/install/share/orogen"); 
    search_paths.push_back(tasks_models_path);
    graph_analysis::BaseGraph::Ptr graph(graph_analysis::BaseGraph::getInstance());
    system_modelling::utils::load_orogen_templates(search_paths, graph);
    system_modelling::io::CndModelReader reader;
    std::string CNDFilePath = "./cnd_models/motion_planning.yml";
    // TODO A segmentation fault occurs when loading this cnd, also in the test of the cnd Reader. Maybe rebuilding all is enough?
    std::cout << "FOO 1" << std::endl;
    reader.read(CNDFilePath, graph);
    std::cout << "FOO 2" << std::endl;

    
    controller.load_best_config_set(graph);

}


