add_subdirectory(feature)

# TODO: add image.cpp and read_data.cpp and fix the compile errors.
add_library(colmap STATIC string_helpers.cpp point3d.cpp point2d.cpp)
target_include_directories(colmap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(colmap Eigen3::Eigen glog)

# TODO: add main.cpp into an executable.
#add_executable(main_bin main.cpp)
#target_link_libraries(main_bin colmap)
#target_include_directories(colmap PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
