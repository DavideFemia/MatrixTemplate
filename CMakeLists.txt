cmake_minimum_required(VERSION 3.7)
project(LaboratoryProject)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(tests)

set(SOURCE_FILES main.cpp Matrix.h MatrixException.h math_exception.h index_exception.h)
add_executable(LaboratoryProject ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(LaboratoryProject core)