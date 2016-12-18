find_package(Boost COMPONENTS unit_test_framework system filesystem serialization thread)

rock_testsuite(test_suite suite.cpp
    test_Controller.cpp
    test_Model.cpp
    DEPS performance_map
    DEPS_PKGCONFIG
         lib_config
    DEPS_PLAIN
        Boost_THREAD
        Boost_UNIT_TEST_FRAMEWORK
        Boost_FILESYSTEM
    )

add_subdirectory(maps_tests)

file(COPY maps_tests DESTINATION ./)
