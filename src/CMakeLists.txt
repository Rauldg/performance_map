rock_library(performance_map
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(performance_map_bin Main.cpp
    DEPS performance_map)

