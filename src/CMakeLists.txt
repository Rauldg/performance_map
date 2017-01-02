rock_library(performance_map
    SOURCES Controller.cpp
            Model.cpp
    HEADERS Controller.hpp
            Model.hpp
            ConfigSet.hpp
            TaskParam.hpp
    DEPS_PKGCONFIG
            base-lib
            system_modelling
            graph_analysis
            )


rock_executable(performance_map_bin Main.cpp
    DEPS performance_map)

