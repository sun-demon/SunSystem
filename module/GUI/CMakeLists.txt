get_filename_component(MODULE_NAME "${CMAKE_CURRENT_LIST_DIR}" NAME)

find_package(SFML COMPONENTS graphics REQUIRED)

include_directories(include)
set(EXECUTABLE_NAME "${PROJECT_NAME}_${MODULE_NAME}")
add_executable("${EXECUTABLE_NAME}" src/main.cpp

    include/CenteredCircleShape/CenteredCircleShape.h
        src/CenteredCircleShape/CenteredCircleShape.cpp

    include/Planet/Planet.h
        src/Planet/Planet.cpp

    include/Planet/PlanetSystem/PlanetSystem.h
        src/Planet/PlanetSystem/PlanetSystem.cpp
)

target_link_libraries("${EXECUTABLE_NAME}" sfml-graphics)
