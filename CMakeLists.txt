cmake_minimum_required(VERSION 3.16)
project(calclib C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(
    calclib
    src/poly.c
    src/matrix.c
    src/calculus.c
    src/frac.c
    src/trig.c
)

target_include_directories(calclib PUBLIC include)
target_link_libraries(calclib PUBLIC m)

add_executable(calclib_demo src/sample_app.c)
target_link_libraries(calclib_demo calclib)

enable_testing()
add_subdirectory(tests)

