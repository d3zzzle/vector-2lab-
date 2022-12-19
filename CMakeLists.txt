cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Matrix)
project(${PROJECT_NAME})


set(LIBRARY "${PROJECT_NAME}")
set(TESTS  "test_${PROJECT_NAME}")

set(vector VectorMain)
set(vectorlib VectorLib)
set(matrixlib MatrixLib)
set(matrix MatrixMain)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)



add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(Matrix)
add_subdirectory(MatrixLib)
add_subdirectory(gtest)
add_subdirectory(test)

