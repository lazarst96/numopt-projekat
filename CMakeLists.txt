cmake_minimum_required(VERSION 3.14)
project(NumericalOptimization)

set(CMAKE_CXX_STANDARD 17)

set(GLOB FUNCTIONS functions/*.h function.h)
set(GLOB LINE_SEARCHES line_searches/*.h line_searches.h)
set(GLOB METHODS methods/*/*.h methods.h)

add_executable(NumericalOptimization main.cpp methods/quasi_newton/l_bfgs.h)
add_library(numopt_clib SHARED library.h library.cpp ${FUNCTIONS} ${LINE_SEARCHES} ${METHODS})