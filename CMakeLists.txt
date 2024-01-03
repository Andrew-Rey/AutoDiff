cmake_minimum_required(VERSION 3.23)
project(autodiff)

add_library(caltool base_type/__init__.cpp)

add_executable(autodiff)
target_sources(autodiff PUBLIC autodiff.cpp)