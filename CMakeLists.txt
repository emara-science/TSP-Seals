cmake_minimum_required(VERSION 3.20)
project(tsp_seals VERSION 0.2.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(TSP_CORE_SOURCES
    core/src/tsp_core.c
)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    list(APPEND TSP_CORE_SOURCES core/src/tsp_device_linux.c)
else()
    list(APPEND TSP_CORE_SOURCES core/src/tsp_device_unsupported.c)
endif()

add_library(tsp_core ${TSP_CORE_SOURCES})
target_include_directories(tsp_core PUBLIC core/include)

add_executable(tsp-diagnostics tools/diagnostics/main.c)
target_link_libraries(tsp-diagnostics PRIVATE tsp_core)

enable_testing()
add_executable(tsp-core-tests tests/test_core.c)
target_link_libraries(tsp-core-tests PRIVATE tsp_core)
add_test(NAME tsp-core-tests COMMAND tsp-core-tests)
