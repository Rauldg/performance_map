rock_library(performance_map
    SOURCES Controller.cpp
            Model.cpp
    HEADERS Controller.hpp
            Model.hpp
            ConfigSet.hpp
            TaskConfig.hpp
    DEPS_PKGCONFIG
            configmaps
            yaml-cpp
            base-lib)


rock_executable(performance_map_bin Main.cpp
    DEPS performance_map)

