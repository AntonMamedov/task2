cmake_minimum_required(VERSION 3.17)
project(tf_idf_metric C)

set(CMAKE_C_STANDARD 11)
include_directories(inc)
add_executable(tf_idf_metric src/main.c inc/str_map.h src/str_map.c inc/tf_idf_metric.h inc/word_tf_wector.h src/word_tf_wector.c inc/str.h src/str.c)