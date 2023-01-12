add_subdirectory(feature)

# TODO: add image.cpp and read_data.cpp and fix the compile errors.
add_library(string_helpers STATIC 
            string_helpers.h
            string_helpers.cpp) 

add_library(read_data STATIC 
            read_data.h
            read_data.cpp) 

add_library(point2d STATIC 
            point2d.h
            point2d.cpp) 

add_library(point3d STATIC 
            point3d.h
            point3d.cpp) 

add_library(image STATIC 
            image.h
            image.cpp) 
target_include_directories(colmap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(colmap Eigen3::Eigen glog)

# TODO: add main.cpp into an executable.
add_executable(main main.cpp)
target_link_libraries(main)
#target_include_directories(colmap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
