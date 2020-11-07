##############################################################
# SKELETON PROJECT
##############################################################
cmake_minimum_required( VERSION 3.5.2 )

project(
  CppSkeleton
  VERSION 0.1
  DESCRIPTION "An C++ skeleton project"
  LANGUAGES CXX)

# Include cmake files
include( "${CMAKE_SOURCE_DIR}/cmake/directories.cmake" )
include( "${CMAKE_SOURCE_DIR}/cmake/cpp_compiler_flags.cmake" )

#-------------------------------------------------------------
# Define modules
#-------------------------------------------------------------
add_subdirectory( ${SRC}/aux )
add_subdirectory( ${SRC}/skeleton )
