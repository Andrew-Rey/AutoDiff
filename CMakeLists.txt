cmake_minimum_required(VERSION 3.23)
project(autodiff)
set(CMAKE_CXX_STANDARD 17)

add_library(caltool base_type/__init__.cpp)

add_executable(autodiff)
target_sources(autodiff PUBLIC metatest.cpp)