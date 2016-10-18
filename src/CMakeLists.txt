rock_library(performance_map
    SOURCES Controller.cpp
            Model.cpp
            ConfigSet.cpp
            TaskConfig.cpp
    HEADERS Controller.hpp
            Model.hpp
            ConfigSet.hpp
            TaskConfig.hpp
            MapsDefines.hpp
            ParamValue.hpp
    DEPS_PKGCONFIG
            configmaps
            graph_analysis
            base-lib
            lib_config
            )

rock_executable(performance_map_bin Main.cpp
    DEPS performance_map)

