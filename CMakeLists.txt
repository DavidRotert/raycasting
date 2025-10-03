cmake_minimum_required(VERSION 3.28)
project(raycasting)

set(CMAKE_CXX_STANDARD 23)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "5.5"
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

set(SHARED_SOURCES
        src/utils.cpp
        src/Game.cpp
        src/Player.cpp
        src/Map.cpp
        src/RenderingSystem.cpp
        src/raycasting.cpp
)

# Add executable
add_executable(${PROJECT_NAME})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
target_include_directories(${PROJECT_NAME} PRIVATE
        src
        test
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_sources(${PROJECT_NAME} PRIVATE
        src/main.cpp

        ${SHARED_SOURCES}
)

# Add tests
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.11.0
)
FetchContent_MakeAvailable(Catch2)
add_executable(${PROJECT_NAME}-tests)
target_include_directories(${PROJECT_NAME}-tests PRIVATE
        src
        test
)
target_link_libraries(${PROJECT_NAME}-tests PRIVATE
        Catch2::Catch2WithMain
        raylib
)
target_sources(${PROJECT_NAME}-tests PRIVATE
        test/raycasting.cpp

        ${SHARED_SOURCES}
)
