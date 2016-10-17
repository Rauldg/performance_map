rock_library(performance_map
    SOURCES Controller.cpp
            Model.cpp
            ConfigSet.cpp
    HEADERS Controller.hpp
            Model.hpp
            ConfigSet.hpp
            TaskConfig.hpp
            MapsDefines.hpp
    DEPS_PKGCONFIG
            configmaps
            base-lib)


rock_executable(performance_map_bin Main.cpp
    DEPS performance_map)

