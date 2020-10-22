cmake_minimum_required(VERSION 3.17)
project(tf_idf_metric_nonthread C)

set(CMAKE_C_STANDARD 11)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread"
include_directories(inc)
add_executable(tf_idf_metric_nonthread src/main.c inc/str.h src/str.c inc/str_mab.h src/str_map.c inc/file_metric.h src/file_metric.c inc/vec.h src/vec.c inc/user_info_macro.h)
target_link_libraries(tf_idf_metric_nonthread m)