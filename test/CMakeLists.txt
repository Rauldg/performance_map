rock_testsuite(test_suite suite.cpp
   test_Controller.cpp
   test_Model.cpp
   test_ConfigSet.cpp
   test_ParamValue.cpp
   test_TaskConfig.cpp
   DEPS performance_map)

add_subdirectory(maps_tests)

file(COPY maps_tests DESTINATION ./)
