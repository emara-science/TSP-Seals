cmake_minimum_required(VERSION 3.20)
project(tsp_seals VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(tsp_core
    core/src/tsp_core.c
)
target_include_directories(tsp_core PUBLIC core/include)

add_executable(tsp-diagnostics tools/diagnostics/main.c)
target_link_libraries(tsp-diagnostics PRIVATE tsp_core)

enable_testing()
add_executable(tsp-core-tests tests/test_core.c)
target_link_libraries(tsp-core-tests PRIVATE tsp_core)
add_test(NAME tsp-core-tests COMMAND tsp-core-tests)
