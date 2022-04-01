cmake_minimum_required(VERSION 3.16)
project(fake_mocap_publisher VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

find_package(yaml-cpp CONFIG REQUIRED)

add_subdirectory(apps)
add_subdirectory(lib)