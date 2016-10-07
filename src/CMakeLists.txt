rock_library(performance_map
    SOURCES Controller.cpp
    HEADERS Controller.hpp)

rock_executable(performance_map_bin Main.cpp
    DEPS performance_map)

