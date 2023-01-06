cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Werror=return-type")

#set(CMAKE_CXX_FLAGS "-O3")
project(sift_cpp)

find_package(Eigen3 REQUIRED)
find_package(Ceres REQUIRED)
find_package(gflags REQUIRED)

add_subdirectory(src)
